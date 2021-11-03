#include <iostream>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

struct Car
{
    char gamerID[CAR_CONST::ID_LEN]; // 소유자 ID
    int fuelGauge;                   // 연료량
    int curSpeed;                    // 현재속도

    void ShowCarState();
    void Accel();
    void Break();
};

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
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}
/*
해설
22~24행: 구조체 안에 함수의 원형만 남으니, 함수의 종류가 한눈에 들어오고, 적절한 주석을 통해 함수의 기능도 쉽게 판단이 된다.
27, 33, 48행: 원래 속하는 구조체 이름을 명시하면서 구조체 밖으로 함수의 정의가 빠져 나왔다.

실행 결과
owner ID: run99
fuelGauge: 98%
curSpeed: 10km/s

owner ID: run99
fuelGauge: 98%
curSpeed: 0km/s
*/