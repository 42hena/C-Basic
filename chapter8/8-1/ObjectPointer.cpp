#include <iostream>
using namespace std;

class Person
{
public:
    void Sleep() {cout << "Sleep" << endl;}
};

class Student : public Person
{
public:
    void Study() { cout << "Study" << endl;}
};

class PartTimeStudent : public Student
{
public:
    void Work() { cout << "Work" << endl; }
};

int main(void)
{
    Person * ptr1 = new Student();
    Person * ptr2 = new PartTimeStudent();
    Student * ptr3 = new PartTimeStudent();
    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();
    delete ptr1; delete ptr2; delete ptr3;
    return 0;
}
/*
해설
24행: Student는 Person을 상속하므로, Person형 포인터 변수는 Student 객체를 가리킬 수 있다.
25행: PartTimeStudent는 Person을 간접 상속하므로, Person형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있다.
26행: PartTimeStudent는 Student를 상속하므로, Student형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있다.

실행결과
Sleep
Sleep
Study
*/