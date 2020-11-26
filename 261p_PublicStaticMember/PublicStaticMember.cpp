#include <iostream>
using namespace std;

class SoSimple
{
public:
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt = 0;

int main(void)
{
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
    // 아래 형태의 접근은 추천하지 않는다. 클래스 내의 static 변수는 객체 내에 존재하는 것이 아닌데 그와 같은 오해를 불러일으킴
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
    return 0;
}