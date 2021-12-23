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
    friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)
{
    Point pos(times*ref.xpos, times*ref.ypos);
    return pos;
}

int main(void)
{
    Point pos(1, 2);
    Point cpy;
    
    cpy = 3*pos;
    cpy.ShowPosition();
    
    cpy = 3*2*pos;
    cpy.ShowPosition();
    return 0;
}
/*
해설
23행: 교환법칙의 성립을 목적으로 함수가 추가로 정의되었다.
33행: 교환법칙이 성립됨을 보이고 있다.
36행: 교환법칙이 성립되면, 자연스러운 연산문의 구성이 가능하다.

실행결과
[3, 6]
[6, 12]
*/