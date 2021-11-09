#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char * name;
    int age;
public:
    Person(char * myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Age:  " << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
/*
해설
11, 23행: 생성자에서 new를 이용한 동적 할당을, 소멸자에서 delete를 이용한 메모리의 해제를 진행함에 주목하자
33행: 별도의 복사 생성자가 정의되지 않았으므로, 디폴트 복사 생성자에 의한 맴버 대 맴버의 복사가 진행된다.

실행 결과
Name: Lee dong woo
Age:  29
Name: Lee dong woo
Age:  29
called destructor!
*/