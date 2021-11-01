#include <iostream>
using namespace std;
int val = 100;      // 전역 변수
int main(void)
{
    int val = 20;   // 지역 변수
    val += 3;       // 지역 변수 val의 값 3증가
    ::val += 7;     // 전역 변수 val의 값 7증가
    cout << val << ' ' << ::val;
}