/*
문제설명
다음과 같은 형태로의 함수 오버로딩은 문제가 있다. 어떠한 문제가 있는지 설명해보자.

SimpleFunc()을 실행하게되면 둘 중 어떤 것을 설정해야하는지 모름
*/
#include <iostream>
int SimpleFunc(int a = 10);
int SimpleFunc(void);

int main(void)
{
    std::cout << "[] : " << SimpleFunc() << std::endl;

    return 0;
}

int SimpleFunc(int a = 10)
{
    return a + 1;
}

int SimpleFunc(void)
{
    return 10;;
}
