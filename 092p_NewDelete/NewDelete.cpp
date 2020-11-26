#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len)
{
	// char * str = (char *)malloc(sizeof(char) * len); 을 대체
	char * str = new char[len];
	return str; 
}

int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	// free(str) 을 대체
	delete []str; 
	return 0;
}
