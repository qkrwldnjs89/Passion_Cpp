#include <iostream>
using namespace std;

int main(void)
{
	const int num = 12;
	const int * numPtr = &num;
	const int *(&ptrRef) = numPtr;
	
	cout<<num<<' '<<*numPtr<<' '<<*ptrRef<<endl;
	return 0;
}
