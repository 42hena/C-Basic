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
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }
    void ShowData()
    {
        cout << "num: " << num << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "return before" << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}
/*
해설
15행: 이 예제의 이해를 위해서는 참조형을 반환하는 AddNum 함수를 잘 이해해야 한다.
18행: 이 문장을 실행하는 객체 자신을 반환하고 있다. 그런데 반환형이 참조형이니, 참조 값이 반환된다. 이와 관련해서는 Chapter 04의 마지막 부분에서 자세히 설명하였다.
26행: 매개변수 선언을 보면, 인자의 전달과정에서 복사 생성자가 호출됨을 알 수 있다.
29행: ob객체를 반환하고 있다. 그런데 반환형이 참조형이 아니다. 따라서 ob객체의 복사본이 만들어지면서 반환이 진행된다. 이와 관련해서는 잠시 후에 별도로 설명하겠다.
35행: SimpleFuncObj 함수가 반환한 객체를 대상으로 AddNum 함수를 호출하고, 이어서 AddNum 함수가 반환하는 참조 값을 대상으로 ShowData 함수를 호출하고 있다.
36행: 35행의 출력결과와 비교하기 위해서 34행에서 생성한 객체를 대상으로 ShowData 함수를 호출하고 있다.

실행 결과
Called SoSimple(const SoSimple& copy)
return before
Called SoSimple(const SoSimple& copy)
num: 37
num: 7
*/