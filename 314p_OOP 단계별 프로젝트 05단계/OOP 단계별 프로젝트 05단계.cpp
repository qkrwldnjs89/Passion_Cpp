#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN       = 20;

namespace OPTION {enum {MAKE = 1, DEPOSIT, WITHDRAW, PRINTALL, TERMINATE};}

// entity class
class Account
{
private:
    int accID;
    char * name;
    int balance;
public:
    Account(int accID, const char * pName, int balance);
    Account(const Account& copy);
    int GetAccID() const;
    void Deposit();
    void Withdraw();
    void PrintInfo() const;
    ~Account();
};

Account::Account(int accID, const char * pName, int balance)
    : accID(accID), balance(balance)
{
    name = new char[strlen(pName) + 1];
    strcpy(name, pName);
}
Account::Account(const Account& copy)
    : accID(copy.accID), balance(copy.balance)
{
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name);
}
int Account::GetAccID() const
{
    return accID;
}
void Account::Deposit()
{
    int money;
    cout << "입금액: "; cin >> money;
    balance += money;
    cout << "입금완료" << endl;
}
void Account::Withdraw()
{
    int money;
    cout << "출금액: "; cin >> money;
    balance -= money;
    cout << "출금완료" << endl;
}
void Account::PrintInfo() const
{
    cout << "계좌 ID: " << accID << endl;
    cout << "이 름: " << name << endl;
    cout << "잔 액: " << balance << endl << endl;
}
Account::~Account()
{
    delete []name;
}


class AccountHandler
{
private:
    Account* accArr[100];
    int accNum;
public:
    AccountHandler();
    int ShowMenu();
    void MakeAccount();
    void Deposit();
    void Withdraw();
    void PrintAll();
    ~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0)
{ }
int AccountHandler::ShowMenu()
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

void AccountHandler::MakeAccount()
{
    int accID;
    char name[50];
    int money;

    cout << "[ 계 좌 개 설 ]" << endl;
    cout << "계좌 ID: "; cin >> accID; 
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> money;
    accArr[accNum++] = new Account(accID, name, money);
}

void AccountHandler::Deposit()
{
    int accID;
    cout << "[ 입  금 ]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            accArr[i]->Deposit();
            return;
        }
    }
    cout << "계좌가 없습니다." << endl;
}
void AccountHandler::Withdraw()
{
    int accID;
    cout << "[ 출  금 ]" << endl;
    cout << "계좌 ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            accArr[i]->Withdraw();
            return;
        }
    }
    cout << "계좌가 없습니다." << endl;
}
void AccountHandler::PrintAll()
{
    cout << "[ 출  력 ]" << endl;
    for (int i = 0; i < accNum; i++)
        accArr[i]->PrintInfo();
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)    
        delete accArr[i];
}

int main(void)
{
    AccountHandler accHandler;
    while (1)
    {
        switch(accHandler.ShowMenu())
        {
            case OPTION::MAKE:
                accHandler.MakeAccount();
                break;
            case OPTION::DEPOSIT:
                accHandler.Deposit();
                break;
            case OPTION::WITHDRAW:
                accHandler.Withdraw();
                break;
            case OPTION::PRINTALL:
                accHandler.PrintAll();
                break;
            case OPTION::TERMINATE:
                cout << "프로그램 종료" << endl;
                return 0;
            default:
                cout << "잘못된 옵션 입력" << endl;
        }
    }
    return 0;
}