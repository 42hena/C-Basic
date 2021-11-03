#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN      = 20, MAX_SPD     = 200, FUEL_STEP   = 2, 
        ACC_STEP    = 10, BRK_STEP    = 10
    };
}

class Car
{
    private:
        char    gamerID[CAR_CONST::ID_LEN];
        int     fuelGauge;
        int     curSpeed;
    public:
        void    InitMembers(const char * ID, int fuel);
        void    ShowCarState();
        void    Accel();
        void    Break();
};

void Car::InitMembers(const char * ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}
void Car::ShowCarState()
{
    cout << "owner ID: " << gamerID << '\n';
    cout << "fuelGauge: " << fuelGauge << "%" << '\n';
    cout << "curSpeed: " << curSpeed << "km/s" << "\n\n";
}
void Car::Accel()
{
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}
/*
해설
14행: struct를 대신해서 class 선언이 삽입되었다. 따라서 클래스의 정의에 해당한다.
16행: 접근제어 지시자중 하나의 private이 선언되었으므로, 이어서 등장하는 변수와 함수는 private에 해당하는 범위 내에서(클래스 내에서만) 접근이 가능하다.
20행: 접근제어 지시자중 하나인 public이 선언되었으므로, 이어서 등장하는 변수와 함수는 public에 해당하는 범위내에서(어디서든) 접근이 가능하다.
21, 27행: 클래스 안에 선언된 변수의 초기화를 목적으로 정의된 함수이다. 변수가 모두 private으로 선언되어서 main함수에서 접근이 불가능하다. 하지만 이 함수는 동일 클래스 내에 정의된 함수이므로 접근이 가능하다. 뿐만 아니라, 이 함수는 public으로 선언되어서 main 함수에서 호출이 가능하다. 따라서 main함수에서는 이 함수의 호출을 통해서 클래스 안에 선언된 변수를 초기화할 수 있다.
66행: 초기화를 목적으로 InitMembers 함수를 호출하고 있다. 이 함수는 ID정보와 연료의 게이지 정보를 전달받아서 초기화하는 형태로 정의되었다. 단, 변수 curSpeed는 무조건 0으로 초기화 되도록 정의되었다.
66 ~ 72행: 함수호출이 가능한 이유는 함수가 모두 public으로 선언되었기 때문이다.

실행 결과
owner ID: run99
fuelGauge: 94%
curSpeed: 30km/s

owner ID: run99
fuelGauge: 94%
curSpeed: 20km/s
*/