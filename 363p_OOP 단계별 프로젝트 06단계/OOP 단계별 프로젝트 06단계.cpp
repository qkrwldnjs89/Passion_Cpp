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
        cout << "�ܰ� " << balance << "�� ���Դϴ�. �� ���� ���� �Է��ϼ���." << endl;
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
    cout << "���� ID: " << accID << endl;
    cout << "�� ��: " << name << endl;
    cout << "�� ��: " << balance << endl;
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
    cout << "���� ����: ���뿹�ݰ���" << endl; 
    Account::PrintInfo();
    cout << "������: " << rate << endl << endl;
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
    cout << "���� ����: �ſ�ŷڰ���" << endl;
    Account::PrintInfo();
    cout << "ȸ�� ���: ";
    switch (grade)
    {
        case GRADE::A:
            cout << "A(���� 7%)" << endl << endl; break;
        case GRADE::B:
            cout << "B(���� 4%)" << endl << endl; break;
        case GRADE::C:
            cout << "C(���� 2%)" << endl << endl; break;
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
    cout << "1. ���°���" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
    cout << "����: "; cin >> option;
    cout << endl;
    return option;
}

void AccountHandler::MakeAccount()
{
    int kind;
    int accID, money, grade, rate;
    char name[50];
    cout << "[������������]" << endl;
    cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
    cout << "����: "; cin >> kind;
    switch(kind)
    {
        case KIND::NORMAL:
            cout << "[���뿹�ݰ��� ����]" << endl;
            cout << "���� ID: "; cin >> accID; 
            cout << "�� ��: "; cin >> name;
            cout << "�Աݾ�: "; cin >> money;
            cout << "������: "; cin >> rate;
            accArr[accNum++] = new NormalAccount(accID, name, money, rate);
            break;
        case KIND::HIGHCREDIT:
            cout << "[�ſ�ŷڰ��� ����]" << endl;
            cout << "���� ID: "; cin >> accID; 
            cout << "�� ��: "; cin >> name;
            cout << "�Աݾ�: "; cin >> money;
            cout << "ȸ�� ���(1toA, 2toB, 3toC): "; cin >> grade;
            accArr[accNum++] = new HighCreditAccount(accID, name, money, grade);
            break;
        default:
            exit(1);
    }
}

void AccountHandler::Deposit()
{
    int accID;
    cout << "[ ��  �� ]" << endl;
    cout << "���� ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            int money;
            cout << "�Աݾ�: "; cin >> money;
            accArr[i]->Deposit(money, accArr[i]->GetRate());
            cout << "�ԱݿϷ�" << endl;
            return;
        }
    }
    cout << "���°� �����ϴ�." << endl;
}
void AccountHandler::Withdraw()
{
    int accID;
    cout << "[ ��  �� ]" << endl;
    cout << "���� ID: "; cin >> accID;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == accID)
        {
            int money;
            cout << "��ݾ�: "; cin >> money; 
            if (accArr[i]->Withdraw(money))
                cout << "��� �Ϸ�" << endl;
            return;
        }
    }
    cout << "���°� �����ϴ�." << endl;
}
void AccountHandler::PrintAll()
{
    cout << "[ ��  �� ]" << endl;
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
                cout << "���α׷� ����" << endl;
                return 0;
            default:
                cout << "�߸��� �ɼ� �Է�" << endl;
        }
    }
    return 0;
}