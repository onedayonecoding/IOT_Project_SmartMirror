/*
    communication between RPi to RPi through network
        server program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAXLINE    511     // 데이터 크기
#define PORT    5000       // 임의로 설정한 통신포트

int main(int argc, char* argv[]){
    int serv_sock;
    int conn_sock;

    struct sockaddr_in    serv_addr;  //
    struct sockaddr_in    conn_addr;  // 소켓 구조체 생성 

    int addrlen, datalen;

    char buf[MAXLINE +1];  // 메시지 버퍼 생성 
    int nbytes;
    int nport;

    pid_t pid;

    if (argc == 1){                                 // 서버 포트 확인 
        nport = PORT;    //default port : 65021
    } else if (argc == 2) {
        nport = atoi(argv[1]);
    } else {
        printf("Usage: %s <port>\n", argv[0]);      // 서버 포트가 정상적으로 입력되지 않으면 용례 표시 
        exit(0);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serv_sock == -1){      // 소켓이 생성되지 않으면 에러 표시 
        perror("socket() error!\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;            //default
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);     //my addr  TCP IP, Port 설정 
    serv_addr.sin_port = htons(nport);        //my port to serv

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) { // 서버 IP와 Por 연결
        perror("bind() error\n");
        exit(0);
    }

    if(listen(serv_sock, 1) == -1) {  // 클라이언트 접속 대기 
        perror("listen() error\n");
        exit(0);
    }

    addrlen = sizeof(conn_sock);    // connection socket
    conn_sock = accept(serv_sock, (struct sockaddr *)&conn_addr, &addrlen); //wait for call 클라이언트 접속 허용
    if(conn_sock == -1){
        perror("accept() error\n");
        exit(0);
    }

    if((pid = fork()) == -1){  // 잘못된 소켓인 경우 접속 종료 
        close(conn_sock);
        perror("fork() error\n");
    } else if(pid ==0) {    //child process
        while(1){
            fgets(buf, sizeof(buf), stdin);    // 사용자의 입력을 받아서
            nbytes = strlen(buf);
            write(conn_sock, buf, MAXLINE);    //입력된 문자를 소켓을 통해 전송
            if(strncmp(buf, "exit", 4) ==0) {        //입력 문자가 "exit" 로 시작하면 -> exit 콜 =>종료
                puts("exit program");    //output message
                exit(0);        //exit when "exit"
            }
        }
    } else if (pid > 0){    //parent process
        while(1){
            if((nbytes = read(conn_sock, buf, MAXLINE)) < 0){    // 클라이언트에서 온 문자를 읽어
                perror("read() error\n");
                exit(0);
            }
            printf("%s\n", buf);    // 표준 출력으로 출력
            if(strncmp(buf, "exit",4) == 0)
                exit(0);
        }
    }

    close(conn_sock);
    close(serv_sock);
    return 0;
} 
//[출처] [라즈베리파이] 클라이언트로 구성하여 온도센서 데이터를 소켓 서버로 전송하기(C언어)|작성자 우리밋 woorimIT

