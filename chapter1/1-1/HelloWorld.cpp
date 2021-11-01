#include <iostream>

int main(void)
{
    int num = 20;
    std::cout << "Hello World!" << std::endl;
    std::cout << "Hello "<< "World!" << std::endl;
    std::cout << num << ' ' << 'A';
    std::cout << ' ' << 3.14 << std::endl;
    return (0);
}
/*
실행 결과
Hello World!
Hello World!
20 A 3.14
*/