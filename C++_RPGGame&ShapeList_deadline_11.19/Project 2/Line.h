#ifndef LINE_H
#define LINE_H
#include "Shape.h"
class Line : public Shape
{
protected:
	virtual void draw();
public:
	Line(const int size) : Shape(size)
	{
		//cout << "Shape :: Line ������ ����" << endl;
	}
	~Line()
	{
		//cout << "Shape :: Line �Ҹ��� ����" << endl;
	}
};
#endif