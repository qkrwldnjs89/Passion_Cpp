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
        cout << "�Աݾ�: "; cin >> money;
        balance += money;
        cout << "�ԱݿϷ�" << endl;
    }
    void Withdraw()
    {
        int money;
        cout << "��ݾ�: "; cin >> money;
        balance -= money;
        cout << "��ݿϷ�" << endl;
    }
    void PrintInfo()
    {
        cout << "���� ID: " << accID << endl;
        cout << "�� ��: " << name << endl;
        cout << "�� ��: " << balance << endl << endl;
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
                cout << "���α׷� ����" << endl;
                return 0;
            default:
                cout << "�߸��� �ɼ� �Է�" << endl;
        }
        
    }
    return 0;
}

int ShowMenu()
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

void MakeAccount(void)
{
    int accID;
    char name[50];
    int money;

    cout << "[ �� �� �� �� ]" << endl;
    cout << "���� ID: "; cin >> accID; 
    cout << "�� ��: "; cin >> name;
    cout << "�Աݾ�: "; cin >> money;
    accPtrArr[accCnt] = new Account(accID, name, money);
    accCnt++;
}

void Deposit(void)
{
    int accID;
    cout << "[ ��  �� ]" << endl;
    cout << "���� ID: "; cin >> accID;
    for (int i = 0; i < accCnt; i++)
    {
        if (accPtrArr[i]->GetAccID() == accID)
        {
            accPtrArr[i]->Deposit();
            return;
        }
    }
    cout << "���°� �����ϴ�." << endl;
}

void Withdraw(void)
{
    int accID;
    cout << "[ ��  �� ]" << endl;
    cout << "���� ID: "; cin >> accID;
    for (int i = 0; i < accCnt; i++)
    {
        if (accPtrArr[i]->GetAccID() == accID)
        {
            accPtrArr[i]->Withdraw();
            return;
        }
    }
    cout << "���°� �����ϴ�." << endl;
}

void PrintAll(void)
{
    cout << "[ ��  �� ]" << endl;
    for (int i = 0; i < accCnt; i++)
        accPtrArr[i]->PrintInfo();
}