#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2)
        : num1(n1), num2(n2)
    {
        //empty
    }
    SoSimple(SoSimple &copy)
        : num1(copy.num1), num2(copy.num2)
    {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    void ShowSimpleData()
    {
        cout << num1 << endl;
        cout << num2 << endl;
    }
};

int main(void)
{
    SoSimple sim1(15, 30);
    cout << "Create and Init before" << endl;
    SoSimple sim2 = sim1;           // SoSimple sim2(sim1)으로 변환
    cout << "Create and Init after" << endl;
    sim2.ShowSimpleData();
    return 0;
}
/*
해설
15행: SoSimple 객체를 인자로 받는 생성자가 추가되었다. 16행에서는 이니셜라이저를 이용해서 맴버 대 맴버의 복사를 진행하고, 생성자의 호출을 확인하기 위한 문장이 18행에 삽입되었다.
31행: 이 문장에 의한 객체생성 과정에서 15행에 정의된 생성자가 호출된다. 이는 실행결과를 통해서 확인이 가능하다.

실행 결과
Create and Init before
Called SoSimple(SoSimple &copy)
Create and Init after
15
30
*/