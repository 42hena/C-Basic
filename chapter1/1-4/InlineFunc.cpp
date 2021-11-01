#include <iostream>

inline int SQUARE(int x)
{
    return x*x;
}

int main(void)
{
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(12) << std::endl;
    return 0;
}
/*
해설
3행: 인라인 함수의 정의방법을 보이고 있다. 키워드 inline의 선언을 통해서 함수 SQUARE는 인라인 함수가 되었다.
10, 11행: SQUARE 함수를 호출하고 있다. 그런데 이 함수는 인라인 함수이니 몸체부분이 호출문을 대체하게 된다.

실행 결과
25
144
*/