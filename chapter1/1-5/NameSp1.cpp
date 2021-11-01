#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "Function in BestCom namespace" << std::endl;
    }
}

namespace ProgComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "Function in ProgCom namespace " << std::endl;
    }
}

int main(void)
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}
/*
해설
3~9행: BestComImp이라는 이름의 공간을 마련하였다. 그리고 그 안에 함수 SimpleFunc를 정의하였다. 따라서 이 함수는 'BestComImpl::SimpleFunc'이라고 지칭하게 된다.
11~17행: ProgComImpl이라는 이름 공간을 마련하였다. 그리고 그 안에 함수SumpleFunc를 정의하였다. 따라서 이 함수는 'ProgComImpl::SimpleFunc'이라고 지칭하게 된다.
21행: 이름공간 BestComImpl 내에 정의된 함수 SimpleFunc의 호출문장이다.
22행: 이름공간 ProgComImpl 내에 정의된 함수 SimpleFunc의 호출문장이다.

실행 결과
Function in BestCom namespace
Function in ProgCom namespace
*/