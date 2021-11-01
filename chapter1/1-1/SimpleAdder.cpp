#include <iostream>

int main(void)
{
    int val1;
    std::cout<< "First num input: ";
    std::cin >> val1;

    int val2;
    std::cout<< "Second num input: ";
    std::cin >> val2;

    int result = val1 + val2;
    std::cout << "Add result: " << result << std::endl;
    return 0;
}
/*
해설
7행: 정수를 입력 받아서 val1에 저장
11행: 정수를 입력 받아서 val2에 저장

실행 결과
First num input: 3
Second num input: 5
Add result: 8
*/