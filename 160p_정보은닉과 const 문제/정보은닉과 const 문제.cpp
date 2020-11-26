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
			cout<<"�߸��� ���� ����. �ʱ�ȭ ����!"<<endl;
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
			cout<<"�߸��� ���� ����. �ʱ�ȭ ����!"<<endl;
			return -1;
		}
		
		int	num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += (num * APPLE_PRICE);
		return num;
	}
	void ShowSalesResult() const
	{
		cout<<"���� ���: "<<numOfApples<<endl;
		cout<<"�Ǹ� ����: "<<myMoney<<endl<<endl;
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
			cout<<"�߸��� ���� ����. �ʱ�ȭ ����!"<<endl;
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
			cout<<"�߸��� ���� ����. �ʱ�ȭ ����!"<<endl;
			return false;
		}
		
		int org = numOfApples;
		numOfApples += seller.SaleApples(money);		
		myMoney -= ( seller.ReturnAPPLE_PRICE() * (numOfApples - org) ); 
		return true;
	}
	void ShowBuyResult() const
	{
		cout<<"���� �ܾ�: "<<myMoney<<endl;
		cout<<"��� ����: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	
	while (1)
	{
		int applePrice, appleNum;
		cout<<"��� ����: "; cin>>applePrice;
		cout<<"��� ��: "; cin>>appleNum;
		if (seller.InitMembers(applePrice, appleNum))
			break;
	}
	
	FruitBuyer buyer;
	while (1)
	{
		int money;
		cout<<"�����ڰ� ������ ��: "; cin>>money;
		if (buyer.InitMembers(money))
			break;
	}
	while (1)
	{
		int money;
		cout<<"����� �����ϴµ� �� ��: "; cin>>money;
		if (buyer.BuyApples(seller, money))
			break;
	}
	
	
	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
