#include <iostream>
#include <cstring>
using namespace std;

class First
{
private:
    char * strOne;
public:
    First(const char * str)
    {
        strOne = new char[strlen(str) + 1];
    }
    virtual ~First()
    {
        cout << "~First()" << endl;
        delete []strOne;
    }
};

class Second : public First
{
private:
    char * strTwo;
public:
    Second(const char * str1, const char * str2) : First(str1)
    {
        strTwo = new char[strlen(str2) + 1];
    }
    ~Second()
    {
        cout << "~Second()" << endl;
        delete []strTwo;
    }
};

int main(void)
{
    First * ptr = new Second("simple", "complex");
    delete ptr;
    return 0;
}

/*
해설
11, 16행: First 클래스의 생성자에서 동적 할당이 있었기 때문에 소멸자가 적절히 정의되었다.
27, 32행: Seoncd 클래스의 생성자에서 동적 할당이 있었기 때문에 소멸자가 적절히 정의되었다.
38, 39행: 38행에서 생성한 객체를 39행에서 소멸하고 있다. 따라서 이 경우에는 First 클래스의 소멸자와 Second 클래스의 소멸자가 동시에 호출되어야한다. 실제로 그렇게 호출이 이뤄지는지 예제를 통해서 확인해보자

실행결과
~First

virtual 추가시 실행결과
~Second()
~First()
*/