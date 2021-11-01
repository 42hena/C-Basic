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
    int num2 = RefRetFuncOne(num1);

    num1 += 1;
    num2 += 100;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}
/*
해설
13행: 참조형으로 반환이 되지만, 이렇듯 참조자가 아닌 일반변수를 선언해서 반환 값을 저장할 수 있다. 여기서 중요한 점은 12행에 선언된 num1과 13행에 선언된 num2는 완전히 별개의 변수라는 것이다.
15, 16행: num1과 num2가 다른 변수임을 확인하기 위해서 서로 다른 연산을 진행하였다.

실행결과
num1: 3
num2: 102
*/