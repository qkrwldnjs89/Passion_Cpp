#include <iostream>

int main(void)
{
	char name[20];
	char phoneNum[20];
	
	std::cout<<"이름: ";
	std::cin>>name;
	
	std::cout<<"전화번호: ";
	std::cin>>phoneNum;
	
	std::cout<<"입력된 이름: "<<name<<std::endl;
	std::cout<<"입력된 전화번호: "<<phoneNum<<std::endl; 
	return 0;
}
