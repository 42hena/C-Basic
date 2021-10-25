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
    EmployeeHandler handelr;

    handelr.AddEmployee(new PermanentWorker("KIM", 1000));
    handelr.AddEmployee(new PermanentWorker("LEE", 1500));
    handelr.AddEmployee(new PermanentWorker("JUN", 2000));

    handelr.ShowAllSalaryInfo();

    handelr.ShowTotalSalary();
    return 0;
}