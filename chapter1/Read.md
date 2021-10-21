# 1-1 printf와 scanf를 대신하는 입출력 방식

관찰결과 1: 헤더파일 선언문 #include <iostream>
헤더파일 확장자는 C언어와 마찬가지로 .h이다. C++에서 프로그래머가 정의하는 헤더파일의 선언이 아닌, 표준 헤더파일의 선언에서는 확장자를 생략하기로 약속되어 있다.

# 참고
새로운 라이브러리 등장
#include <iostream.h>와 같은 헤더파일이 있었으나
1. 과거의 표준 라이브러리와 새로운 표준 라이브러리의 구분
2. 새로운 표준 라이브러리를 사용하는 형태로 소스코드를 쉽게 변경할 수 있게 함
와 같은 이유로 지원하지 않음

관찰결과 2: std::cout과 << 연산자를 이용한 출력
std::cout<< '출력대상';
출력 대상의 위치에는 무엇이든 올 수 있다.(정수, 실수, 문자열, 변수)

관찰결과 3: << 연산자를 이용한 출력 대상의 연이은 표현과 개행
<< 도 사실 연산자이고,
std::cout << '출력대상' << '출력대상2' << '출력대상3';
과 같이 연속으로 출력 가능하다


SimpleAdder.cpp
관찰결과 1: 데이터의 입력에 사용되는 std::cin과 >> 연산자
std::cout<< '변수';

c++에서는 데이터의 입력도 데이터의 출력과 마찬가지로 별도의 포맷 지정이 필요 없기 때문에 출력 가능

관찰결과2: C++의 지역변수 선언
BetweenAdder.cpp확인


# 1-2 함수 오버로딩(Function Overloading)
함수 오버로딩의 이해
c언어에서는 아래와 같이 동일한 이름의 함수가 정의되는 것을 허용하지 않는다
int Myfunc(int num){}
int Myfunc(int a, int b){}
c++에서는 위와 같은 경우를 허용하는데, 함수 오버로딩이라고 한다.

# 차이점
c++에서는 함수의 이름, 매개변수의 선언 두 가지 정보를 동시에 활용한다.
MyFunc(30, 40);의 호출문을 보면 두 개의 int형 정수를 인자로 전단받을 수 있는 MyFunc이름의 함수를 찾는다. 
c언어는 함수 이름만 이용해서 호출 대상을 찾는다.

함수 오버로딩의 예
함수의 오버로딩이 가능하려면 매개변수의 선언이 달라야한다. 예를 들어서 다음 두 함수는 오버로딩이 가능하다.
int MyFunc(char c){}
int MyFunc(int n){}

이 경우는 매개변수의 개수가 다르므로, 전달되는 인자의 개수를 통해서 호출할 함수의 구분이 가능하기 때문이다.
int MyFunc(int n){}
int MyFunc(int n1, int n2){}
 
정리하면 함수의 오버로딩이 가능하려면 "매개변수의 자료형 또는 개수가 다르다"

잘못된 오버로딩의 예
int MyFunc(int n){}
void MyFunc(int n){}
반환형이 다른경우는 컴파일 오류로 이어진다.
FunciotnOverloading.cpp

# 1-3 매개변수의 디폴트 값(Default Value)
int MyFuncOne(int num = 7)
{
    return num + 1;
}

int MyFuncTwo(int num1 = 5, int num2 = 7)
{
    return num1 + num2;
}

MyFuncOne()은 
MyFuncOne(7)과 같은 의미
MyFuncTwo()은
MyFuncTwo(5, 7)과 같은 의미

디폴트 값은 함수의 선언 부분에만 표현하시면 됩니다.

부분적 디폴트 값 설정
반드시 오른쪽 매개변수의 디폴트 값부터 채우는 형태로 정의해야 한다. 즉, 다음의 함수정의는 모두 유효하다.
int YourFUnc(int num1, int num2, int num3){}에서
int YourFUnc(int num1, int num2, int num3=30){}
int YourFUnc(int num1, int num2=20, int num3=30){}
int YourFUnc(int num1=10, int num2=20, int num3=30){}

int YourFUnc(int num1=10, int num2, int num3){} (X)
int YourFUnc(int num1=10, int num2=20, int num3){} (X)

# 중요
오른쪽부터 채울 것을 요구하는 이유는 무엇일까?
함수에 전달되는 인자가 왼쪽에서부터 오른쪽으로 채워지기 때문입니다.
YourFunc(10, 20)// YourFunc(10, 20, 30)?
매개


# 1-4인라인 함수

매크로 함수의 장점
일반적인 함수에 비해서 실행속도의 이점이 있다.
단점
정의하기가 어렵다. 복잡한 함수를 매크로의 형태로 정의하는 데 한계가 있다.

#매크로 함수 vs 인라인 함수수
#define SQUARE(X) ((X)*(X)) 는 데이터 손실이 이뤄지지 않는다
inline int SQUARE(int x) {return x*x;}는 int기반이므로 3.15출력시 손실
해결방법
함수 오버로딩
템플릿 이용

# 1-5 이름 공간