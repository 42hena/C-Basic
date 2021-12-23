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
    friend Point operator+(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return 0;
}
/*
해설
15행: 18행의 함수에 대해 private 영역의 접근을 허용하기 위해서 friend 선언을 하고 있다.
18행: +연산자를 전역함수의 형태로 오버로딩 하였다. Point클래스는 이 함수에 대해서 friend선언을 하였으므로, 함수 내에서는 Point클래스의 private맴버에 접근이 가능하다.
28행: +연산자가 전역함수의 형태로 오버로딩 되었으므로, +연ㅅㄴ은 'operator+(pos1, pos2)로 해석이 된다.

실행 결과
[3, 4]
[10, 20]
[13, 24]
*/