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
    Point& operator++()     // 전위증가
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    const Point operator++(int)     // 후위증가
    {
        const Point retobj(xpos, ypos);
        xpos += 1;
        ypos += 1;
        return retobj;
    }
    friend Point& operator--(Point &ref);
    friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point &ref, int)
{
    const Point retobj(ref);        //const 객체라 한다.
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj;
}
int main(void)
{
    Point pos(3, 5);
    Point cpy;
    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();
    
    cpy = pos++;
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}

//15행: ++ 연산자가 맴버함수의 형태로 오버로딩 되었다.
//21행: 24행에 정의된 전역함수에 대해 friend 선언을 하고 있다.
//24행: -- 연산자가 전역함수의 형태로 오버로딩 되었다.
//34행: ++연산자는 맴버함수의 형태로 오버로딩 되었으므로, 이 문장은 pos.operator++();으로 해석된다.
//36행: --연산자는 전역함수의 형태로 오버로딩 되었으므로, 이 문장은 operator--(pos);으로 해석된다.
//39행, 41행: 이 두 문장이 어떻게 구성 가능한지 잠시 후에 설명하겠다.
/*
실행 결과
[2, 3]
[1, 2]
[3, 4]
[1, 2]
*/