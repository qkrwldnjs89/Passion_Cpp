#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(const int x, const int y)
	{
		xpos = x;
		ypos = y;
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
	void Init(const int x, const int y, const int PRad)
	{
		cen.Init(x, y);
		rad = PRad;
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
	void Init(const int x1, const int y1, const int rad1, const int x2, const int y2, const int rad2)
	{
		inner.Init(x1, y1, rad1);
		outter.Init(x2, y2, rad2);
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
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
