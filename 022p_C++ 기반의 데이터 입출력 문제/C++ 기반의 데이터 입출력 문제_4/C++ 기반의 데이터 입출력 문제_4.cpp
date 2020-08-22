#include <iostream>

int main(void)
{
	while (1)
	{
		int salesMoney;
		std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin>>salesMoney;
		if (salesMoney == -1)
		{
			std::cout<<"프로그램을 종료합니다."<<std::endl;
			break;
		}
		
		std::cout<<"이번 달 급여: "<<50 + (salesMoney * 0.12)<<"만원"<<std::endl; 
	}
	return 0;
}
