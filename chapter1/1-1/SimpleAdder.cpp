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