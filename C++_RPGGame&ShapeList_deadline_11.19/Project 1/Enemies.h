#ifndef ENEMIES_H
#define ENEMIES_H
#include "Character.h"
class Enemies : public Character
{
public:
	Enemies() : Character(40, 0, 5, 15)
	{
		//cout << "Character :: Enemies ������ ����" << endl;
	}
	~Enemies()
	{
		//cout << "Character :: Enemies �Ҹ��� ����" << endl;
	}
	void Attack(Character* main_hero)
	{
		int attack = this->getDamage() - main_hero->getArmor();
		cout << "����� ���κ��� " << attack << "�� ���ظ� �Ծ����ϴ�!" << endl << endl;
		main_hero->setHP(main_hero->getHP() - attack);
	}
	void Skill(Character* trash)
	{
		//��ӹ޾� �������̵� �ϵ�, ����ϴ� ���� ����.
	}

};
#endif