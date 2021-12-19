#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char * name;
public:
    Person(const char * myname)
    {
        name = new char [strlen(myname) + 1];
        strcpy(name, myname);
    }
    ~Person()
    {
        delete []name;
    }
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
};

class UnivStudent : public Person
{
private:
    char * major;
public:
    UnivStudent(const char * myname, const char * mymajor)
        : Person(myname)
    {
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
    ~UnivStudent()
    {
        delete []major;
    }
    void WhoAreYou() const
    {
        WhatYourName();
        cout << "My major is " << major << endl << endl;
    }
};

int main(void)
{
    UnivStudent st1("Kim", "Mathematics");
    st1.WhoAreYou();
    UnivStudent st2("Hong", "Physics");
    st2.WhoAreYou();
    return 0;
}
/*
해설
12, 17행: UnivStudent의 기초 클래스인 Person 클래스의 소멸자는 생성자에서 할당한 메모리 공간을 해제하도록 정의하였다.
33, 38행: UnivStudent의 소멸자에서도 자신의 생성자에서 할당한 메모리 공간에 대한 해제만을 책임지고 있다. 어차피 기초 클래스의 소멸자가 호출이 되면서 기초 클래스의 생성자에서 할당한 메모리 공간을 해제하기 때문이다.

실행결과
My name is Kim
My major is Mathematics

My name is Hong
My major is Physics

+
error 경고 발생하여 const 추가 (warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]) <- 찾아보기
*/