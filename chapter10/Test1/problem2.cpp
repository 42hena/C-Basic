/*
문제 2
Point 클래스에 대해서 다음 조건을 만족하는 형태로 -연산자를 오버로딩 해보자
전역함수 기반으로 오버로딩
맴버 별 - 연산의 결과를 담은 Point 객체 반환
*/

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
    Point operator+=(Point &ref)
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }
    Point operator-=(Point &ref)
    {
        Point pos(xpos - ref.xpos, ypos - ref.ypos);
        return pos;
    }
};

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 += pos2;
    Point pos4 = pos1 -= pos2;
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    pos4.ShowPosition();
    return 0;
}