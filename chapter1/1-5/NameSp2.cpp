#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc(void)
{
    std::cout << "Function in BestCom namespace" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
    std::cout << "Function in ProgCom namespace" << std::endl;
}
/*
해설
3~6행: 이름공간 안에 함수의 선언만 삽입되었다.
8~11행: 마찬가지로 이름공간 안에서 함수의 선언만 삽입되었다.
20행: 이름공간 BestComImpl에 선언된 함수 SimpleFunc의 정의부분이다. ::연산자는 함수의 호출 이외에도 다양하게 사용된다.
25행: 마찬가지로 이름공간 ProgComImpl에 선언된 함수 SimpleFunc의 정의부분이다.

실행 결과
Function in BestCom namespace
Function in ProgCom namespace
*/