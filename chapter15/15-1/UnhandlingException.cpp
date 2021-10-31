#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Two Integer Input: ";
    cin >> num1 >> num2;

    cout << "share of division: " << num1 / num2 << endl;
    cout << "remainder of division: " << num1 % num2 << endl;
    return 0;
}