#include <iostream>
#include <stdlib.h>
using namespace std;


struct Account_Info{
    int accountId;
    char name[20];
    int depoisitMoney;
};

struct Account_Info info[20];
int cnt;

void MakeAccount()
{
    int num;
    cout << "[Account Make]\n";
    cout << "Account ID: ";
    cin >> info[cnt].accountId;
    cout << "Name";
    cin >> info[cnt].name;
    cout << "account total";
    cin >> info[cnt].depoisitMoney;
    cnt++;
}

void DepositAccount()
{
    int num;
    cout << "[Account Deposit]\n";
    cout << "Account ID: ";
    cin >> num;
    int id;
    for (int i = 0 ; i < cnt ; i++)
    {
        if (num == info[i].accountId){
            id = i;
            break;
        }
    }
    cout << "Deposit amount";
    cin >> num;
    info[id].depoisitMoney += num;
    cout << "Deposit Complete\n";
}

void WithdrawAccount()
{
    int num;
    cout << "[Account Withdraw]\n";
    cout << "Account ID: ";
    cin >> num;
    int id;
    for (int i = 0 ; i < cnt ; i++)
    {
        if (num == info[i].accountId){
            id = i;
            break;
        }
    }
    cout << "Withdraw amount";
    cin >> num;
    info[id].depoisitMoney -= num;
    cout << "Withdraw Complete\n";
}
void PrintAccount()
{
    for (int i = 0 ; i < cnt ; i++)
    {
        cout << "ID: " << info[i].accountId << '\n';
        cout << "name: " << info[i].name << '\n';
        cout << "Money: " << info[i].depoisitMoney << '\n';
    }
}
int main(void)
{
	
    int num;
    int cnt = 0;
    while (true){
        cout << "-----Menu-----\n";
        cout << "1. make account\n";
        cout << "2. deposit\n";
        cout << "3. withdraw\n";
        cout << "4. account info print\n";
        cout << "5. exit\n";
        cout << "select : ";
        cin >> num;
        
        switch (num)
        {
            case 1:
                MakeAccount();
                break;
            case 2:
                DepositAccount();
                break;
            case 3:
                WithdrawAccount();
                break;
            case 4:
                PrintAccount();
                break;
            case 5:
                exit(0);
                break;
        }
    } 
}