#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout << "New Object: " << this << endl;
    }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "New Copy obj: " << this << endl;
    }
    ~SoSimple()
    {
        cout << "Destroy obj: " << this << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Parm ADR: " << &ob << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj);

    cout << endl;
    SoSimple tempRef = SimpleFuncObj(obj);
    cout << "Return Obj " << &tempRef << endl;
    return 0;
}
/*
실행 결과
New Object: 0x61ff00
New Copy obj: 0x61ff08
Parm ADR: 0x61ff08
New Copy obj: 0x61ff04
Destroy obj: 0x61ff04
Destroy obj: 0x61ff08

New Copy obj: 0x61ff0c
Parm ADR: 0x61ff0c
New Copy obj: 0x61fefc
Destroy obj: 0x61ff0c
Return Obj 0x61fefc
Destroy obj: 0x61fefc
Destroy obj: 0x61ff00
*/