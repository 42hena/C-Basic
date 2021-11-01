#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void);
}

namespace BestComImp1
{
    void PrettyFunc(void);
}

namespace ProgComImp1
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImp1::SimpleFunc();
    return 0;
}

void BestComImp1::SimpleFunc(void)
{
    std::cout << "Function in BestCom namespace" << std::endl;
    PrettyFunc();                   // 동일 이름공간
    ProgComImp1::SimpleFunc();      // 다른 이름공간
}

void BestComImp1::PrettyFunc(void)
{
    std::cout << "So Pretty" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
    std::cout << "Function in ProgCom namespace" << std::endl;
}
/*
3, 8행: 이름공간은 둘 이상의 영역으로 나뉘어서 선언할 수도 있다. 물론 이 둘은 동일공간으로 간주된다.
27행: 24행에 정의된 함수와 동일한 이름공간에 정의된 함수이다. 따라서 직접호출이 가능하다.
28행: 함수의 호출위치가 어떻게 되건, 이름공간 ProgComImpl에 정의된 함수 SimpleFunc를 호출하는 방법에는 차이가 없다.

실행 결과
Function in BestCom namespace
So Pretty
Function in ProgCom namespace
*/