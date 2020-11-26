#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN     20

namespace OPTION
{
    enum {MAKE = 1, DEPOSIT, WITHDRAW, PRINTALL, TERMINATE};
}

class Account
{
private:
    int accID;
    char * name;
    int balance;
public:
    Account(int accID, const char * pName, int balance)
        : accID(accID), balance(balance)
    {
        name = new char[strlen(pName) + 1];
        strcpy(name, pName);
    }
    Account(const Account& copy)
        : accID(copy.accID), balance(copy.balance)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }
    int GetAccID() const
    {
        return accID;
    }
    void Deposit()
    {
        int money;
        cout << "입금액: "; cin >> money;
        balance += money;
        cout << "입금완료" << endl;
    }
    void Withdraw()
    {
        int money;
        cout << "출금액: "; cin >> money;
        balance -= money;
        cout << "출금완료" << endl;
    }
    void PrintInfo()
    {
        cout << "계좌 ID: " << accID << endl;
        cout << "이 름: " << name << endl;
        cout << "잔 액: " << balance << endl << endl;
    }
    ~Account()
    {
        delete []name;
    }
};

int ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void PrintAll(void);

Account * accPtrArr[MAX_LEN];
int accCnt = 0;

int main(void)
{
    while (1)
    {
        switch(ShowMenu())
        {
            case OPTION::MAKE:
                MakeAccount();
                break;
            case OPTION::DEPOSIT:
                Deposit();
                break;
            case OPTION::WITHDRAW:
                Withdraw();
                break;
            case OPTION::PRINTALL:
                PrintAll();
                break;
            case OPTION::TERMINATE:
                for (int i = 0; i < accCnt; i++)
                    delete accPtrArr[i];
                cout << "프로그램 종료" << endl;
                return 0;
            default:
                cout << "잘못된 옵션 입력" << endl;
        }
        
    }
    return 0;
}

int ShowMenu()
{
    int option;

    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: "; cin >> option;
    cout << endl;
    return option;
}

void MakeAccount(void)
{
    int accID;
    char name[50];
    int money;

    cout << "[ 계 좌 개 설 ]" << endl;
    cout << "계좌 ID: "; cin >> accID; 
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> money;
    accPtrArr[accCnt] = new Account(accID, name, money);
    accCnt++;
}

void Deposit(void)
{
    int accID;
    cout << "[ 입  금 ]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    for (int i = 0; i < accCnt; i++)
    {
        if (accPtrArr[i]->GetAccID() == accID)
        {
            accPtrArr[i]->Deposit();
            return;
        }
    }
    cout << "계좌가 없습니다." << endl;
}

void Withdraw(void)
{
    int accID;
    cout << "[ 출  금 ]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    for (int i = 0; i < accCnt; i++)
    {
        if (accPtrArr[i]->GetAccID() == accID)
        {
            accPtrArr[i]->Withdraw();
            return;
        }
    }
    cout << "계좌가 없습니다." << endl;
}

void PrintAll(void)
{
    cout << "[ 출  력 ]" << endl;
    for (int i = 0; i < accCnt; i++)
        accPtrArr[i]->PrintInfo();
}