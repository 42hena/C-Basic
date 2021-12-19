# 8-1 객체 포인터의 참조관계

상속은 IS-A관계의 표현을 위한 수단이다.

<h4>객체 포인터 변수: 객체의 주소 값을 저장하는 포인터 변수</h4>
Person * ptr;       //포인터 변수 선언
ptr = new Person(); //포인터 변수의 객체 참조

Person형 포인터는 Person 객체뿐만 아니라, Person을 상속하는 유도 클래스의 객체도 가리킬 수 있다.
class Student : public Person
{
    .....
};
Person * ptr = new Student();
Student 객체도 가리킬 수 있다.

class PartTimeStudent : public Student
{
    .....
};
Person형 포인터는 PartTimeStudent 객체도 가리킬 수 있다.


C++에서 AAA형 포인터 변수는 AAA객체 또는 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다(객체의 주소 값을 저장할 수 있다.)

8-1/ObjectPointer.cpp <파일 참고>

<h4>유도 클래스의 객체까지 가리킬 수 있다니!</h4>
논리적이지 않는 것 처럼 보이지만, 객체 포인터의 속성은 상속의 IS-A 관계를 통해서 논리적으로 이해 가능하다.
C++에서 AAA형 포인터 변수는 AAA객체 또는 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다(객체의 주소 값을 저장할 수 있다.)

학생(Student)은 사람(Persong)이다.                  -> 학생은 사람의 일종이다.
근로학생(PartTimeStudent)은 학생(Student)이다.      ->  근로학생은 학생의 일종이다.
근로학생(PartTimeStudent)은 사람(Person)이다.       ->  근로학생은 사람의 일종이다.

AAA -> BBB -> CCC
CCC는 AAA이다 또는 CCC는 AAA의 일종이다.

<h4>오렌지미디어 급여관리 확장성 문제의 1차적 해결과 함수 오버라이딩</h4>
정규직, 영업직, 임시직 모두 고용의 한 형태이다(고용인이다).
영업직은 정규직의 일종이다.
- 고용인        Employee
- 정규직        PermanentWorker
- 영업직        SalesWorker
- 임시직        TemporaryWorker

IS-A관계
TemporarayWorker is a Employee
PermanentWorker is a Employee
SalesWorker is a PermanentWorker

EmployeeHandler 클래스가 저장 및 관리하는 대상이 Employee 객체가 되게 하면, 이후에 Employee 클래스를 직접 혹은 간접적으로 상속하는 클래스가 추가되었을 때, EmployeeHandler 클래스에는 변화가 발생하지 않는다.

8-1/EmployeeManager2.cpp <파일 참고>

주석 신경 쓰지 말기

- 영업직 급여       기본급여(월 기본급여) + 인센티브
- 임시직 급여       시간당 급여 x 일한 시간

