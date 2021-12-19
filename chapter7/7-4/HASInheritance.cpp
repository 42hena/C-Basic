#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;     // 장전된 총알의 수
public:
    Gun(int bnum) : bullet(bnum)
    { }
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police : public Gun
{
private:
    int handcuffs;      // 소유한 수갑의 수
public:
    Police(int bnum, int bcuff)
        : Gun(bnum), handcuffs(bcuff)
    { }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
};

int main(void)
{
    Police pman(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();
    return 0;
}
/*
해설
5~17행: Gun은 총을 표현한 클래스이다. 표현의 간결함을 위해서 총알을 추가로 장전하는 등의 기능은 생략하였다.
19~32행: Police는 경찰을 표현한 클래스이다. 경찰은 기본적으로 수갑능 지닌다고 가정하였고, 수갑을 추가로 지니는 등의 기능은 예제의 간결함을 위해 생략하였다.

실행결과
BBANG!
SNAP!
*/