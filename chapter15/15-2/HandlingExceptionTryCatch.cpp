#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Two Integer Input: ";
    cin >> num1 >> num2;

    try
    {
        if (num2 == 0)
            throw num2;
        cout << "share of division: " << num1 / num2 << endl;
        cout << "remainder of division: " << num1 % num2 << endl;
    }
    catch(int expn)
    {
        cout << "The divisor cannot be " << 0 << endl;
        cout << "Please, restart program." << endl;
    }
    cout << "end of main" << endl;
    return 0;
}