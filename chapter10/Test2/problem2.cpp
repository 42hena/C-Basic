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
    friend Point& operator~(Point &ref);
};

Point& operator~(Point &ref)
{
    int tmp;
    tmp = ref.xpos;
    ref.xpos = ref.ypos;
    ref.ypos = tmp;
    return ref;
}

int main(void)
{
    Point pos(1, 2);
    pos.ShowPosition();
    Point pos1 = ~pos;
    pos1.ShowPosition();
    return 0;
}