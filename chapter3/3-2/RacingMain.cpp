#include "Car.h"

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
1행: main 함수를 구성하는 문장은 클래스 Car와 관련된 것뿐이다. 따라서 헤더파일 Car.h만 포함하면 된다.

실행 결과
owner ID: run99
fuelGauge: 94%
curSpeed: 30km/s

owner ID: run99
fuelGauge: 94%
curSpeed: 20km/s
*/