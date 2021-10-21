#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void);
}

namespace ProgComImp1
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();
}

void BestComImp1::SimpleFunc(void)
{
    std::cout << "Function in BestCom namespace" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
    std::cout << "Function in ProgCom namespace" << std::endl;
}