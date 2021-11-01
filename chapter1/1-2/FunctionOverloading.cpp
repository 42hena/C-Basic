#include <iostream>

void MyFunc(void)
{
    std::cout <<"Myfunc(void) called"<<std::endl;
}

void MyFunc(char c)
{
    std::cout <<"Myfunc(char c) called"<<std::endl;
}

void MyFunc(int a, int b)
{
    std::cout <<"Myfunc(int a, int b) called"<<std::endl;
}

int main(void)
{
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);
    return 0;
}
/*
해설
20행: 3행의 함수를 호출하는 문장이다.
21행: 8행의 함수를 호출하는 문장이다.
22행: 13행의 함수를 호출하는 문장이다.

실행 결과
Myfunc(void) called
Myfunc(char c) called
Myfunc(int a, int b) called
*/