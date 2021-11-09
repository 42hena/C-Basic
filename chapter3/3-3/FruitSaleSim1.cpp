#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int moeny)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = moeny;
    }
    int SaleApples(int money)
    {
        int num = money/APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult()
    {
        cout << "now apple num: " << numOfApples << endl;
        cout << "sell revenue: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller &seller, int moeny)
    {
        numOfApples += seller.SaleApples(moeny);
        myMoney -= moeny;
    }
    void ShowBuyResult()
    {
        cout << "now change: " << myMoney << endl;
        cout << "apple num: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "Fruit Seller Status" << endl;
    seller.ShowSalesResult();
    cout << "Fruit Purchanser Status" << endl;
    buyer.ShowBuyResult();
    return 0;
}
/*
해설
34, 35행: 클래스 내에서 접근제어 지시자가 생략되었으니, 이 둘은 private으로 간주된다.
45행: 과일장수를 대상으로 과일의 구매를 목적으로 SaleApples 함수를 호출하고 있다.
61행: 이 예제에서 어렵게 느껴질 수 있는 부분이다. BuyApples은 사과의 구매 기능을 담당하는 함수이다. 즉, 이 함수 내에서 사과의 구매가 완성되어야 한다. 그렇다면 사과를 구매하는데 있어서 필요한 것은 두가지가 무엇인가? FruitBuyer 클래스 안에 존재하지 않지만 필요한 것 말이다. 그것은 바로 '구매대상'과 '구매금액'이다. 그래서 이 둘의 정보가 인자로 전달되도록 함수가 정의되었다.

실행 결과
Fruit Seller Status
now apple num: 18
sell revenue: 2000

Fruit Purchanser Status
now change: 3000
apple num: 2
*/