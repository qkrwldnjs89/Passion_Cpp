#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

/* 위의 함수를 SwapByRef2(23, 45) 의 형태로 호출 시 컴파일 에러가 발생한다.
그 이유는?

Answ: 참조자는 변수에 대하여만 선언이 가능하기 때문이다.
		함수가 호출될 때 매개변수도 선언과 동시에 초기화가 되는데,
		int &ref1 = 23; 은 잘못된 문법이기 때문이다. 
