#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = "str1+str2";

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1+=str2;
    if (str1 == str3)
        cout << "same string!" << endl;
    else
        cout << "not same string!" << endl;

    string str4;
    cout << "input string: ";
    cin >> str4;
    cout << "my input string: " << str4 << endl;
    return 0;
}