#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

/* ���� �Լ��� SwapByRef2(23, 45) �� ���·� ȣ�� �� ������ ������ �߻��Ѵ�.
�� ������?

Answ: �����ڴ� ������ ���Ͽ��� ������ �����ϱ� �����̴�.
		�Լ��� ȣ��� �� �Ű������� ����� ���ÿ� �ʱ�ȭ�� �Ǵµ�,
		int &ref1 = 23; �� �߸��� �����̱� �����̴�. 
