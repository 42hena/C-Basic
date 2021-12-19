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

class Police
{
private:
    int handcuffs;      // 소유한 수갑의 수
    Gun * pistol;       // 소유하고 있는 권총
public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    { 
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol -> Shot();
    }
    ~Police()
    {
        if (pistol != NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3);
    pman2.Shot();
    pman2.PutHandcuff();
    return 0;
}
/*
해설
23, 29행: 이전 예제와 달리 Gun 클래스를 상속하는 것이 아니라, 생성자에서 Gun 객체를 생성해서 이를 참조하고 있다.
38행: Gun 클래스를 상속한다면 별도의 Shot 함수를 정의할 필요가 없다. 그러나 Gun 객체를 멤버변수를 통해 참조하는 구조이기 때문에 이러헤 별도의 함수를 정의해야 한다.
58행: 총을 소유하지 않은 경찰을 객체로 생성하고 있다. 생성자의 첫 번째 인자로 0이 전달되면, 23행의 맴버변수는 NULL로 초기화되어, 총의 사용이 불가능해진다(총을 소유하지 않은 상태의 표현이다).

실행결과
BBANG!
SNAP!
Hut BBANG!
SNAP!
*/