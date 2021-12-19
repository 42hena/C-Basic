#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
    char owner[50];
public:
    Computer(const char * name)
    {
        strcpy(owner, name);
    }
    void Calculate()
    {
        cout << "Calculate your request." << endl;
    }
};

class NotebookComp : public Computer
{
private:
    int Battery;
public:
    NotebookComp(const char * name, int initChag)
        : Computer(name), Battery(initChag)
    { }
    void charging() { Battery += 5; }
    void UseBattery() { Battery -= 1; }
    void MovingCal()
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "need charge." << endl;
            return ;
        }
        cout << "Moving ";
        Calculate();
        UseBattery();
    }
    int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
private:
    char regstPenModel[50];
public:
    TabletNotebook(const char * name, int initChag, const char * pen)
        : NotebookComp(name, initChag)
    {
        strcpy(regstPenModel, pen);
    }
    void Write(const char * penInfo)
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "Need charge" << endl;
            return ;
        }
        if (strcmp(regstPenModel, penInfo)!=0)
        {
            cout << "not enrolled pen" << endl;
            return ;
        }
        cout << "Handwriting is processed." << endl;
        UseBattery();
    }
};

int main(void)
{
    NotebookComp nc("이수종", 5);
    TabletNotebook tn("정수영", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}
/*
해설
5~18행: 모든 컴퓨터의 공통적인 특성을 Computer 클래스 하나에 표현하였다. 모든 컴퓨터는 소유자가 있으니 소유자 정보를 저장할 수 있도록 정의했고, 또 계산의 기능이 있으니 계산과 관련된 함수를 하나 정의하였다.
20~42행: NotebookComp는 노트북 컴퓨터를 표현한 클래스이다. 노트북 컴퓨터는 배터리가 있어서 이동이 가능하므로 이와 관련된 변수 및 함수를 추가하였고, 컴퓨터를 사용할때마다(MovingCal 함수가 호출될 때 마다) 배터리는 소모되는 상황을 표현하였다.
44~69행: TableNotebook은 펜이 있어서 필기가 가능한 노트북 컴퓨터를 표현한 클래스이다. 펜을 등록하고 등록이 된 펜을 사용해야 필기가 가능한 상황을 표현하였다.(실제와는 조금 다름)

실행 결과
Moving Calculate your request.
Handwriting is processed.

에러 처리
warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
const 붙이기
*/