#include <iostream>

int main(void)
{
    int val1, val2;
    int result = 0;
    std::cout << "Two number input: ";
    std::cin >> val1 >> val2;

    if (val1 < val2)
    {
        for (int i = val1 + 1 ; i < val2 ; i++)
            result += i;   
    }
    else
    {
        for (int i = val2 + 1 ; i < val1 ; i++)
            result += i;
    }

    std::cout << "Between Two number Integer Sum: " << result << std::endl;
    return 0;
}
/*
해설
8행: 두 개의 정수를 입력받아서 val1, val2에 순서대로 저장할 것을 명령하는 문장
12행, 17행: 이 두 문장에서 보이듯이 for문 내에서 변수를 선언할 수 있다.

실행결과
Two number input: 3 7
Between Two number Integer Sum: 15
*/