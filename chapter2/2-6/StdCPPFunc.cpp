#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[] = "Result";
    char str2[30];

    strcpy(str2, str1);
    printf("%s: %f \n", str1, sin(0.14));
    printf("%s: %f \n", str2, abs(-1.25));
    return 0;
}

/*
1행: C표준헤더 math.h
2행: C표준헤더 stdio.h
3행: C표준헤더 string.h
4행: C표준헤더 C의 표준에 정의된 함수들 조차 이름공간 std안에 선언이 되어 있어서 이 문장이 삽입되어야 한다.
11~13행: C언어의 표준함수를 호출하고 있다.

실행 결과
Result: 0.139543
Result: 1.250000
*/