#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <math.h>
#include <stdlib.h>       //
#include <string.h>       //
#include <unistd.h>       //
#include <sys/types.h>    //
#include <sys/socket.h>   //   네트워크용 헤더 파일 추가 
#include <netinet/in.h>   //
#include <netdb.h>        //

#define BUFSIZE 1024      //
 
#define		PCF     120
#define		DOpin	0
#define		LedPin 	2

void Print(int x)
{
	switch(x)
	{
		case 0:
			printf("\n************\n"  );
			printf(  "* Too Hot! *\n"  );
			printf(  "************\n\n");
		break;
		case 1:
			printf("\n***********\n"  );
			printf(  "* Better~ *\n"  );
			printf(  "***********\n\n");
		break;
		default:
			printf("\n**********************\n"  );
			printf(  "* Print value error. *\n"  );
			printf(  "**********************\n\n");
		break;
	}
}
/*
 *error - wrapper for perror 
 */
void error(char *msg) {      // 에러메시지 표시용 코드
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
	unsigned char analogVal;
	double Vr, Rt, temp;
	int tmp, status;
	int sockfd, portno, n;           //
	struct sockaddr_in serveraddr;   //
	struct hostent *server;          //  네트워크용 변수 
	char *hostname;                  //
	char buf [BUFSIZE];              //

	if (argc != 3) {     // 커멘드 입력시 IP와 포트 입력을 위한 코드
		fprintf(stderr, "usage: %s <hostname> <port>/n", argv[0]);
		exit(0);
	}
	hostname = argv[1];
	portno = atoi(argv[2]);

	/* socket: create the socket */  
	sockfd = socket(AF_INET, SOCK_STREAM, 0);   // 
	if (sockfd < 0)                             //
		error("ERROR opening socker");      //
	/* gethostbyname: get the server's DNS entry */  //
	server = gethostbyname(hostname);                // 소켓을 생성하고 서버의 DNS 주소를 얻는 루틴
	if (server == NULL) {                            //
		fprintf(stderr, "ERROR, no such host as %s\n", hostname); //
		exit(0);                                                  //
	}	                                                          //

	/* build the server's Internet address */   //서버의 인터넷 주소 생성하고 서버에 접속  
	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, 
	server->h_length);
	serveraddr.sin_port = htons(portno);
	/* connect: create a connection with the server */
	if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr) ) < 0)
		printf("ERROR connecting");
        

	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1;
	}
	// Setup pcf8591 on base pin 120, and address 0x48
	pcf8591Setup(PCF, 0x48);

	pinMode(DOpin, INPUT);
	pinMode(LedPin, OUTPUT);            //

	status = 0;                         //
	while(1) // loop forever            // 상태체크를 위해 LED 포트 초기화 
	{
		digitalWrite(LedPin, LOW);  //

		printf("loop");
		analogVal = analogRead(PCF + 0);
		Vr = 5 * (double)(analogVal) / 255;
		Rt = 10000 * (double)(Vr) / (5 - (double)(Vr));
		temp = 1 / (((log(Rt/10000)) / 3950)+(1 / (273.15 + 25)));
		temp = temp - 273.15;
		printf("Current temperature : %lf\n", temp);

		sprintf(buf, "Current temperature : %lf\n", temp);  //
		n = write(sockfd, buf, strlen(buf));                // 전송 메시지  
		if (n < 0)                                          // 생성 및 전송 
			error("ERROR writing to socket");           //

		// For a threshold, uncomment one of the code for
		// which module you use. DONOT UNCOMMENT BOTH!
		//---------------------------------------------
		// 1. For Analog Temperature module(with DO)
		tmp = digitalRead(DOpin);
		printf("Digital Value : %d\n", tmp);
                // 2. For Thermister module(with sig pin)
                // if (temp > 33) tmp = 0;
                // else if (temp < 31) tmp = 1;
		//---------------------------------------------

		if (tmp != status)
		{
			Print(tmp);
			status = tmp;
		}
		delay (500);

		digitalWrite(LedPin, HIGH);      // LED 상태 반전 
		delay (500);
	}
	return 0;
}
//[출처] [라즈베리파이] 클라이언트로 구성하여 온도센서 데이터를 소켓 서버로 전송하기(C언어)|작성자 우리밋 woorimIT