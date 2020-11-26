#include <iostream>
using namespace std;

SwapPointer(int *(&pptr1), int *(&pptr2))
{
	int * tmp = pptr1;
	pptr1 = pptr2;
	pptr2 = tmp;
}

int main(void)
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	cout<<"ptr1: "<<ptr1<<' '<<"*ptr1: "<<*ptr1<<endl;
	cout<<"ptr2: "<<ptr2<<' '<<"*ptr2: "<<*ptr2<<endl;
	
	SwapPointer(ptr1, ptr2); //ptr1 과 ptr2 가 가리키는 대상이 바뀌도록 해야 한다

	cout<<"ptr1: "<<ptr1<<' '<<"*ptr1: "<<*ptr1<<endl;
	cout<<"ptr2: "<<ptr2<<' '<<"*ptr2: "<<*ptr2<<endl;
	return 0;
}
