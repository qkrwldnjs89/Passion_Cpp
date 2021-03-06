#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
}
class NameCard
{
private:
    char *name;
    char *coName;
    char *tel;
    int rank;
public:
    NameCard(const char * paraName, const char * paraCoName, const char * paraTel, const int &paraRank)
            : rank(paraRank)
    {
        name = new char[strlen(paraName) + 1];
        strcpy(name, paraName);
        coName = new char[strlen(paraCoName) + 1];
        strcpy(coName, paraCoName);
        tel = new char[strlen(paraTel) + 1];
        strcpy(tel, paraTel);
    }
    NameCard(const NameCard& copy)
        : rank(copy.rank)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
        coName = new char[strlen(copy.coName) + 1];
        strcpy(coName, copy.coName);
        tel = new char[strlen(copy.tel) + 1];
        strcpy(tel, copy.tel); 
    }
    void ShowNameCardInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << coName << endl;
        cout << "전화번호: " << tel << endl;
        switch(rank)
        {
            case COMP_POS::CLERK:
                cout << "직급: 사원" << endl << endl;
                break;
            case COMP_POS::SENIOR:
                cout << "직급: 주임" << endl << endl;
                break;
            case COMP_POS::ASSIST:
                cout << "직급: 대리" << endl << endl;
                break;
            case COMP_POS::MANAGER:
                cout << "직급: 과장" << endl << endl;
        }
    }
    ~NameCard()
    {
        delete []name;
        delete []coName;
        delete []tel;
        cout << "called destructor" << endl;
    }
};
int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}