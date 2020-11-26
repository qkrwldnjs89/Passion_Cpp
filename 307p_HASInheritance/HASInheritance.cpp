#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    { }
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police : public Gun
{
/*
접근불가:
    int bullet;
*/
private:
    int handcuffs;
public:
    Police(int bnum, int bcuff)
        : Gun(bnum), handcuffs(bcuff)
    { }
    void PutHandCuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
};

int main(void)
{
    Police pman(3, 5);
    pman.Shot();
    pman.PutHandCuff();
    return 0;
}