# 7-1 상속에 들어가기에 앞서
상속은 적절한 때에 사용이 가능해야할 적용이 중요한 문법이다.

<h4>상속(Inheritance)의 이해를 위한 이 책의 접근방식</h4>
상속이 지니는 문법적 요소와 더불어 이점을 정확히 이해해야한다.

1단계: 문제의 제시
상속과 더불어 다형성의 개념을 적용해야만 해결 가능한 문제를 먼저 제시한다. <- 다형성 찾아보기 (p272)
2단계: 기본개념 소개
상속의 문법적 요소를 하나씩 소개해 나간다. 그리고 그 과정에서 앞서 제시한 문제의 해결책을 함께 고민해 나간다.
3단계: 문제의 해결
처음 제시한 문제를, 상속을 적용하여 해결한다.

<h4>상속에 대한 새로운 관점의 이해</h4>
90년대 이후 객체지향의 개념이 확산되어, '상속'에 대한 관점도 많이 달라졌다. 
C++의 상속은 그 단어의 의미처럼 물려 받는다는 성격이 강하다. 

과거 -> 기존에 정의해 놓은 클래스의 재활용을 목적으로 만들어진 문법적 요소가 강하다.

<h4>문제의 제시를 위한 시나리오의 도입</h4>
OrangeMedia라는 회사가 운영하는 '급여관리 시스템'이다. 시스템이 도입시기상 직원의 근무 형태는 정규직(Permanent)였다. 

PermanentWorker 클래스 정의
정규직 직원을 관리하기 위한 형태
EmployeeHandler 클래스 정의
PermanentWorker 클래스 객체 저장 및 관리하기 위한 클래스

7-1/EmployManager1.cpp <파일 참조>
PermanentWorker - 데이터 클래스
EmployeeHandler - 기능 클래스

- 새로운 직원정보의 등록                AddEmployee
- 모든 직원의 이번 달 급여정보 출력      ShowAllSalaryInfo
- 이번 달 급여의 총액 출력              ShoTotalSalary
기능의 처리를 실제로 담당하는 클래스를 컨트롤(control)클래스 또는 핸들러(handler) 클래스라 부른다.

<참고 컨트롤 클래스> 
프로그램이 어떠한 기능을 제공하는지 구체적으로 알 수 있고, 기능 제공의 핵심으로 모든 객체지향 프로그램에서 반드시 존재하는 클래스이다.

소프트웨어의 설계에서 중요시 하는 것
1. 요구사항 변경에 대응하는 프로그램의 유연성
2. 기능의 추가에 따른 프로그램의 확정성

-> 기능 변경시 프로그램을 처음부터 다시 만들어야 한다면 잘못된 프로그램임

<h4>문제의 제시</h4>
회사가 번창하여, <b>b부서가 세분화</b>되었고 직원도 늘어났으며, 고용형태가 조금 다양해졌다.

기존 고용 형태
- 정규직
추가 고용 형태
- 영업직(Sales)         조금 특화된 형태의 고용직, 인센티브 개념이 도입
- 임시직(Temporary)     학생들을 대상으로 하는 임시고용 형태, 아르바이트 느낌

급여 지급 방식
- 고용직 급여           연봉제! 따라서 매달의 급여가 정해짐
- 영업직 급여           기본급여 + 인센티브
- 임시직 급여           시간당 급여 x 일한 시간

문제 해결?
SalesMan클래스와 Temporary 클래스를 추가

EmployeeHandler 클래스의 변경
SalesMan 객체와 Temporary 객체의 저장을 위한 배열을 두 개 추가, 정수형 변수도 맴버 추가
AddEmployee 함수는 SalesMan객체용과 Temporary 객체용 추가, 급여정보를 출력하는 부분도 추가해야함
-> 결국 다 바꿔야함
확장성 문제라 칭함

# 7-2 상속의 문법적인 이해
<h4>상속이란?</h4>
상속 = 재산의 상속? -> 사람의 좋은 품성이나 특성도 상속임
철수는 아버지로부터 좋은 목소리와 큰 키를 물려받았다(상속받았다).

