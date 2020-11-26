#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
    Point(const int &x, const int &y) : xpos(x), ypos(y)
    {
    }
	void ShowPointInfo() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
	}
};

class Circle
{
private:
	Point cen;
	int rad; 
public:
    Circle(const int &x, const int &y, const int &PRad)
        : cen(x, y), rad(PRad)
    {
    }
	void ShowCircleInfo() const
	{
		cout<<"radius: "<<rad<<endl;
		cen.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inner;
	Circle outter;
public:
    Ring(const int x1, const int y1, const int rad1, const int x2, const int y2, const int rad2)
        : inner(x1, y1, rad1), outter(x2, y2, rad2)
    {
    }
	void ShowRingInfo() const
	{
		cout<<"Inner Circle Info. . ."<<endl;
		inner.ShowCircleInfo();
		cout<<"Outter Circle Info. . ."<<endl;
		outter.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
