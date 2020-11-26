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
    cout << "�Աݾ�: "; cin >> money;
    balance += money;
    cout << "�ԱݿϷ�" << endl;
}
void Account::Withdraw()
{
    int money;
    cout << "��ݾ�: "; cin >> money;
    balance -= money;
    cout << "��ݿϷ�" << endl;
}
void Account::PrintInfo() const
{
    cout << "���� ID: " << accID << endl;
    cout << "�� ��: " << name << endl;
    cout << "�� ��: " << balance << endl << endl;
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
    int accID;
    char name[50];
    int money;

    cout << "[ �� �� �� �� ]" << endl;
    cout << "���� ID: "; cin >> accID; 
    cout << "�� ��: "; cin >> name;
    cout << "�Աݾ�: "; cin >> money;
    accArr[accNum++] = new Account(accID, name, money);
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
            accArr[i]->Deposit();
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
            accArr[i]->Withdraw();
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