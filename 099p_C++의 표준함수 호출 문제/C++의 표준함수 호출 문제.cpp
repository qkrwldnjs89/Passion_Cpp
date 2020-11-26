#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str1[30];
	char str2[30];
	char str3[60];
	char str4[30];
	
	cout<<"문자열 입력: "; cin>>str1;
	cout<<"덧붙일 문자열 입력: "; cin>>str2;
	
	cout<<"문자열의 길이"<<endl;
	cout<<"첫번째: "<<strlen(str1)<<endl;
	cout<<"두번째: "<<strlen(str2)<<endl;
	
	cout<<"str1 의 뒤에 str2 를 덧붙이면"<<endl;
	strcat(str1, str2);
	cout<<str1<<endl;
	
	cout<<"두 문자열을 이은 문자열을 다른 배열에 복사하면"<<endl;
	strcpy(str3, str1);
	cout<<str3<<endl;
	
	cout<<"str3 과 비교할 문자열 입력: "; cin>>str4;
	bool is_same = !strcmp(str4, str3);
	if (is_same)
		cout<<"두 문자열은 같습니다."<<endl;
	else
		cout<<"두 문자열은 다릅니다."<<endl;
		
	
	return 0;
}
