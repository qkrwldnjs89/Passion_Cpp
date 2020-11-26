#include <iostream>
#include <cstring>
#include "Printer.h"
using namespace std;

void Printer::SetString(const char * iptStr)
{
	strcpy(str, iptStr);
}
void Printer::ShowString()
{
	cout<<str<<endl;
}

