#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(const char* myname, const int myage)
        : age(myage)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
    void ShowMyFriendInfo() const
    {
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(const char* myname, const int myage, const char* myaddr, const char* myphone)
        : MyFriendInfo(myname, myage)
    {
        addr = new char[strlen(myaddr) + 1]; strcpy(addr, myaddr);
        phone = new char[strlen(myphone) + 1]; strcpy(phone, myphone);
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;        
    }
    void ShowMyFriendDetailInfo() const
    {
        ShowMyFriendInfo();
        cout << "�ּ�: " << addr << endl;
        cout << "��ȭ: " << phone << endl << endl;
    }
};

int main(void)
{
    MyFriendInfo fr1("Lyn", 22);
    fr1.ShowMyFriendInfo();
    MyFriendDetailInfo fr2("Won", 23, "Busan", "010-1234-5678");
    fr2.ShowMyFriendDetailInfo();
    return 0;
}