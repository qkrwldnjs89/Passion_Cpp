#include <iostream>

int main(void)
{
	char name[20];
	char phoneNum[20];
	
	std::cout<<"�̸�: ";
	std::cin>>name;
	
	std::cout<<"��ȭ��ȣ: ";
	std::cin>>phoneNum;
	
	std::cout<<"�Էµ� �̸�: "<<name<<std::endl;
	std::cout<<"�Էµ� ��ȭ��ȣ: "<<phoneNum<<std::endl; 
	return 0;
}
