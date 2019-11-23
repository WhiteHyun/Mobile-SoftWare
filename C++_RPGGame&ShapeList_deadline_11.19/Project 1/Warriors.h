#ifndef WARRIORS_H
#define WARRIORS_H
#include "Character.h"
class Warriors : public Character
{
public:
	Warriors() : Character(150, 60, 10, 13)
	{
		//cout << "Character :: Warriors ������ ����" << endl;
	}
	~Warriors()
	{
		//cout << "Character :: Warriors �Ҹ��� ����" << endl;
	}
	void Attack(Character* enemies)
	{
		int attack = this->getDamage() - enemies->getArmor();
		cout << "����� ��뿡�� " << attack << "�� ���ظ� �������ϴ�!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}

	// Warrior uses skill on enemy
	void Skill(Character* enemies)
	{
		int skill_damage = 15;
		int attack = skill_damage - enemies->getArmor();
		this->setMP(this->getMP() - 10);
		cout << "����� ��뿡�� " << attack << "�� ���ظ� �������ϴ�!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}
};
#endif