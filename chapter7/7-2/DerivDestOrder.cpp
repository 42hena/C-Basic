#include <iostream>
using namespace std;

class SoBase
{
private:
    int baseNum;
public:
    SoBase(int n) : baseNum(n)
    {
        cout << "SoBase() : " << baseNum << endl;
    }
    ~SoBase()
    {
        cout << "~SoBase() : " << baseNum << endl;
    }
};

class SoDerived : public SoBase
{
private:
    int derivNum;
public:
    SoDerived(int n) : SoBase(n), derivNum(n)
    {
        cout << "SoDerived() : " << derivNum << endl;
    }
    ~SoDerived()
    {
        cout << "~SoDerived() : " << derivNum << endl;
    }
};

int main(void)
{
    SoDerived dr1(15);
    SoDerived dr2(27);
    return 0;
}
/*
실행결과
SoBase() : 15
SoDerived() : 15
SoBase() : 27
SoDerived() : 27
~SoDerived() : 27
~SoBase() : 27
~SoDerived() : 15
~SoBase() : 15
*/