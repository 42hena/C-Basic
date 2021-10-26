int operator*(int times, Point& ref)
{
    Point pos(times*ref.xpos, times*ref.ypos);
    return pos;
}