철수는 자신이 지니고 있는 고유의 특성 이외에 아버지로부터 물려 받은 좋은 목소리와 큰 키라는 또 다른 특성을 함께 지니게 되었다.

<h4>상속의 방법과 그 결과</h4>
Person클래스와 Person을 상속받은 UnivStudent
class Person
{
private:
    int age;        //나이
    char name[50];  //이름
public:
    Person(int myage, char * myname) : age(myage)
    {
        strcpy(name, myname);
    }
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
    void HowOldAreYou() const
    {
        cout << "I'm " << age << " years old << endl;
    }
};

class UnivStudent : public Person      // Person 클래스의 상속을 의미
{
private:
    char major[50]; // 전공 과목
public:
    UnivStudent(char * myname, int myage, char * mymajor)
        : Person(myage, myname);
    {
        strcpy(major, mymajor);
    }
    void WhoAreYou() const
    {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;>>>>>>>
    }
};

<h4>상속받은 클래스의 생성자 정의</h4>
UnivStudent(char * myname, int myage, char * mymajor)
    : Person(myage, myname);
{
    strcpy(major, mymajor);
}

<h4>상속관련 완전한 예제의 확인 및 실행</h4>
7-2/UnivStudentInheri.cpp <파일 참고>

private Person으로 상속받으면 맴버 변수 age와 name에 접근이 가능할까?
1. 접근제한이 객체를 기준으로 결정          맴버 변수 접근 가능
2. 접근제한이 클래스를 기준으로 결정        맴버 변수 접근 불가능
정답 2 --> Person 클래스에 정의된 public 함수를 통해 간접적 접근을 해야하고 '정보의 은닉'은 하나의 객체 내에서도 진행 가능

<h4>용어의 정리 </h4>
|Person|UnivStudent|
|----|----|
|상위 클래스|하위 클래스|
|기초 (base)클래스|유도(derived)클래스|
|슈퍼(super) 클래스|서브(sub) 클래스|
|부모 클래스|자식 클래스|

책에선 기초 (base)클래스와 유도(derived)클래스를 사용할 예정

<h4>유도 클래스의 객체 생성과정</h4>
유도 클래스의 객체 생성과정은 매우 중요하므로 다음 예시를 통해 정확히 이해하셈
(기초 클래스의 생성자 호출부분을 중시적으로 볼 것)
7-2/DerivCreOrder.cpp <파일 참고>

알아야하는 2가지 정보
- 유도 클래스의 객체생성 과정에서 기초 클래스의 생성자는 100% 호출된다.
- 유도 클래스의 생성자에서 기초 클래스의 생성자 호출을 명시하지 않으면, 기초 클래스의 void 생성자가 호출된다.

클래스의 맴버는 해당 클래스의 생성자를 통해서 초기화해야 한다.(유도 클래스의 객체 생성과정에서도 지키셈!)

<h4>유도 클래스 객체의 소멸과정</h4>
유도 클래스의 객체 생성과정시 생성자가 두 번 호출 됨을 알음 -> 객체 소멸과정에서 소멸자 두 번 호출
7-2/DerivDestOrder.cpp <파일 참고>

<알 수 있는 사실>
1. 유도 클래스의 객체가 소멸될 때는, 유도 클래스의 소멸자가 실행되고 난 다음의 기초 클래스의 소멸자가 실행된다.
2. 스택에 생성된 객체의 소멸순서는 생성순서와 반대이다.
-> 생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제한다.

7-2/DestModel.cpp <파일 참고>
-> 각자 자기 부분 해제하면 됨

# 7-3 protected 선언과 세 가지 형태의 상속
<h4>protected로 선언된 맴버가 허용하는 접근의 범위</h4>
C++ 접근제어 지시자에는 private, protected, public가 존재하는데 허용 접근 범위는
private < protected < public
protected와 private는 매우 유사하다.

Class Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
    void ShowData()
    {
        cout << num1 << ", " << num2 << ", " << num3;
    }
};
private와 protected 둘 다 클래스의 외부에서는 접근이 불가능하고, 내부에서는 접근이 가능하다.
상속이 되면

