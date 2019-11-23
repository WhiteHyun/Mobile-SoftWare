#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape
{
protected:
	virtual void draw();
public:
	Circle(const int size) : Shape(size)
	{
		//cout << "Shape :: Circle ������ ����" << endl;
	}
	~Circle()
	{
		//cout << "Shape :: Circle �Ҹ��� ����" << endl;
	}
};
#endif