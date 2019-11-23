#ifndef RECT_H
#define RECT_H
#include "Shape.h"
class Rect : public Shape
{
protected:
	virtual void draw();
public:
	Rect(const int size) : Shape(size)
	{
		//cout << "Shape :: Rect ������ ����" << endl;
	}
	~Rect()
	{
		//cout << "Shape :: Rect �Ҹ��� ����" << endl;
	}
};
#endif