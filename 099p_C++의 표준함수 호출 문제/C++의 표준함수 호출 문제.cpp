#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str1[30];
	char str2[30];
	char str3[60];
	char str4[30];
	
	cout<<"���ڿ� �Է�: "; cin>>str1;
	cout<<"������ ���ڿ� �Է�: "; cin>>str2;
	
	cout<<"���ڿ��� ����"<<endl;
	cout<<"ù��°: "<<strlen(str1)<<endl;
	cout<<"�ι�°: "<<strlen(str2)<<endl;
	
	cout<<"str1 �� �ڿ� str2 �� �����̸�"<<endl;
	strcat(str1, str2);
	cout<<str1<<endl;
	
	cout<<"�� ���ڿ��� ���� ���ڿ��� �ٸ� �迭�� �����ϸ�"<<endl;
	strcpy(str3, str1);
	cout<<str3<<endl;
	
	cout<<"str3 �� ���� ���ڿ� �Է�: "; cin>>str4;
	bool is_same = !strcmp(str4, str3);
	if (is_same)
		cout<<"�� ���ڿ��� �����ϴ�."<<endl;
	else
		cout<<"�� ���ڿ��� �ٸ��ϴ�."<<endl;
		
	
	return 0;
}
