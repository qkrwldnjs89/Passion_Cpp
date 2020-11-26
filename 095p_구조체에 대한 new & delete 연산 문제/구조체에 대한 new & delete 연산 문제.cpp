#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main(void)
{
	Point * pos1 = new Point;
	Point * pos2 = new Point;
	Point * resultPos = new Point;
	pos1->xpos = 3;
	pos1->ypos = 4;
	pos2->xpos = 5;
	pos2->ypos = 6;
	
	*resultPos = PntAdder(*pos1, *pos2);
	
	cout<<resultPos->xpos<<endl<<resultPos->ypos<<endl;
	delete pos1; delete pos2; delete resultPos;
	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point * result = new Point;
	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;
	return *result;
}
