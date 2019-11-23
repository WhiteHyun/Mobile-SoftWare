#ifndef GAMEMAIN_H
#define GAMEMAIN_H
#include "Enemies.h"
#include "Thieves.h"
#include "Wizards.h"
#include "Warriors.h"
#include <string>
class GameMain
{
	int difficulty;		//1 ���� 2 ���� 3 �����
	Character* enemies;
	Character* main_hero;
	int Set_Difficulty();	//���̵� ���� �޼ҵ�
	int Set_Job();		//���� ���� �޼ҵ�		���̵��� ���� ������ Ŭ���� �ܺο��� ������ �� ������ �ϱ� ���� private�� �����Ͽ���.
	int Set_Menu();
public:
	GameMain()
	{
		Menu();
	}
	~GameMain()
	{
		if (enemies)
			delete[] enemies;
		if (main_hero)
			delete main_hero;
	}
	bool Error(const string& errorcode, const int size);	//1���� size ���� �Է¿� ���� ���� ���� �޼ҵ�
	void Menu();		//�޴� �޼ҵ�
	void Start();		//���� ���� �޼ҵ�

};

#endif