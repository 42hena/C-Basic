/*
문제 설명
숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해보자. 예를 들어 사용자가 5를 입력한다면 구구단에서 5단을 출력해야 한다.
*/
#include <iostream>
using namespace std;
int main(void)
{
    int num;
    cout << "Input Number : ";
    cin >> num;
    for (int i = 0 ; i < 9 ; i++)
        cout << num << " x " << i + 1 << " = " << num * (i + 1) << '\n';
}