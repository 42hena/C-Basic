/*
문제 설명
프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성해 보자.
*/
#include <iostream>
using namespace std;
int main(void)
{
    char name[20];
    char phoneNumber[20];
    cout << "Name : ";
    cin >> name;
    cout << "output Name: " << name << '\n';
    cout << "PhoneNumber : ";
    cin >> phoneNumber;
    cout << "output Phone: " << phoneNumber << '\n';
}