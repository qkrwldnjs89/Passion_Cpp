#include <iostream>
using namespace std;

class SoSimple
{
private:   
    int num;
public:
    SoSimple(int n) : num(n)
    { }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }
    void ShowData()
    {
        cout << "num: " << num << endl;
    }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7);
    cout << "함수호출 전" << endl;
    SimpleFuncObj(obj); // 매개변수 ob 객체의 복사 생성자 호출
    cout << "함수호출 후" << endl;   
    return 0;
}