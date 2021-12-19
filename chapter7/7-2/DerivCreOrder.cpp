#include <iostream>
using namespace std;

class SoBase
{
private:
    int baseNum;
public:
    SoBase() : baseNum(20)
    {
        cout << "SoBase()" << endl;
    }
    SoBase(int n) : baseNum(n)
    {
        cout << "SoBase(int)" << endl;
    }
    void ShowBaseDate()
    {
        cout << baseNum << endl;
    }
};

class SoDerived : public SoBase
{
private:
    int derivNum;
public:
    SoDerived() : derivNum(30)
    {
        cout << "SoDerived()" << endl;
    }
    SoDerived(int n) : derivNum(n)
    {
        cout << "SoDerived(int n)" << endl;
    }
    SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
    {
        cout << "SoDerived(int n1, int n2)" << endl;
    }
    void ShowDerivDate()
    {
        ShowBaseDate();
        cout << derivNum << endl;
    }
};

int main(void)
{
    cout << "case1..... " << endl;
    SoDerived dr1;
    dr1.ShowDerivDate();
    cout << "--------------------" << endl;
    cout << "case2..... " << endl;
    SoDerived dr2(12);
    dr2.ShowDerivDate();
    cout << "--------------------" << endl;
    cout << "case3..... " << endl;
    SoDerived dr3(23, 24);
    dr3.ShowDerivDate();
    
    return 0;
}
/*
해설
28행: 이 생성자를 살펴보면, 기초 클래스의 생성자 호출에 대한 언급이 없음을 알 수 있다.
32행: 이 생성자 역시 기초 클래스의 생성자 호출에 대한 언급이 전혀 없다.
36행: 이 생성자의 경우에는 n1을 인자로 받는 기초 클래스의 생성자 호출을 직접 명시하고 있다.

실행 결과
case1..... 
SoBase()
SoDerived()
20
30
--------------------
case2.....
SoBase()
SoDerived(int n)
20
12
--------------------
case3.....
SoBase(int)
SoDerived(int n1, int n2)
23
24
*/