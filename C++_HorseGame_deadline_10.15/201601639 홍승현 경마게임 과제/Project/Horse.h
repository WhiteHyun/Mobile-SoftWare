#ifndef HORSE_H
#define HORSE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//�渶��� ��ü�� ����� ���� Ŭ���� ����
class Horse
{
	int move;		//�� Ÿ��(time)���� �����̴� ���� �����ϱ� ���� move��� ������ ����
	int position;	//�� Ÿ��(time)���� �ٲ�� ��ġ�� �����ϱ� ���� position�̶�� ������ ����
public:
	Horse();
	void setMove(int move)		//����(private)������ �ִ� move ����� �������ֱ� ���� set�Լ�
	{
		this->move = move;
	}
	int getMove()			//����(private)������ �ִ� move ����� �б� ���� get�Լ�
	{
		return move;
	}
	int getPosition()		//����(private)������ �ִ� position ����� �б� ���� ���� set�Լ�
	{
		return position;
	}
	void Addposition(int move);	//����(private)������ �ִ� position ����� move���� �����ֱ� ���� �Լ�

};


#endif