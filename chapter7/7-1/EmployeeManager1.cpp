#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class PermanentWorker
{
private:
    char name[100];
    int salary;
public:
    PermanentWorker(const char* name, int money)
        :salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class EmployeeHandler
{
private:
    PermanentWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(PermanentWorker* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0 ; i < empNum ; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0 ; i < empNum ; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0 ; i < empNum ; i++)
            delete empList[i];
    }
};

int main(void)
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handelr;

    // 직원 등록
    handelr.AddEmployee(new PermanentWorker("KIM", 1000));
    handelr.AddEmployee(new PermanentWorker("LEE", 1500));
    handelr.AddEmployee(new PermanentWorker("JUN", 2000));

    // 이번 달에 지불해야 할 급여의 정보
    handelr.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handelr.ShowTotalSalary();
    return 0;
}
/*
실행 결과
name: KIM
salary: 1000

name: LEE
salary: 1500

name: JUN
salary: 2000

salary sum: 4500
*/