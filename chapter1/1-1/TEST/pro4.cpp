/*
문제 설명
판매원들의 급여 계산 프로그램을 작성해보자. 이 회사는 모든 판매원에게 매달 50만원의 기본 급여와 판매 가격의 12%에 해당하는 돈을 지급한다. 예를 들어서 민수라는 친구의 이번 달 물품 판매금액이 100만원이라면, 50 + 100 x 0.12 = 62, 따라서 62만원을 급여로 지급 받는다. 단, 아래의 실행의 예에서 보이듯이 이러한 급여의 계산은 -1이 입력될 때까지 계속 되어야 한다.
*/

#include <iostream>
using namespace std;
int main(void)
{
    int num;
    while (true)
    {
        cout << "Input your sell things Number(-1 to end:): ";
        cin >> num;
        if (num == -1)
            break ;
        cout << "This month, you get "<< 50 + num * 0.12 << '\n';
    }
}