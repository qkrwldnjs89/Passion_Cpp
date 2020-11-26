#include <iostream>
#include <cstring>
using namespace std;

class Girl; // Girl 이라는 이름이 class 의 이름임을 알림

class Boy
{
private:
    int height;
    friend class Girl;
public:
    Boy(int len) : height(len)
    { }
    void ShowYourFriendInfo(Girl &frn) const;
};

class Girl
{
private:
    char phNum[20];
public:
    Girl(const char * num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy &frn) const;
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn) const
{
    cout << "Her phone Number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn) const
{
    cout << "His height: " << frn.height << endl;
}

int main(void)
{
    Boy boy(170);
    Girl girl("010-1234-5678");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    return 0;
}