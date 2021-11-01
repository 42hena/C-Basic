#include <iostream>

int Adder(int num1 = 1, int num2 = 2)
{
    return num1 + num2;
}

int main(void)
{
    std::cout << Adder() << std::endl;
    std::cout << Adder(5) << std::endl;
    std::cout << Adder(3, 5) << std::endl;
    return 0;
}
/*
해설
3행: Adder 함수의 디폴트 값으로 1과 2가 설정되었다.
10행: Adder 함수를 호출하면서 인자를 전달하지 않았으니, 1과 2가 전달된 것으로 간주된다.
11행: Adder 함수를 호출하면서 인자를 하나만 전달하고 있다. 이러한 경우 인자는 첫번째 매개변수로 전달 된다. 따라서 두 번째 매개변수 num2에는 2가 전달된 것으로 간주된다.
12행: Adder 함수를 호출하면서 두 개의 인자를 직접 전달하였다. 이러한 경우 매개변수의 디폴트 값은 의미를 갖지 않는다.

실행 결과
3
7
8
*/