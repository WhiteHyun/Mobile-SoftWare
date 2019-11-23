#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
class Shape
{
	int shape;
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape(const int shape)
	{
		next = nullptr;
		this->shape = shape;
	}
	virtual ~Shape()
	{
		//cout << "Shape �θ�Ŭ���� �Ҹ��� ����" << endl;
	}
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() const
	{
		return next;
	}
	int getShape() const
	{
		return shape;
	}
};
#endif