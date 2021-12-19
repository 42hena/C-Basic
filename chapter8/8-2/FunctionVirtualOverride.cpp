#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
    virtual void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second
{
public:
    virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main(void)
{
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    return 0;
}
/*
해설
7, 13, 19행: 7행의 MyFunc함수가 virtual로 선언되었으니, 13, 19행의 함수에는 굳이 virtual 선언을 추가하지 않아도 가상함수가 된다. 그러나 이렇게 virtual 선언을 넣어서 함수가 가상함수임을 알리는 것이 좋다.

실행 결과
ThirdFunc
ThirdFunc
ThirdFunc
*/