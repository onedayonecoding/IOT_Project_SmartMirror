#include <stdio.h>    // printf 함수를 사용하기 위하여!
#include <stdlib.h>  // system 함수를 사용하기 위하여!

int main()
{
    // TestC 프로그램을 실행합니다.
    int ret = system("/home/pi/project/src/UI/alarm/alarm.sh");
    return 0;
}
