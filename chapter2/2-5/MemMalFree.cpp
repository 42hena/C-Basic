#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStrAdr(int len)
{
    char * str = (char *)malloc(sizeof(char) * len);
    return str;
}

int main(void)
{
    char * str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    free(str);
    return 0;
}
/*
해설
2, 3행: C++에서 C언어의 헤더파일을 추가하는 것도 가능하다. 이와 관련해서는 잠시 후에 별도로 언급을 한다.
8행: 문자열 저장을 위한 배열을 힙 영역에 할당하고 있다.
17행: 힙에 할당된 메모리 공간을 소멸하고 있다.

실행 결과
I am so happy~
*/