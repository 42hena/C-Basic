#include <iostream>
using namespace std;

namespace CAR_CONST{
    enum{
        ID_LEN      = 20,
        MAX_SPD     = 200,
        FUEL_STEP   = 2,
        ACC_STEP    = 10,
        BRK_STEP    = 10
    };
}

struct Car
{
    char    gamerID[CAR_CONST::ID_LEN]; // 소유자 ID
    int     fuelGauge;                  // 연료량
    int     curSpeed;                   // 현재속도

    void ShowCarState()
    {
        cout << "Owner ID: " << gamerID << '\n';
        cout << "fuelGauge: " << fuelGauge << "%" << '\n';
        cout << "curSpeed: " << curSpeed << "km/s" << "\n\n";
    }

    void Accel()
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

    void Break()
    {
        if (curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= CAR_CONST::BRK_STEP;
    }
};

int main(void)
{
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car run77 = {"run77", 100, 0};
    run77.Accel();
    run77.Break();
    run77.ShowCarState();
    return 0;
}
/*
해설
4~14행: CAR_CONST 이름공간 안에 구조체 Car에서 사용하는 상수들을 모두 모아놓았다.
18행: 상수 ID_LEN의 접근을 위해서 이름공간 CAR_CONST를 지정하고 있다. 이렇듯 이름공간을 지정해서 코드를 작성했기 때문에, 이 문장만 봐도 이 상수가 어느 영역에서 선언되고 사용되는 상수인지 쉽게 알 수 있다. 그래서 가독성이 좋아졌다고 할 수 있다.

owner ID: run99
fuelGauge: 96%
curSpeed: 20km/s

owner ID: run99
fuelGauge: 96%
curSpeed: 10km/s

owner ID: run77
fuelGauge: 98%
curSpeed: 0km/s
*/