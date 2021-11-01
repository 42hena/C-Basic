#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int num = 20;
    cout << "Hello World!" << endl;
    cout << "Hello " << "World!" << endl;
    cout << num  << ' ' << 'A';
    cout << ' ' << 3.14 << endl;
    return 0;
}
/*
해설
2~4행: using 선언을 함수 밖에 전역의 형태로 삽입하였다. 따라서 이제부터 cin, cout, endl의 사용에 있어서 이름공간의 지정이 불필요하다.
9~12행: using 선언을 통해서 코드의 구성이 한결 간단해졌음을 알 수 있다.

실행 결과
Hello World!
Hello World!
20 A 3.14
*/