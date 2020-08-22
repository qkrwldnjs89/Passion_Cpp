#include <iostream>
#include "AddressStruct.h"
#include "func.h"

using namespace std;
const int ARR_LEN = 20;

int main(void) 
{
	AddressStruct clientArr[ARR_LEN];
	int iptCnt = 0;
	
	while (1)
	{
		int option;
		PrintMenu();
		cin>>option;
		switch (option)
		{
			case 1:
				CreateAddress(clientArr, &iptCnt);
				break;
			case 2:
				Deposit(clientArr, ARR_LEN);
				break;
			case 3:
				Withdraw(clientArr, ARR_LEN);
				break;
			case 4:
				PrintAll(clientArr, iptCnt);
				break;
			case 5:
				cout<<"���α׷� ����"<<endl;
				return 0;
			default:
				cout<<"�ɼ� �Է� ����"<<endl;
		}
	}
	return 0;
}
