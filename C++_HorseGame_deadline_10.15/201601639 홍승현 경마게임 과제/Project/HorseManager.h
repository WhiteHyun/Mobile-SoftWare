#ifndef HORSEMANAGER_H
#define HORSEMANAGER_H
#include "Horse.h"
class HorseManager
{
	int first_win[5];	//����� ���� ������ ���� ����
	int count;	//�渶 ������ �����ϱ� ���� ���� ����
	int select;	//�Է¹��� ���� ��� �渶�� �����ϱ� ���� ���� ����
	Horse* horse;	//������ �渶 Ŭ������ �����Ͱ�ü ����
public:
	HorseManager();	//������
	~HorseManager();	//�Ҹ���
	int horse_input();	//�渶 ���� �Է¹ް� ��ȯ�� �Լ� ����
	int select_input();	//������ �渶 ���� �Է¹ް� ��ȯ�� �Լ� ����
	void Progress();	//��� ���� �Լ�
	void Show(int time_i)const;		//���� ��� ����� ��� �Ǿ��ִ��� ����ϴ� �Լ� ����
	void End_Announcement();
};
#endif