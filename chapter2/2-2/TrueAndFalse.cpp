#include <iostream>
using namespace std;

int main(void)
{
    int num = 10;
    int i = 0;

    cout << "true: " << true << endl;
    cout << "false: " << false << endl;

    while (true)
    {
        cout << i++ << ' ';
        if (i > num)
            break;
    }
    cout << endl;

    cout << "sizeof 1:" << sizeof(1) << endl;
    cout << "sizeof 0:" << sizeof(0) << endl;
    cout << "sizeof true:" << sizeof(true) << endl;
    cout << "sizeof false:" << sizeof(false) << endl;
    return 0;
}
/*
해설
9, 10 행: 키워드 true와 false를 콘솔에 출력했을 때의 출력내용을 확인하기 위한 문장이다.
12행: C언어에서는 무한루프를 형성하기 위해서 일반적으로 숫자 1을 사용한다. C++에서도 물론 숫자 1을 사용할 수 있지만, 이렇게 true대신 사용할 수도 있다.
20, 21행: 상수 1과 상수 0의 데이터 크기를 확인하기 위한 문장이다.
22, 23행: 참과 거짓을 의미하는 데이터 true와 false의 크기를 확인하기 위한 문장이다.

실행 결과
true: 1
false: 0
0 1 2 3 4 5 6 7 8 9 10
sizeof 1:4
sizeof 0:4
sizeof true:1
sizeof false:1
PS C:\Users\somni\
*/