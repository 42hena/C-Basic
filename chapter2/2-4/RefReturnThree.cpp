#include <iostream>
using namespace std;

int RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 1;
    int num2 = RefRetFuncOne(num1);

    num1 += 1;
    num2 += 100;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}
/*
해설
7행: 참조자를 반환하지만, 반환형이 기본자료형 int이기 때문에 참조자가 참조하는 변수의 값이 반환된다. 다시 한번 말하지만, 변수에 저장된 값이 반환된다.
15, 16행: num1과 num2가 다른 변수임을 확인하기 위해서 서로 다른 연산을 진행하였다.

실행 결과
num1: 3
num2: 102
*/