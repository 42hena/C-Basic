#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    if (num2 == 0)
        throw num2;
    cout << "share of division: " << num1 / num2 << endl;
    cout << "remainder of division: " << num1 % num2 << endl;
}

int main(void)
{
    int num1, num2;
    cout << "Two Integer Input: ";
    cin >> num1 >> num2;

    try
    {
        Divide(num1, num2);
        cout << "Divide finished." << endl;
    }
    catch(int expn)
    {
        cout << "divisor is can't be " << expn << endl;
        cout << "Please, restart program" << endl;
    }
    return 0;
}