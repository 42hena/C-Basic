#include <iostream>
#include <new>
using namespace std;

int main(void)
{
    int num = 0;

    try
    {
        while (1)
        {
            num++;
            cout << num << "alloc try" << endl;
            new int[10000][10000];
        }
    }
    catch(bad_alloc &bad)
    {
        cout << bad.what() << endl;
        cout << "cant alloc" << endl;
    }
    return 0;
}