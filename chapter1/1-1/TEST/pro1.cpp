/*
문제 설명
사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해 보자. 단, 프로그램의 실행은 다음과 같이 이뤄져야 한다.
*/
#include <iostream>
using namespace std;
int main(void)
{
    int n = 5;
    int num;
    int sum = 0;
    for (int i = 0 ;  i < 5 ; i++)
    {    
        cout << i + 1 << " num input: ";
        cin >> num;
        sum += num;
    }
    cout << "Sum : " << sum << '\n';
    return 0;
}