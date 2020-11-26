#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;
public:
    SelfRef(int n) : num(n)
    {
        cout << "객체생성" << endl;
    }
    SelfRef& Adder(int n)
    {
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }
    /* 위의 함수들을 const 로 바꿀 수 없는 이유는
    const 는 해당 객체의 속성을 해당 함수 내에서 const 로 만들어버리기 때문이고,
    난 아무것도 안건드릴 거지만 다른놈한텐 마음대로 건드릴 수 있게 줄게! 라는 의미의 함수가 된다.
    */
};

int main(void)
{
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    return 0;
}