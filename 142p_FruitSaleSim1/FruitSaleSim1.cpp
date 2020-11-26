#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
	
public:
	void InitMembers(int price, int num)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = 0;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += (num * APPLE_PRICE);
		return num;
	}
	void ShowSalesResult()
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
	int ReturnAPPLE_PRICE()
	{
		return APPLE_PRICE;
	}
};

class FruitBuyer
{
	int myMoney;		//private
	int numOfApples;	//private
	
public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		int org = numOfApples;
		numOfApples += seller.SaleApples(money);		
		myMoney -= ( seller.ReturnAPPLE_PRICE() * (numOfApples - org) ); 
	}
	void ShowBuyResult()
	{
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2450);
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
