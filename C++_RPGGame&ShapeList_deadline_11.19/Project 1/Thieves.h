#ifndef THIEVES_H
#define THIEVES_H
#include "Character.h"
class Thieves : public Character
{
public:
	Thieves() : Character(120, 60, 7, 16)
	{
		//cout << "Character :: Thieves ������ ����" << endl;
	}
	~Thieves()
	{
		//cout << "Character :: Thieves �Ҹ��� ����" << endl;
	}
	void Attack(Character* enemies)
	{
		int attack = this->getDamage() - enemies->getArmor();
		cout << "����� ��뿡�� " << attack << "�� ���ظ� �������ϴ�!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}

	// Thief uses skill on enemy
	void Skill(Character* enemies)
	{
		int skill_damage = (int)(this->damage * 1.5);
		int attack = skill_damage - enemies->getArmor();
		this->setMP(this->getMP() - 10);
		cout << "����� ��뿡�� " << attack << "�� ���ظ� �������ϴ�!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}
};
#endif