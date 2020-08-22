#include <iostream>
#include "AddressStruct.h"

using namespace std;

void PrintMenu(void)
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
	cout<<"����: ";
}

void CreateAddress(AddressStruct arr[], int * iptCnt)
{
	cout<<"[ ���°��� ]"<<endl;
	cout<<"���¸� �Է��ϼ���: ";
	cin>>arr[*iptCnt].address;
	cout<<"�̸��� �Է��ϼ���: ";
	cin>>arr[*iptCnt].name;
	cout<<"�Աݾ��� �Է��ϼ���: ";
	cin>>arr[*iptCnt].balance;
	(*iptCnt)++;
}

void Deposit(AddressStruct arr[], int size)
{
	int id;
	int money;
	cout<<"[ �Ա� ]"<<endl;
	cout<<"���� ID: ";
	cin>>id;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].address == id)
		{
			cout<<"�Աݾ�: ";
			cin>>money;
			arr[i].balance += money;
			return;
		}
	}
	
	cout<<"ã�� ���߽��ϴ�"<<endl;
}

void Withdraw(AddressStruct arr[], int size)
{
	int id;
	int money;
	cout<<"[ ��� ]"<<endl;
	cout<<"���� ID: ";
	cin>>id;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].address == id)
		{
			cout<<"��ݾ�: ";
			cin>>money;
			arr[i].balance -= money;
			return;
		}
	}
	
	cout<<"ã�� ���߽��ϴ�."<<endl;
}

void PrintAll(AddressStruct arr[], int personNum)
{
	cout<<"[ ��� ]"<<endl;
	for (int i = 0; i < personNum; i++)
	{
		cout<<i+1<<"��°"<<endl; 
		cout<<"���� ID: "<<arr[i].address<<endl;
		cout<<"�� ��: "<<arr[i].name<<endl;
		cout<<"�� ��: "<<arr[i].balance<<endl<<endl; 
	}
}

