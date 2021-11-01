#include <iostream>
using namespace std;

int main(void)
{
    int num1 = 1020;
    int &num2 = num1;

    num2 = 3047;
    cout << "VAL: " << num1 << endl;
    cout << "REF: " << num2 << endl;

    cout << "VAL: " << &num1 << endl;
    cout << "REF: " << &num2 << endl;
    return 0;
}
/*
해설
7행: num1에 대한 참조자 num2를 선언하였다. 따라서 이후로는 num1과 num2가 동일한 메모리 공간을 참조하게 된다.
10, 11행: 동일한 값이 출력되면, num1과 num2가 동일한 메모리 공간을 참조함을 증명하는 셈이다.
13, 14행: num1과 num2의 주소 값을 출력하게 하였다. 이 출력 값에 중점을 두고 보셈.

실행 결과
VAL: 3047
REF: 3047
VAL: 0x61ff08
REF: 0x61ff08
*/