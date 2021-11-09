#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {}
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }    
    void ShowData()
    {
        cout << "num: " << num << endl;
    }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7);
    cout << "function call before" << endl;
    SimpleFuncObj(obj);
    cout << "function call after" << endl;
    return 0;
}
/*
실행 결과
function call before
Called SoSimple(const SoSimple& copy)
num: 7
function call after
*/