임시직 클래스
class TemporaryWorker : public Employee
{
private:
    int workTime;       // 이 달에 일한 시간의 합계
    int payPerHour      // 시간당 급여
public:
    TemporaryWorker(char * name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    {}
    void AddWorkTime(int time)  // 일한 시간의 추가
    {
        workTime += time;
    }
    int GetPay() const      // 이 달의 급여
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;        // 월 판매실적
    double bonusRatio;      // 상여금 비율
public:
    SalesWorker(char * name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay()    // PermanentWorker의 GetPay 함수 호출
            + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;     //SalesWorker의 GetPay 함수가 호출됨
    }
};

두 함수 모드 GetPay가 있는데 이를 함수 오버라이딩이라고 한다.(오버로딩과 혼동하면 안됨)

<참고 함수 오버라이딩 vs 함수 오버 로딩>
기초 클래스와 동일한 이름의 함수를 유도 클래스에서 정의한다고 해서 무조건 함수 오버라이딩이 되는 것은 아니다. 매개변수의 자료형 및 개수가 다르면, 이는 함수 오버로딩이 되어, 전달되는 인자에 따라서 호출되는 함수가 결정된다. 즉, 함수 오버로딩은 상속의 관계에서도 구성이 될 수 있다.

8-1/EmployeeManager3.cpp <파일 참고>

<h4>SalesWorker 클래스에서 ShowSalaryInfo 함수를 오버라이딩 한 이유는?</h4>
주석 해제시 일어나는 컴파일에러는 8-2(가상함수) 에서 이뤄진다.
class PermanentWorker : public Employee
{
private:
    .....
public:
    .....
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

class SalesWorker : public PermanentWorker
{
private:
    .....
public:
    .....
    int GetPay() const
    {
        return PermanentWorker::GetPay()    // PermanentWorker의 GetPay 함수 호출
            + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;     //SalesWorker의 GetPay 함수가 호출됨
    }
};

# 8-2 가상함수(Virtual Function)
<h4>기초 클래스의 포인터로 객체를 참조하면,</h4>
int main(void)
{
    Simple * sim = new
}

sim은 Simple 클래스 또는 Simple클래스를 상속하는 클래스의 객체라는 사실

class Base
{
public:
    void BaseFunc() { cout << "Base Function" << endl; }
};

class Derived : public Base
{
public:
    void DerivedFunc() { cout << "Derived Function" << endl; }
};
라고 가정 시

int main(void)
{
    Base *bptr = new Derived(); //컴파일 OK
    bptr->DerivedFunc();        //컴파일 Error
}
-> bptr이 Base형 포인터이기 떄문에 에러 발생
의문? 실제로 가리키는 대상은 Derived 객체이므로 실행되야하지 않니?
-> C++ 컴파일러 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.

int main(void)
{
    Base *bptr = new Derived(); //컴파일 OK
    Derived * dptr = bptr;      //컴파일 Error
}
해석
Derived 클래스는 Base 클래스의 유도 클래스니까 Base 클래스의 포인터 변수로 Derived 객체의 참조가 가능하므로 컴파일 가능하다.
컴파일러는 bptr이 실제 가리키는 객체가 Derived 객체라는 사실을 기억하지 않는다.
-> bptr은 Base형 포인터이니까, bptr이 가리키는 대상은 Base 객체일 수도 있는 거잖아! 그럴 경우에는 이 문장이 성립하지 않으니까, 컴파일 에러를 발생시켜야겠다.

int main(void)
{
    Derived * dptr = new Derived(); //컴파일 OK
    Base * bptr = dptr;             //컴파일 OK
}
dptr은 Derived 클래스의 포인터 변수니까, 이 포인터가 가리키는 객체는 분명 Base 클래스를 직접 혹은 간접적으로 상속하는 객체이다. Base형 포인터 변수로도 참조가 가능하다.

<참고 컴파일러는 바보?>
불필요한 포인터 연산을 허용하지 않음으로 인해 문제의 발생확률을 최소화시킬 수 있도록 정의된 C++의 문법에 근거를 하는 것임.

<h4>복습</h4>
class First
{
public:
    void FirstFunc() { cout << "FirstFunc" << endl; }
};
class Second
{
public:
    void SecondFunc() { cout << "SecondFunc" << endl; }
};
class Third : public Second
{
public:
    void ThirdFunc() { cout << "ThirdFunc" << endl; }
};

int main(void)
{
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;
    .....
}모두 정상작동

Third형 포인터 변수 tptr이 가리키는 객체는 무조건 Second형 포인터 변수 sptr도 가리킬 수 있으므로, Second형 포인터 변수 sptr이 가리키는 객체는 무조건 First형 포인터 변수 fptr도 가리킬수 있으므로, 오류가 발생하지 않으나, 객체를 참조하는 포인터의 형에 따라 호출할 수 있는 함수의 종류애는 다음과 같이 제한한다.

int main(void)
{
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    tptr->FirstFunc();      (o)
    tptr->SecondFunc();     (o)
    tptr->ThirdFunc();      (o)

    sptr->FirstFunc();      (o)
    sptr->SecondFunc();     (o)
    sptr->ThirdFunc();      (x)

    fptr->FirstFunc();      (o)
    fptr->SecondFunc();     (x)
    fptr->ThirdFunc();      (x)
    .....
}

결론적으론 포인터 형에 해당하는 클래스에 정의된 멤버에만 접근이 가능하다.

<h4>함수의 오버라이딩과 포인터 형</h4>
8-2/FunctionOverride.cpp <파일 참고>

fptr->MyFunc();
-> fptr이 First형 포인터이니, 이 포인터가 가리키는 객체를 대상으로 First 클래스에 정의된 MyFunc함수는 무조건 호출할 수 있겠구나

sptr->MyFunc();
-> sptr이 Second형 포인터이니, 이 포인터가 가리키는 객체에는 First의 MyFunc 함수와 Second의 MyFunc함수가 오버라이딩 관계로 존재하는군! 그럼 오버라이딩을 한 Second의 MyFunc 함수를 호출해야겠다.

tptr->MyFunc();
tptr이 Third형 포인터란 사실을 기억한다. 따라서 포인터 변수가 참조하는 객체에는 총 세 개의 MyFunc함수가 존재하고, 이들은 오버라이딩 관계를 갖기 때문에 가장 마지막에 오버라이딩을 한 Third 클래스의 MyFunc 함수가 호출되어야 한다는 사실을 알고 있다.

<h4>가상함수(Virtual Function)</h4>
함수를 오버라이딩을 했다는 것은, 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미인데, 포인터 변수의 자료형에 따라서 호출되는 함수의 종류가 달라지는 것은 문제가 있어 보입니다.

앞의 경우 SalesWorker 클래스에서 계산방식이 다르기 때문에 GetPay함수를 오버라이딩하였다. 포인터 자료형의 이유로 PermanentWorker 클래스의 GetPay함수가 대신 호출되어서 급여가 결정된다면, 잘못된 경우이다.
-> 가상함수라는 것을 제공

class First
{
public:
    virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

8-2/FunctionVirtualOverride.cpp <파일 참고>

<h4>오렌지미디어 급여관리 확장성 문제의 완전한 해결</h4>
배열을 구성하는 포인터 변수가 Employee형 포인터 변수이므로, Employee 클래스의 멤버가 아닌 GetPay함수와 ShowSalaryInfo 함수의 호출부분에서 컴파일 에러가 발생해서 주석처리 한것임.
Employee클래스에 GetPay함수와 ShowSalaryInfo 함수를 추가로 정의하고, 가상함수로 선언

8-2/EmployeeManager4.cpp <파일 참고>

<h4>오렌지미디어 급여관리 확장성 문제의 해결을 통해서 확인한 상속의 이유</h4>
Q. 상속을 하는 이유는 무엇인가?
A. 상속을 통해 연관된 일련의 클래스에 대해 공통적인 규약을 정의할 수 있습니다.

일련의 클래스 PermanentWorker, TemporaryWorker, SalesWorker에 적용된 공통규약은 Employee 클래스이다. 적용하고픈 공통규약을 모아서 Employee 클래스를 정의하고, 클래스를 상속하는 모든 클래스의 객체는 Employee 객체로 바라볼 수 있게 되었다.

<h4>순수 가상함수(Pure Virtual Function)와 추상 클래스(Abstract Class)</h4>
class Employee
{
private:
    char name[100];
public:
    Employee(char * name){}
    void ShowYourName() const{}
    virtual int GetPay() const
    {
        return 0;
    }
    virtual void ShowSalaryInfo() const
    { }
};
이 클래스는 기초 클래스로서만 의미를 가질 뿐, 객체의 생성을 목적으로 정의된 클래스는 아니고, 클래스 중에서 객체생성을 목적으로 정의되지 않는 클래스도 존재한다.
-> Employee * emp = new Employee("Lee Dong Sook"); 은 실수가 됨
문법적으로 아무런 문제가 없으므로 순수 가상함수로 선언하여 객체의 생성을 문법적으로 막는 것이 좋다.


class Employee
{
private:
    char name[100];
public:
    Employee(char * name){}
    void ShowYourName() const{}
    virtual int GetPay() const = 0;             //순수 가상함수
    virtual void ShowSalaryInfo() const = 0;    //순수 가상함수
};
순수 가상함수란 함수의 몸체가 정의되지 않은 함수를 의미한다.
0의 대입을 의미하는게 아닌 명시적으로 몸체를 정의하지 않았음을 컴파일러에게 알리는 것이다. 이 부분에서 함수의 몸체가 정의되지 않았다고 컴파일 오류를 일으키지는 않으나 Employee 클래스는 순수 가상함수를 지닌, 완전하지 않은 클래스가 되기 때문에 다음과 같이 객체를 생성하려 들면, 컴파일 에러가 발생한다.
Employee * emp = new Employee("Lee Dong Sook")

이점
1. 잘못된 객체의 생성을 막을 수 있다.
2. 유도 클래스에 정의된 함수가 호출되게끔 돕는데 의미가 있을뿐 실제로 실행이 되는 함수가 아니였으나, 이를 보다 명확히 명시하는 효과
하나 이상의 멤버 함수를 순수 가상함수로 선언한 클래스를 가리켜 추상 클래스라고 함

<h4>다형성(Polymorphism)</h4>
다형성이란 동질이상을 의미한다. 
모습은 같은데 결과는 다르다.

class First
{
public:
    virtual void SimpleFunc() { cout << "First" << endl; }
};

class Second
{
public:
    virtual void SimpleFunc() { cout << "Second" << endl; }
};

int main(void)
{
    First * ptr = new First();
    ptr->SimpleFunc();
    delete ptr;

    ptr = new Second();
    ptr-SimpleFunc();
    delete ptr;
    return 0;
}
ptr->SimpleFunc()
ptr은 동일한 포인터 변수이지만 실행결과는 다르다. -> 다형성의 예

# 8-3 가상 소멸자와 참조자의 참조 가능성
가상함수 말고 virtual키워드가 필요한 대상이 있다.

<h4>가상 소멸자(Virtual Destructor)</h4>
8-3/VirtualDestructor.cpp <파일 참고>

<h4>참조자의 참조 가능성</h4>
C++에서 AAA형 포인터 변수는 AAA객체 또는 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다(객체의 주소 값을 저장할 수 있다.)
참조자에도 적용된다.

First형 포인터 변수를 이용하면 First 클래스에 정의된 MyFunc 함수가 호출되고, Second형 포인터 변수를 이용하면 Second 클래스에 정의된 MyFunc함수가 호출되고, Third형 포인터 변수를 이용하면 Third 클래스에 정의된 MyFunc함수가 호출된다.
참조자에 적용됨

void GoodFunction(const First *ref){}
1. First 객체 또는 First를 직접 혹은 간접적으로 상속하는 클래스의 객체가 인자의 대상이 되는구나.
2. 인자로 전달되는 객체의 실제 자료형에 상관없이 함수 내에서는 Fisrt 클래스에 정의된 함수만 호출할 수 있겠구나!.
