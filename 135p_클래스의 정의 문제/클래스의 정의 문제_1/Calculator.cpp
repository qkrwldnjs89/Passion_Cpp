#include <iostream>
#include "Calculator.h"
using namespace std;

void Calculator::Init()
{
	plusCnt = 0;
	minCnt = 0;
	mulCnt = 0;
	divCnt = 0;
}
double Calculator::Add(double a, double b)
{
	plusCnt++;
	return (a + b);
}
double Calculator::Min(double a, double b)
{
	minCnt++;
	return (a - b);
}
double Calculator::Mul(double a, double b)
{
	mulCnt++;
	return (a * b);
}
double Calculator::Div(double a, double b)
{
	divCnt++;
	return (a / b);
}
void Calculator::ShowOpCount()
{
	cout<<"����: "<<plusCnt;
	cout<<" ����: "<<minCnt;
	cout<<" ����: "<<mulCnt;
	cout<<" ������: "<<divCnt<<endl<<endl; 
}
