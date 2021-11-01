#include <iostream>
using namespace std;

bool IsPositive(int num)
{
    if (num <= 0)
        return false;
    else
        return true;
}

int main(void)
{
    bool isPos;
    int num;
    cout << "Input number: ";
    cin >> num;

    isPos = IsPositive(num);
    if (isPos)
        cout << "Positive number" << endl;
    else
        cout << "Negative number" << endl;
    
    return 0;
}
/*
해설
4행: bool도 기본자료형이기 때문에 함수의 반환형으로 선언이 가능하다.
14, 19행: bool형 변수를 선언해서 함수 IsPositive가 반환하는 bool형 데이터를 저장하고 있다.

실행 결과
Input number: 12
Positive number

Input number: -12
Negative number
*/