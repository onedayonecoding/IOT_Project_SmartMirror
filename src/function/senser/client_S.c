/**    chat_client **/
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<pthread.h>
#include<time.h>
 
#define BUF_SIZE 100
#define NORMAL_SIZE 20
 
void* send_msg(void* arg);
void* recv_msg(void* arg);
void error_handling(char* msg);
 
void menu();
void changeName();
void menuOptions(); 
 
char name[NORMAL_SIZE]="[DEFALT]";      // name
char msg_form[NORMAL_SIZE];             // msg form
char serv_time[NORMAL_SIZE];            // server time
char msg[BUF_SIZE];                     // msg
char air[BUF_SIZE];                     // air
char air_temp[BUF_SIZE];                // air
char motor[BUF_SIZE];                   // motor
char motor_temp[BUF_SIZE];              // motor
char serv_port[NORMAL_SIZE];            // server port number
char clnt_ip[NORMAL_SIZE];              // client ip address
FILE* stream; //파일 포인터를 선언한다.
FILE* stream1; //파일 포인터를 선언한다.
FILE* stream2; //파일 포인터를 선언한다.
FILE* stream3; //파일 포인터를 선언한다.
 
int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    pthread_t snd_thread, rcv_thread;
    void* thread_return;
 
    if (argc!=4)
    {
        printf(" Usage : %s <ip> <port> <name>\n", argv[0]);
        exit(1);
    }
 
    /** local time **/
    struct tm *t;
    time_t timer = time(NULL);
    t=localtime(&timer);
    sprintf(serv_time, "%d-%d-%d %d:%d", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour,
    t->tm_min);
 
    sprintf(name, "[%s]", argv[3]);
    sprintf(clnt_ip, "%s", argv[1]);
    sprintf(serv_port, "%s", argv[2]);
    sock=socket(PF_INET, SOCK_STREAM, 0);
 
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_addr.sin_port=htons(atoi(argv[2]));
 
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
        error_handling(" conncet() error");
 
    /** call menu **/
    menu();

    /*모터 에어컨 초기화 */
    stream = fopen("Motor.txt", "w"); //파일 포인터를 선언한다. //Temperature.txt를 쓰기용으로 연다.
    fputs("off", stream); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
    fclose(stream); //파일을 닫는다.
    stream = fopen("Air.txt", "w"); //파일 포인터를 선언한다. //Temperature.txt를 쓰기용으로 연다.
    fputs("off", stream); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
    fclose(stream); //파일을 닫는다.
    strcpy(motor_temp, "off");
    strcpy(air_temp, "off");
 
    pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
    pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
    pthread_join(snd_thread, &thread_return);
    pthread_join(rcv_thread, &thread_return);
    close(sock);
    return 0;
}
 
void* send_msg(void* arg)
{
    int sock=*((int*)arg);
    char name_msg[NORMAL_SIZE+BUF_SIZE];
    char myInfo[BUF_SIZE];
    char* who = NULL;
    char temp[BUF_SIZE];
 
    /** send join messge **/
    printf(" >> join the chat !! \n");
    sprintf(myInfo, "%s's join. IP_%s\n",name , clnt_ip);
    write(sock, myInfo, strlen(myInfo));
 
    while(1)
    {
        // fgets(msg, BUF_SIZE, stdin);
        stream = fopen("Motor.txt", "r"); //파일 포인터를 선언한다. //Temperature.txt를 쓰기용으로 연다.
        fgets(motor, BUF_SIZE, stream); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
        fclose(stream); //파일을 닫는다.
        stream = fopen("Air.txt", "r"); //파일 포인터를 선언한다. //Temperature.txt를 쓰기용으로 연다.
        fgets(air, BUF_SIZE, stream); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
        fclose(stream); //파일을 닫는다.
 
        // menu_mode command -> !menu
        if (!strcmp(msg, "!menu\n"))
        {
            menuOptions();
            continue;
        }
 
        else if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
        {
            close(sock);
            exit(0);
        }

        if (!strcmp(msg, "!motor\n"))
        {
            printf("%s\n", motor);
            continue;
        }
        if (!strcmp(msg, "!motor_temp\n"))
        {
            printf("%s\n", motor_temp);
            continue;
        }
        // // send message
        // sprintf(name_msg, "%s %s", name,msg);
        // write(sock, name_msg, strlen(name_msg));
        /* 모터 에어컨 신호 보내기 */
        if(strncmp(motor, "on",2) == 0 && strncmp(motor_temp, "on",2) != 0){
            strcpy(motor_temp, "on");
            send(sock, "motor = on\n", BUF_SIZE, MSG_DONTWAIT);
            printf("motor = on\n");
        }else if(strncmp(motor, "off",3) == 0 && strncmp(motor_temp, "off",3) != 0){
            strcpy(motor_temp, "off");
            send(sock, "motor = off\n", BUF_SIZE, MSG_DONTWAIT);
            printf("motor = off\n");
        }
        if(strncmp(air, "on",2) == 0 && strncmp(air_temp, "on",2) != 0){
            strcpy(air_temp, "on");
            send(sock, "air = on\n", BUF_SIZE, MSG_DONTWAIT);
            printf("air = on\n");
        }else if(strncmp(air, "off",3) == 0 && strncmp(air_temp, "off",3) != 0){
            strcpy(air_temp, "off");
            send(sock, "air = off\n", BUF_SIZE, MSG_DONTWAIT);
            printf("air = off\n");
        }else if(strncmp(air, "auto",3) == 0 && strncmp(air_temp, "auto",4) != 0){
            strcpy(air_temp, "auto");
            send(sock, "air = auto\n", BUF_SIZE, MSG_DONTWAIT);
            printf("air = auto\n");
        }
    }
    return NULL;
}
 
