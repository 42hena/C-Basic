#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[100];
public:
    Employee(char * name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};

class PermanentWorker : public Employee
{
private:
    int salary;     // 월 급여
public:
    PermanentWorker(char * name, int money)
        : Employee(name), salary(money)
    { }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        /*
            for (int i = 0 ; i < enpNum ; i++)
                empList[i]->ShowSalaryInfo();
        */
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        /*
            for (int i = 0 ; i < enpNum ; i++)
                sum += empList[i]->GetPay();
        */
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
    //직원 관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    //직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}

//5행: 고용인을 의미하는 Employee 클래스가 추가되었다. 모든 고용인은 이름이 있으므로, 이와 관련된 맴버들을 기반으로 정의하였다
//20행: 이전의 PermanentWorker 클래스와 차이점은 Employee 클래스를 상속한다는 점이다. 떄문에 이름과 관련된 멤버는 모두 제거하였다.
//39행: 이전의 EmployeeHandler 클래스와 비교해볼 필요가 있다. 저장의 대상이 PermanentWorker 객체에서 Employee 객체로 변경되었다. 그러나, PermanentWorker 객체 역시 Employee 객ㅇ체의 일종이므로 저장이 가능하다.
//42행: AddEmployeee 함수의 인자로 Employee 객체의 주소 값을 전달해야 한다. 따라서 Employee 클래스를 상속하는 PermanentWorker 객체의 주소 값도 전달이 가능하다.
//54, 55행: 55행의 함수호출문이 컴파일 에러를 일으키기 때문에 주석처리 하였다. 이에 대해서는 잠시후 설명한다.
//62, 63행: 63행의 함수호출문이 컴파일 에러를 일으키기 때문에 주석처리 하였다. 이에 대해서는 잠시후 설명한다.