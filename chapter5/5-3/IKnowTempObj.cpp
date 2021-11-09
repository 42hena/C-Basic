#include <iostream>
using namespace std;

class Temporary
{
private:
    int num;
public:
    Temporary(int n) : num(n)
    {
        cout << "create obj:" << num << endl;
    }
    ~Temporary()
    {
        cout << "destroy obj:" << num << endl;
    }
    void ShowTempInfo()
    {
        cout << "My num is " << num << endl;
    }
};

int main(void)
{
    Temporary(100);
    cout << "********** after make!" << endl << endl;

    Temporary(200).ShowTempInfo();
    cout << "********** after make!" << endl << endl;

    const Temporary &ref = Temporary(300);
    cout << "********** end of main!" << endl << endl;
    return 0;
}

/*
해설
25행: 이것이 임시객체를 직접 생성하는 방법이다. 이 문장에 의해서 100으로 초기화된 Temporary 임시객체가 생성된다.
28행: 임시객체를 생성하고, 이어서 이 객체를 대상으로 ShowTempInfo 함수를 호출하고 있다. 객체가 생성 및 반환되면, 생성 및 반환된 위치에 객체를 참조할 수 있는 참조 값이 반환되기 때문에 이러한 문장을 구성할 수 있는데 이에 대해서는 잠시 후에 별도로 정리하겠다.

실행 결과
create obj:100
destroy obj:100
********** after make!

create obj:200
My num is 200
destroy obj:200
********** after make!

create obj:300
********** end of main!

destroy obj:300
*/