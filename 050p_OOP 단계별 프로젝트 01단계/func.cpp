#include <iostream>
#include "AddressStruct.h"

using namespace std;

void PrintMenu(void)
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. 개좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	cout<<"선택: ";
}

void CreateAddress(AddressStruct arr[], int * iptCnt)
{
	cout<<"[ 계좌개설 ]"<<endl;
	cout<<"계좌를 입력하세요: ";
	cin>>arr[*iptCnt].address;
	cout<<"이름을 입력하세요: ";
	cin>>arr[*iptCnt].name;
	cout<<"입금액을 입력하세요: ";
	cin>>arr[*iptCnt].balance;
	(*iptCnt)++;
}

void Deposit(AddressStruct arr[], int size)
{
	int id;
	int money;
	cout<<"[ 입금 ]"<<endl;
	cout<<"계좌 ID: ";
	cin>>id;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].address == id)
		{
			cout<<"입금액: ";
			cin>>money;
			arr[i].balance += money;
			return;
		}
	}
	
	cout<<"찾지 못했습니다"<<endl;
}

void Withdraw(AddressStruct arr[], int size)
{
	int id;
	int money;
	cout<<"[ 출금 ]"<<endl;
	cout<<"계좌 ID: ";
	cin>>id;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].address == id)
		{
			cout<<"출금액: ";
			cin>>money;
			arr[i].balance -= money;
			return;
		}
	}
	
	cout<<"찾지 못했습니다."<<endl;
}

void PrintAll(AddressStruct arr[], int personNum)
{
	cout<<"[ 출력 ]"<<endl;
	for (int i = 0; i < personNum; i++)
	{
		cout<<i+1<<"번째"<<endl; 
		cout<<"계좌 ID: "<<arr[i].address<<endl;
		cout<<"이 름: "<<arr[i].name<<endl;
		cout<<"잔 액: "<<arr[i].balance<<endl<<endl; 
	}
}

