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
		cout<<"���� ���: "<<numOfApples<<endl;
		cout<<"�Ǹ� ����: "<<myMoney<<endl<<endl;
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
		cout<<"���� �ܾ�: "<<myMoney<<endl;
		cout<<"��� ����: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2450);
	
	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
