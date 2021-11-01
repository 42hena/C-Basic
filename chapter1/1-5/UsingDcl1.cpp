#include <iostream>

namespace Hybrid
{
    void HybFunc(void)
    {
        std::cout << "So simple function!" << std::endl;
        std::cout << "IN namespace Hybrid" << std::endl;
    }
}

int main(void)
{
    using Hybrid::HybFunc;
    HybFunc();
    return 0;
}
/*
해설
14행: 키워드 using을 이용해서 '이름공간 Hybrid에 정의된 HybFunc를 호출할 때에는, 이름 공간을 지정하고 않고 호출하겠다!'는 것을 명시(선언)하고 있다.
15행: 14행의 using 선언을 통해서 이름공간의 지정 없이 HybFunc함수를 호출하고 있다.

실행 결과
So simple function!
IN namespace Hybrid
*/