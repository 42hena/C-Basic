#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
public:
    Simple()
    {
        cout << "I'm simple constructor!" << endl;
    }
};

int main(void)
{
    cout << "case 1: ";
    Simple * sp1 = new Simple;

    cout << "case 2: "; 
    Simple * sp2 = (Simple *)malloc(sizeof(Simple) * 1);

    cout << endl << "end of main" << endl;
    delete sp1;
    free(sp2);
    return 0;
}
/*
해설
5~12행: 아직은 클래스를 모르니, 이를 그저 C언어의 구조체라고 생각하기 바란다. 즉, 프로그래머가 직접 정의한 자료형으로 인식하기 바란다.
17행: 5행에 정의되어 있는 자료형을 근거로, new 연산자를 이용해서 힙 영역에 변수를 할당하고 있다.
20행: 5행에 정의되어 있는 자료형을 근거로, malloc 함수호출을 통해서 힙 영역에 변수를 할당하고 있다.
23, 24행: 할당방법에 따른 소멸을 진행하고 있다.

실행 결과
case 1: I'm simple constructor!
case 2:
end of main
*/