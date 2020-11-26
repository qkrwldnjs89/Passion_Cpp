#include <iostream>
using namespace std;

class Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;

    Base() : num1(1), num2(2), num3(3) { }
};

class Derived : protected Base { };

int main(void)
{
    Derived drv;
    // cout << drv.num3 << endl; 
    // 컴파일 에러, class Derived 에 Base 를 protected 로 상속하였기 때문에 public이었던 num3 는 Derived 에서 protected 가 되어 클래스 외에서 접근 불가
    return 0;
}