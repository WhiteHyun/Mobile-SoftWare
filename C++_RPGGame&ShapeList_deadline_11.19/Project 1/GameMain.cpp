#include "GameMain.h"

const string JOB_WARRIOR = "1";
const string JOB_WIZARD = "2";
const string JOB_THIEF = "3";
const string EASY = "1";
const string MEDIUM = "2";
const string DIFFICULT = "3";
const string GENERAL_ATTACK = "1";
const string SKILL_ATTACK = "2";
const int SELECT_JOB_WARRIOR = 1;
const int SELECT_JOB_WIZARD = 2;
const int SELECT_JOB_THIEF = 3;
const int MENU_DIFFICULTY_SETTING = 1;
const int MENU_JOB_SETTING = 2;
const int MENU_GAME_START = 3;
//�������� �ڵ� ������ ���� ������ const ����

int GameMain::Set_Difficulty()
{
	string difficulty;
	while (true)
	{
		cout << "[���̵� ����]" << endl;
		cout << "1. ����   2. ����    3. �����" << endl;
		cout << "���� : ";
		cin >> difficulty;	//���̵� �Է�
		if (!Error(difficulty, 3))	//��Ȯ�� ���ڸ� �޾Ҵ��� �Ǻ�, ������ ���� �ʴ´ٸ� �ݺ��� Ż��
			break;
	}
	if (difficulty == EASY) cout << "���̵� \"����\"�� �����ϼ̽��ϴ�." << endl;
	else if (difficulty == MEDIUM) cout << "���̵� \"����\"�� �����ϼ̽��ϴ�." << endl;
	else if (difficulty == DIFFICULT) cout << "���̵� \"�����\"�� �����ϼ̽��ϴ�." << endl;
	return stoi(difficulty, nullptr, 10);
}


int GameMain::Set_Job()
{
	string job;
	while (true)
	{
		cout << "[���� ����]" << endl;
		cout << "1. ����   2. ������    3. ����" << endl;
		cout << "���� : ";
		cin >> job;		//���� ���� �Է�
		if (!Error(job, 3))	//��Ȯ�� ���ڸ� �޾Ҵ��� �Ǻ�, ������ ���� �ʴ´ٸ� �ݺ��� Ż��
			break;
	}
	if (job == JOB_WARRIOR) cout << "\"����\"�� �����ϼ̽��ϴ�." << endl;
	else if (job == JOB_WIZARD) cout << "\"������\"�� �����ϼ̽��ϴ�." << endl;
	else if (job == JOB_THIEF) cout << "\"����\"�� �����ϼ̽��ϴ�." << endl;
	return stoi(job, nullptr, 10);
}


int GameMain::Set_Menu()
{
	string select_menu;
	while (true)
	{
		cout << "-------MENU-------" << endl;
		cout << "1. ���̵� �����ϱ�" << endl;
		cout << "2. ���� �����ϱ�" << endl;
		cout << "3. �����ϱ�" << endl;
		cout << "���� : ";
		cin >> select_menu;	//�޴� ����
		if (!Error(select_menu, 3))	//��Ȯ�� ���ڸ� �޾Ҵ��� �Ǻ�, ������ ���� �ʴ´ٸ� �ݺ��� Ż��
			break;
	}
	return stoi(select_menu, nullptr, 10);
}


bool GameMain::Error(const string& errorcode, const int size)
{
	int temp_int_errorcode;	//int�� �����ڵ� �Ǻ� ����
 	if ((errorcode.length() != 1) || (errorcode.length() == 1 && !isdigit(errorcode[0])))	//�Է¹��� ���ڿ��� ���̰� 2�ڸ� �̻��̰ų�, 1�ڸ��� �� �� ���ڰ� ���ڰ� �ƴ� ���
	{	//���� �޽��� ���
		cout << endl;
		cout << "�߸��� �Է��Դϴ�. 1���� " << size << "������ ��ȣ �� �ϳ��� �����Ͽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
		cout << endl;
	}
	else		//�������� �ϳ��� ���ڸ� �Է� ���� ���
	{
		temp_int_errorcode = stoi(errorcode, nullptr, 10);	//int������ ����ȯ�Ͽ� ����
		if (temp_int_errorcode > size || temp_int_errorcode < 1)	//�Է¹��� ���ڸ� �� �� 1�� size ũ�� ��ŭ�� ���̿� ���� ���� ������ ��� ���� �޽��� ���
		{
			cout << endl;
			cout << "�߸��� �Է��Դϴ�. 1���� " << size << "������ ��ȣ �� �ϳ��� �����Ͽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
			cout << endl;
		}
		else	//��Ȯ�� ���� �Է����� ��� ���� �߻����� �ʾ����Ƿ� false ��ȯ
			return false;
	}
	return true;	//������ �˻��Ǿ����Ƿ� true ��ȯ
}


