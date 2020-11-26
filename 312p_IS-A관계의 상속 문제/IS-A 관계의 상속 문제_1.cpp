#include <iostream>
using namespace std;

class Rectangle
{
private:
    int height;
    int width;
public:
    Rectangle(int height, int width)
        : height(height), width(width)
    { }
    int GetH() const { return height; }
    int GetW() const { return width; }
    void ShowAreaInfo() const
    {
        cout << "면적: " << height * width << endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int side)
        : Rectangle(side, side)
    { }
    void ShowAreaInfo() const
    {
        cout << "면적: " << GetH() * GetW() << endl;
    }
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}