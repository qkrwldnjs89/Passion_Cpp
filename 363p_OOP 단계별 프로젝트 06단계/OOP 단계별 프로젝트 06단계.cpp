#include <iostream>
#include <cstring>
using namespace std;

namespace OPTION {enum {MAKE = 1, DEPOSIT, WITHDRAW, PRINTALL, TERMINATE};}
namespace KIND{enum {NORMAL = 1, HIGHCREDIT};}
namespace GRADE{enum {A = 1, B, C};}
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
    virtual int GetRate() const = 0;
    virtual void Deposit(int money, int rate);
    bool Withdraw(int money);
    virtual void PrintInfo() const;
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
int Account::GetAccID() const {return accID;}
void Account::Deposit(int money, int rate)
{
    balance += money;
    balance *= (1 + (rate / double(100)));
}
bool Account::Withdraw(int money)
{
    if (money > balance)
    {
        cout << "잔고가 " << balance << "원 뿐입니다. 더 작은 값을 입력하세요." << endl;
        return false;
    }
    else
    {
        balance -= money;
        return true;
    }
}
void Account::PrintInfo() const
{
    cout << "계좌 ID: " << accID << endl;
    cout << "이 름: " << name << endl;
    cout << "잔 액: " << balance << endl;
}
Account::~Account()
{
    delete []name;
}

class NormalAccount : public Account
{
private:
    int rate;
public:
    NormalAccount(int accID, const char* pName, int balance, int rate);
    virtual int GetRate() const;
    virtual void Deposit(int money, int rate);
    virtual void PrintInfo() const;
};

NormalAccount::NormalAccount(int accID, const char* pName, int balance, int rate)
    : Account(accID, pName, balance), rate(rate)
    { }
int NormalAccount::GetRate() const {return rate;}
void NormalAccount::Deposit(int money, int rate)
{
    Account::Deposit(money, rate);
}
void NormalAccount::PrintInfo() const
{
    cout << "계좌 종류: 보통예금계좌" << endl; 
    Account::PrintInfo();
    cout << "이자율: " << rate << endl << endl;
}

class HighCreditAccount : public Account
{
private:
    int grade;
    int rate;
public:
    HighCreditAccount(int accID, const char* pName, int balance, int grade);
    virtual int GetRate() const;
    virtual void Deposit(int money, int rate);
    virtual void PrintInfo() const;
};
HighCreditAccount::HighCreditAccount(int accID, const char* pName, int balance, int grade)
    : Account(accID, pName, balance), grade(grade)
{
    switch (grade)
    {
        case GRADE::A: rate = 7; break;
        case GRADE::B: rate = 4; break;
        case GRADE::C: rate = 2; break;
        default: exit(1);
    }
}
int HighCreditAccount::GetRate() const
{
    return rate;
}
void HighCreditAccount::Deposit(int money, int rate)
{
    Account::Deposit(money, rate);
}
void HighCreditAccount::PrintInfo() const
{
    cout << "계좌 종류: 신용신뢰계좌" << endl;
    Account::PrintInfo();
    cout << "회원 등급: ";
    switch (grade)
    {
        case GRADE::A:
            cout << "A(이자 7%)" << endl << endl; break;
        case GRADE::B:
            cout << "B(이자 4%)" << endl << endl; break;
        case GRADE::C:
            cout << "C(이자 2%)" << endl << endl; break;
        default:
            exit(1);
    }
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
    int kind;
    int accID, money, grade, rate;
    char name[50];
    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
    cout << "선택: "; cin >> kind;
    switch(kind)
    {
        case KIND::NORMAL:
            cout << "[보통예금계좌 개설]" << endl;
            cout << "계좌 ID: "; cin >> accID; 
            cout << "이 름: "; cin >> name;
            cout << "입금액: "; cin >> money;
            cout << "이자율: "; cin >> rate;
            accArr[accNum++] = new NormalAccount(accID, name, money, rate);
            break;
        case KIND::HIGHCREDIT:
            cout << "[신용신뢰계좌 개설]" << endl;
            cout << "계좌 ID: "; cin >> accID; 
            cout << "이 름: "; cin >> name;
            cout << "입금액: "; cin >> money;
            cout << "회원 등급(1toA, 2toB, 3toC): "; cin >> grade;
            accArr[accNum++] = new HighCreditAccount(accID, name, money, grade);
            break;
        default:
            exit(1);
    }
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
            int money;
            cout << "입금액: "; cin >> money;
            accArr[i]->Deposit(money, accArr[i]->GetRate());
            cout << "입금완료" << endl;
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
            int money;
            cout << "출금액: "; cin >> money; 
            if (accArr[i]->Withdraw(money))
                cout << "출금 완료" << endl;
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