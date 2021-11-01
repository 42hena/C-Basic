#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len)
{
    // char * str = (char *)malloc(sizeof(char) * len);
    char * str = new char[len];
    return str;
}

int main(void)
{
    char * str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    // free(str);
    delete []str;
    return 0;
}
/*
해설
7, 8행: 단순 비교를 하더라도 new를 이용한 동적할당이 훨씬 간결함을 알 수 있다.
18행: 배열의 형태로 할당된 메모리 공간의 해제를 보이고 있다.

실행결과
I am so happy~
*/