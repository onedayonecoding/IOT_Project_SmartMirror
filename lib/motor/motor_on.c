#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

void motorControl()
{
    //FILE* stream; //파일 포인터를 선언한다.
    pinMode(2, OUTPUT); 		/* Pin의 모드 설정 */
    digitalWrite(2, HIGH); 	/* HIGH(1) 값을 출력 : 모터 켜기 */
    //stream = fopen("motor.txt", "w"); //파일 포인터를 선언한다. //Temperature.txt를 쓰기용으로 연다.
    //fputs("on", stream); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
    //fclose(stream); //파일을 닫는다.
}

int main(int argc, char **argv)
{

    printf("%s\n","moter on");
    wiringPiSetup( );
    motorControl(2);
    FILE* stream; //파일 포인터를 선언한다.
    stream = fopen("motor.txt", "w"); //파일 포인터를 선언한다. //Temperature.txt를 쓰기용으로 연다.
    fputs("on", stream); //받은 문자열 txt을 stream포인터가 가르키고 있는 곳에 넣는다.
    fclose(stream); //파일을 닫는다.

    return 0;
}
