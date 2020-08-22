int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}

/*
위의 함수 오버로딩은 문제가 있다. 어떠한 문제가 있는지 설명해보자

첫번째 함수를 main 함수 내에서 호출할 때에
SimpleFunc(); 라고 호출하여도 매개변수의 디폴트 값이 설정되어 있기 떄문에
아무 문제가 없는데, 두번째 함수의 호출방식이 SimpleFunc(); 이므로
두 함수의 호출방식이 같아지게 되어 문제가 생긴다. 

*/
