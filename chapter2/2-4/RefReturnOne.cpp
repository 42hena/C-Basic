#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 1;
    int &num2 = RefRetFuncOne(num1);

    num1++;
    num2++;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}
/*
해설
13행: RefRetFuncOne 함수가 참조자를 반환했고, 이를 다시 참조자에 저장하고 있다.
15, 16행: 변수 num1과 참조자 num2의 값을 1씩 증가시키고 있다.
17, 18행: 변수 num1과 참조자 num2의 관계를 확인하기 위한 출력이다.

실행 결과
num1: 4
num2: 4
*/