void GameMain::Menu()
{
	int select_job = 0;
	bool gamestart = false;		//���� �÷��� ��/�� �Ǵ� ����
	bool complete_settings = false;	//���� �Ϸ� �Ǵ� ���� ( ���̵� & ���� )
	while (true)
	{
		if (gamestart)		//�̹� ������ �� �� ���������� �ݺ��� ��������
			break;
		else if (difficulty != 0 && select_job != 0)		//��� ������ �Ϸ�Ǿ����� Ȯ���ϴ� �ڵ�
			complete_settings = true;			//������ ��� �Ϸᰡ �Ǿ����� ������ ������ �� �ִ� ���Ǻο��� ������ ����



//----------------------------------------------------------------------------//
		switch(Set_Menu())
		{
		case MENU_DIFFICULTY_SETTING:	//���̵� ���� ���ǹ�
			this->difficulty = Set_Difficulty();
			if (enemies)
				delete[] enemies;	//�����Ҵ� �Ǿ������� �� Ŭ������ �ν��Ͻ� ��ü �޸� ����
			enemies = new Enemies[difficulty + 2];	//�� Ŭ������ �ν��Ͻ� ��ü�� ���̵��� �ش��ϴ� ���� �� ��ŭ ���� �Ҵ�.
			break;
//----------------------------------------------------------------------------//
		case MENU_JOB_SETTING:	//���� ���� ���ǹ�
			select_job = Set_Job();
			if (main_hero)
				delete main_hero;	//�̹� ������ �������� ��� �ش� ������ ������ �޸� ����
			switch (select_job)
			{						//�� ������ ������ ��ĳ���� �Ͽ� �����Ҵ�
			case SELECT_JOB_WARRIOR:
				main_hero = new Warriors();
				break;
			case SELECT_JOB_WIZARD:
				main_hero = new Wizards();
				break;
			case SELECT_JOB_THIEF:
				main_hero = new Thieves();
				break;
			}
			break;
//----------------------------------------------------------------------------//
		case MENU_GAME_START:
			if (complete_settings)	//���� ��� ������ �Ϸ�Ǿ����� ���� ����
			{
				cout << "���� ����" << endl;
				Start();		//���� ���� ����
				gamestart = true;
			}	
			else	//������ ä �Ϸᵵ ���� ���� ä ������ �����Ϸ� �� ���
			{
				cout << "���� ��� ������ �Ϸ���� �ʾҽ��ϴ�." << endl;
			}
			break;
		default:
			cout << "������ �߻��Ͽ����ϴ�." << endl;
			return;
		}
//**************************SWITCH ���� ��********************************//
	}
}


void GameMain::Start()
{
	int the_number_of_enemies = difficulty + 2;	//���� ���ڸ� �����ϴ� ����
	bool ifDead = false;		//���� ������ ���� ���� �� ���� �Ǻ� ����
	string select_attack;
	for (int i = 0; i < the_number_of_enemies; i++)
	{
		for (int j = 1; !enemies[i].HP_isEmpty(); j++)
		{
			cout <<  endl << "<ROUND " << i + 1 << "-" << j << ">" << endl;
			cout << "��� :  HP(" << main_hero->getHP() << ")" << "\t" << "MP(" << main_hero->getMP() << ")" << endl;
			cout << "��� : HP(" << enemies[i].getHP() << ")" << endl << endl;
			cout << "1. �Ϲ� ����     2. ��ų ���" << endl;
			cout << "���� : ";
			// �� �ڵ�� �ܼ� ��¹� : ���� �ڽ��� hp, mp �� ���� ���� ���� ��� �ڵ��̴�.


			for (;;)		// �Է� �� ���� ���� �ݺ���
			{
				cin >> select_attack;		//���� ���� ����
				if (!Error(select_attack, 2))
					break;
			}


			if (select_attack == GENERAL_ATTACK)	//�Ϲ� ������ ���
				main_hero->Attack(enemies + i);

			else if (select_attack == SKILL_ATTACK && main_hero->MP_isUsable())	//��ų ������ �� MP�� ��밡�� �� ���
				main_hero->Skill(enemies + i);

			else if (select_attack == SKILL_ATTACK && !(main_hero->MP_isUsable())) //��ų ������ �� MP�� ��밡������ ���� ���
				cout << "MP�� �����մϴ�. ��ų ��뿡 �����߽��ϴ�. ���� �Ѿ�ϴ�." << endl;

			if (enemies[i].HP_isEmpty())	//�������� �Ͽ� ���� ����Ʈ�� ���
				cout << "���� óġ�߽��ϴ�." << endl;

			else	//�������� �� ���� �������� �ʰ� HP�� ���� �ִ� ���
			{
				(enemies + i)->Attack(main_hero);	//���� ������ ����
				if (main_hero->HP_isEmpty())		//������ ���ݹ޾� ������ ĳ���Ͱ� �������� ���
				{
					ifDead = true;		//�׾����� �Ǵ��ϴ� ������ true�� ��ȯ
					break;
				}
			}
		}

		if (ifDead)		//������ �׾��� ���
		{
			cout << "����� �й��ϼ̽��ϴ�." << endl << endl;
			break;
		}
	}
	if (enemies[the_number_of_enemies - 1].HP_isEmpty())	//������ ���� HP�� ���� ���
		cout << "����� �¸��ϼ̽��ϴ�!" << endl << endl;
}