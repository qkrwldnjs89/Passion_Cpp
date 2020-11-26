#include <iostream>
using namespace std;

void AddOne(int &a)
{
	a += 1;
}

void ChangeSign(int &a)
{
	a *= -1;
}

int main(void)
{
	int num = 10;
	cout<<num<<endl;
	
	AddOne(num);
	cout<<num<<endl;
	
	ChangeSign(num);
	cout<<num<<endl;
	return 0;
}
