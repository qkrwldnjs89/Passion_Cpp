#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;
public:
    SelfRef(int n) : num(n)
    {
        cout << "��ü����" << endl;
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
    /* ���� �Լ����� const �� �ٲ� �� ���� ������
    const �� �ش� ��ü�� �Ӽ��� �ش� �Լ� ������ const �� ���������� �����̰�,
    �� �ƹ��͵� �Ȱǵ帱 ������ �ٸ������� ������� �ǵ帱 �� �ְ� �ٰ�! ��� �ǹ��� �Լ��� �ȴ�.
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