#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    FruitSeller(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += APPLE_PRICE * num;
        return num;
    }
    int GetAPPLE_PRICE() const
    {
        return APPLE_PRICE;
    }
    void ShowSalesResult() const
    {
        cout << "���� ���: " << numOfApples << endl;
        cout << "�Ǹ� ����: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    FruitBuyer(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        int addApples = seller.SaleApples(money);
        numOfApples += addApples;
        myMoney -= addApples * seller.GetAPPLE_PRICE();
    }
    void ShowBuyResult() const
    {
        cout << "���� �ܾ�: " << myMoney << endl;
        cout << "��� ����: " << numOfApples << endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "���� �Ǹ����� ��Ȳ" << endl;
    seller.ShowSalesResult();
    cout << "���� �������� ��Ȳ" << endl;
    buyer.ShowBuyResult();
    return 0;
}