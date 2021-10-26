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
    Point operator+(const Point &ref)
    {
        Point pos(xpos+ref.xpos, ypos+ref.ypos);
        return pos;
    }
};

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1.operator+(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return 0;
}

//15행: 함수의 이름이 operator+이다. 조금 독특하다고 생각해도 좋다. 이름의 형태가 조금 어색하지만 분명히 이는 함수의 이름이다.
//26행: pos1 객체의 맴버함수 operator+를 호출하면서 인자로 pow2객체를 전달하고 있다. 따라서 이 두 객체의 맴버 별 덧셈결과로 새로운 Point 객체가 만들어지고, 이것이 반환되어 pos3를 초기화하게 된다.(이 과정에서 복사 생성자가 호출된다.)
/*
실행 결과
[3, 4]
[10, 20]
[13, 24]
*/