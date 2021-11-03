#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{
    char gamerID[ID_LEN]; // 소유자 ID
    int fuelGauge;        // 연료량
    int curSpeed;         // 현재속도

    void ShowCarState()
    {
        cout << "owner ID: " << gamerID << '\n';
        cout << "fuelGauge: " << fuelGauge << "%" << '\n';
        cout << "curSpeed: " << curSpeed << "km/s" << "\n\n";
    }
    void Accel()
    {
        if (fuelGauge <= 0)
            return;
        else
            fuelGauge -= FUEL_STEP;

        if (curSpeed + ACC_STEP >= MAX_SPD)
        {
            curSpeed = MAX_SPD;
            return;
        }

        curSpeed += ACC_STEP;
    }
    void Break()
    {
        if (curSpeed < BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= BRK_STEP;
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
10행: 함수를 맴버로 지니는 구조체의 정의를 보이고 있다.
51행: 초기화의 대상은 함수가 아닌 변수이다. 따라서 함수가 삽입되었어도 초기화의 방법은 달라지지 않는다.
52행: 구조체 run99에 존재하는(존재하는 것으로 이해 하였다.), Accel함수를 호출하고 있다. 구조체 내에 선언된 변수에 접근하는 방법과 동일한 방식으로 함수의 호출이 이뤄진다.
58, 59행: 또 다른 구조체 변수를 선언하였다. 그리고 이번에는 이 구조체를 대상으로 Accel함수를 호출하고 있다. 이렇듯 구조체 내에 함수가 정의되었기 때문에, 구조체 변수를 대상으로 함수의 호출이 이뤄져야 한다.

실행 결과
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