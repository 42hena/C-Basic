#include <iostream>

int main(void)
{
    char name[100];
    char lang[200];

    std::cout << "What is your name? ";
    std::cin >> name;

    std::cout << "What is your favorite language? ";
    std::cin >> lang;

    std::cout << "My name is " << name << ".\n";
    std::cout << "My favorite language is " << lang <<"." << std::endl;    
    return 0;
}
/*
해설
9, 12행: 배열에 문자열을 저장하고 명령하고 있다.
14행: '\n'과 같은 특수문자는 C언어에서와 같은 의미를 지닌다. 다만 std::endl;로 개행의 역할을 대신할 뿐이다.

실행결과
What is your name? Young
What is your favorite language? C++
My name is Young.
My favorite language is C++.
*/