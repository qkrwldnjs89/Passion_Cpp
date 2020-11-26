#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
	
public:
	bool InitMembers(const int price, const int num)
	{
		if ( (price < 0) || (num < 0) )
		{
			cout<<"잘못된 값을 전달. 초기화 실패!"<<endl;
			return false;
		}	
		
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = 0;
		return true;
	}
	int SaleApples(const int money)
	{
		if (money < 0)
		{
			cout<<"잘못된 값을 전달. 초기화 실패!"<<endl;
			return -1;
		}
		
		int	num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += (num * APPLE_PRICE);
		return num;
	}
	void ShowSalesResult() const
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
	int ReturnAPPLE_PRICE() const
	{
		return APPLE_PRICE;
	}
};

class FruitBuyer
{
	int myMoney;		//private
	int numOfApples;	//private
	
public:
	bool InitMembers(const int money)
	{
		if (money < 0)
		{
			cout<<"잘못된 값을 전달. 초기화 실패!"<<endl;
			return false;
		}
		myMoney = money;
		numOfApples = 0;
		return true;
	}
	bool BuyApples(FruitSeller &seller, const int money)
	{
		if (money < 0)
		{
			cout<<"잘못된 값을 전달. 초기화 실패!"<<endl;
			return false;
		}
		
		int org = numOfApples;
		numOfApples += seller.SaleApples(money);		
		myMoney -= ( seller.ReturnAPPLE_PRICE() * (numOfApples - org) ); 
		return true;
	}
	void ShowBuyResult() const
	{
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	
	while (1)
	{
		int applePrice, appleNum;
		cout<<"사과 가격: "; cin>>applePrice;
		cout<<"사과 수: "; cin>>appleNum;
		if (seller.InitMembers(applePrice, appleNum))
			break;
	}
	
	FruitBuyer buyer;
	while (1)
	{
		int money;
		cout<<"구매자가 보유한 돈: "; cin>>money;
		if (buyer.InitMembers(money))
			break;
	}
	while (1)
	{
		int money;
		cout<<"사과를 구매하는데 쓸 돈: "; cin>>money;
		if (buyer.BuyApples(seller, money))
			break;
	}
	
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
