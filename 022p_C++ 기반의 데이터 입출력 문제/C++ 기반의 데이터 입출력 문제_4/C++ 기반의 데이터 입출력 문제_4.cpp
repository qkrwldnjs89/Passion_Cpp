#include <iostream>

int main(void)
{
	while (1)
	{
		int salesMoney;
		std::cout<<"�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin>>salesMoney;
		if (salesMoney == -1)
		{
			std::cout<<"���α׷��� �����մϴ�."<<std::endl;
			break;
		}
		
		std::cout<<"�̹� �� �޿�: "<<50 + (salesMoney * 0.12)<<"����"<<std::endl; 
	}
	return 0;
}
