#include <iostream>
using namespace std;

int main()
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;
    cout << *pref << endl;
    cout << **dpref << endl;
    return 0;
}
/*
해설
11, 12행: 포인터 변수의 참조자 선언도 & 연산자를 하나 더 추가하는 형태로 진행이 된다. 이미 잘 아는 10행의 참조자 선언과 비교하기 바란다.
15행: pref는 포인터 변수 ptr의 참조자이므로, 변수 num에 저장된 값이 출력된다.
16행: dpref는 포인터 변수 dptr의 참조자이므로, 변수 num에 저장된 값이 출력된다.

실행 결과
12
12
12
*/