void* recv_msg(void* arg)
{
    int sock=*((int*)arg);
    char name_msg[NORMAL_SIZE+BUF_SIZE];
    int str_len;
 
    while(1)
    {
        str_len=read(sock, name_msg, NORMAL_SIZE+BUF_SIZE-1);
        if (str_len==-1)
            return (void*)-1;
        name_msg[str_len]=0;
        fputs(name_msg, stdout);
        // 파일 저장 - 온도
        if(strncmp(name_msg, "Temperature",11) == 0){
            stream1 = fopen("Temperature.txt", "w"); //파일 포인터를 선언한다. //Temperature.txt를 쓰기용으로 연다.
            fputs(name_msg, stream1); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
            fclose(stream1); //파일을 닫는다.
        }else if(strncmp(name_msg, "Humidity",8) == 0){
            stream2 = fopen("Humidity.txt", "w"); //파일 포인터를 선언한다. //Humi.txt를 쓰기용으로 연다.
            fputs(name_msg, stream2); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
            fclose(stream2); //파일을 닫는다.
        }else if(strncmp(name_msg, "motion",6) == 0){
            stream3 = fopen("motion.txt", "w"); //파일 포인터를 선언한다. //Humi.txt를 쓰기용으로 연다.
            fputs(name_msg, stream3); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
            fclose(stream3); //파일을 닫는다.
        }   
    }
    return NULL;
}
 
 
void menuOptions() 
{
    int select;
    // print menu
    printf("\n\t**** menu mode ****\n");
    printf("\t1. change name\n");
    printf("\t2. clear/update\n\n");
    printf("\tthe other key is cancel");
    printf("\n\t*******************");
    printf("\n\t>> ");
    scanf("%d", &select);
    getchar();
    switch(select)
    {
        // change user name
        case 1:
        changeName();
        break;
 
        // console update(time, clear chatting log)
        case 2:
        menu();
        break;
 
        // menu error
        default:
        printf("\tcancel.");
        break;
    }
}
 
 
/** change user name **/
void changeName()
{
    char nameTemp[100];
    printf("\n\tInput new name -> ");
    scanf("%s", nameTemp);
    sprintf(name, "[%s]", nameTemp);
    printf("\n\tComplete.\n\n");
}
 
void menu()
{
    system("clear");
    printf(" **** moon/sum chatting client ****\n");
    printf(" server port : %s \n", serv_port);
    printf(" client IP   : %s \n", clnt_ip);
    printf(" chat name   : %s \n", name);
    printf(" server time : %s \n", serv_time);
    printf(" ************* menu ***************\n");
    printf(" if you want to select menu -> !menu\n");
    printf(" 1. change name\n");
    printf(" 2. clear/update\n");
    printf(" **********************************\n");
    printf(" Exit -> q & Q\n\n");
}    
 
void error_handling(char* msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
