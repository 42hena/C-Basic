#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void)
    {
        std::cout << "Function in BestCom namespace" << std::endl;
    }
}

namespace ProgComImp1
{
    void SimpleFunc(void)
    {
        std::cout << "Function in ProgCom namespace " << std::endl;
    }
}

int main(void)
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();
}