#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator*(int times)
    {
        Point pos(xpos * times, ypos * times);
        return pos;
    }
};

int main(void)
{
    Point pos(1, 2);
    Point cpy;
    
    cpy = pos*3;
    cpy.ShowPosition();
    
    cpy = pos*3*2;
    cpy.ShowPosition();
    return 0;
}
/*
해설
15행: 곱셈 연산자를 오버로딩 하였다. 따라서, Point 객체와 정수간의 곱셈이 가능하게 되었다.
17, 18행: 곱의 배수만큼 xpos와 ypos의 값이 증가된 Point객체를 생성 및 반환하는 형태로 연산자를 오버로딩 하였다.
27행: 이 문장에서 보이는 곱셈연산은 pos.operaotr*(3)으로 해석된다. 이렇게 해석이 되기 위해서는 Point 객체가 곱셈 연산자의 왼편에 와야 한다.
30행: 3을 곱했을 때 반환되는 객체를 대상으로 다시 2를 곱하는 연산을 하고 있다. 연산자의 결과가 cpy의 객체에 저장된다.

실행결과
[3, 6]
[6, 12]
*/