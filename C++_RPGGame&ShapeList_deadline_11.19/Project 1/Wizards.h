#ifndef WIZARDS_H
#define WIZARDS_H
#include "Character.h"
class Wizards : public Character
{
public:
	Wizards() : Character(120, 80, 7, 10)
	{
		//cout << "Character :: Wizards ������ ����" << endl;
	}
	~Wizards()
	{
		//cout << "Character :: Wizards �Ҹ��� ����" << endl;
	}
	void Attack(Character* enemies)
	{
		int attack = this->getDamage() - enemies->getArmor();
		cout << "����� ��뿡�� " << attack << "�� ���ظ� �������ϴ�!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}

	// Wizard uses skill on enemy
	void Skill(Character* enemies)
	{
		int skill_damage = 30;
		int attack = skill_damage - enemies->getArmor();
		this->setMP(this->getMP() - 10);
		cout << "����� ��뿡�� " << attack << "�� ���ظ� �������ϴ�!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}
};
#endif