Class Derived : public Base
{
public:
    void ShowBaseMember()
    {
        cout << num1;   // 컴파일 에러
        cout << num2;   // 컴파일 OK!
        cout << num3;   // 컴파일 OK!
    }
};
-> protected로 선언된 맴버변수는 이를 상속하는 유도 클래스에서 접근이 가능합니다.
private와 protected의 유일한 차이점!!!!

유도클래스에게만 제한적으로 접근이 허용한다는 측면에서 유용한 키워드지만, 기본적으로 기초 클래스와 이를 상속하는 유도 클래스 사이에서도 '정보은닉'은 지켜지는 게 좋다.

<h4>세가지 형태의 상속</h4>
class Derived : public Base
{
    .....
}
class Derived : protected Base
{
    .....
}
class Derived : private Base
{
    .....
}

<h4>protected 상속</h4>
Class Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
};

class Derived : protected Base
{
    //empty
}
-> protected보다 접근의 범위가 넓은 맴버는 protected로 변경시켜서 상속하겠다.
class Derived : protected Base
{
접근불가:
    int num1;
protected:
    int num2;
protected:
    int num3;
};

7-3/ProtectedHeri.cpp <파일 참조>

<h4>private 상속</h4>
Class Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
};

class Derived : private Base
{
    //empty
}
-> private보다 접근의 범위가 넓은 맴버는 private로 변경시켜서 상속하겠다.
class Derived : private Base
{
접근불가:
    int num1;
private:
    int num2;
private:
    int num3;
};
class DeDerived : public Derived
{
접근불가:
    int num1;
접근불가:
    int num2;
접근불가:
    int num3;
};

7-3/PrivateHeri.cpp <파일 참조>

<h4>public 상속</h4>
Class Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
};

class Derived : public Base
{
    //empty
}
-> public보다 접근의 범위가 넓은 맴버는 public으로 변경시켜서 상속하겠다.
-> private을 제외한 나머지는 그냥 그대로 상속한다.
-> C++의 상속은 public 상속만 있다고 생각하셈(의미 파악하기)

7-3/PublicHeri.cpp <파일 참조>

# 7-4 상속을 위한 조건
<h4>상속을 위한 기본 조건인 IS-A 관계의 성립</h4>
유도 클래스는 기초 클래스가 지니는 모든 것을 지니고, 유도 클래스만의 추가적인 특성이 더해진다.

전화기 -> 무선 전화기
컴퓨터 -> 노트북 컴퓨터

무선 전화기는 is a 전화기
노트북 컴퓨터 is a 컴퓨터
is a(일종의 ~이다.)

만약 is a로 표현되지 않는다면, 관계가 아닐 확률이 높음

7-4/ISAInheritance.cpp <파일 참고>
NotebookComp is a Computer.
TableNotebook is a NotebookComp
-> TableNotebook is a Computer

computer <- NotebookComp <- TableNotebook
UNL에서 상속 표현

<h4>HAS-A관계도 상속의 조건은 되지만 복합 관계로 이를 대신하는 것이 일반적이다.</h4>
소유의 관계일시 상속 가능. 유도클래스는 기초 클래스가 지니고 있는 모든 것을 소유한다. 상속이 아닌 다른 방식으로 표현하고 있다.
7-4/HASInheritance.cpp <파일 참고>

경찰 has a 총(has a ~을 소유한다.)
HAS-A 관계 또한 상속으로 표현 가능하다.

다른 방식의 표현
7-4/HASComposite.cpp <파일 참고>
HASInheritance는 아래 2개를 반영하기 쉽지 않다.
1. 권총을 소유하지 않은 경찰을 표현해야 합니다.
2. 경찰이 권총과 수갑뿐만 아니라, 전기봉도 소유하기 시작했습니다.

상속은 IS-A관계의 표현에 매우 적절하다. 경우에 따라 HAS-A관계에도 사용되나, 많은 제약이 생김
봉을 상속받은 총은 봉총? ㅋㅋ

