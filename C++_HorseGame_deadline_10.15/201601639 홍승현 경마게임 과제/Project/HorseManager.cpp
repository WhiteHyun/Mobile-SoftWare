#include "HorseManager.h"

HorseManager::HorseManager()
{
	cout << "�渶 ���� ����!" << endl;
	this->count = horse_input();			// �Է¹��� �渶�� ���� ī��Ʈ ������ �Ҵ�
	for (int i = 0; i < sizeof(first_win) / sizeof(int); i++)
		this->first_win[i] = -1;		//����� ���� ���� �� ���� �Ҵ�
	horse = new Horse[count];		//�Է¹��� �渶�� ����ŭ ���� �Ҵ�, �迭�� �� �� ����
	this->select = select_input();		// ����� ������ �渶�� �Է¹޾� select ������ �ʱ�ȭ 
}

HorseManager::~HorseManager()
{
	//�����Ҵ��� �޸𸮸� ����
	delete[] horse;
}

int HorseManager::horse_input()
{
	cout << "�� ������ ���� �÷��� �Ͻðڽ��ϱ�?" << endl;
	int temp_count;	//�Է¹��� ���� ����
	for (;;)	//���ѷ���
	{
		cin >> temp_count;		//�渶 �� �Է�

		if (!cin)	//number�� �ƴ� letter ���� �޾��� ���
			cout << "�߸��� �����Է��Դϴ�." << endl << "�ٽ� �Է����ּ���" << endl;

		else if (temp_count >= 2 && temp_count <= 5)	//�������� �渶 ��(2����~5����)�� �޾��� ���
			break;

		else if (temp_count < 2)		//2���� �̸��� �渶 ���� ����	��
			cout << "�ּ� 2������ ���� �ʿ��մϴ�. �ٽ� �Է����ּ���." << endl;

		else if (temp_count > 5)		//5���� �ʰ��� �渶 ���� �޾��� ���
			cout << "�ִ� 5������ ������ �÷��� �����մϴ�, �ٽ� �Է����ּ���" << endl;

		//���� ����
		cin.clear();												//���� ���� ���� ��� ���� ���� ���� �ֱ⿡ ���� �ݺ����� ����� ����.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		//���� ���信 �Ϸ��ν� �Լ��� ��������� ������ ������ŭ �����, ignore �ȿ� �������� ���� �־���.
	}
	//�������� �Է°��� �޾��� ��� �� ��ȯ
	return temp_count;
}

int HorseManager::select_input()
{
	int temp_count;
	cout << "�� ��° ���� ���� �Ͻðڽ��ϱ�?" << endl;
	for (;;)
	{
		cin >> temp_count;		//������ �渶 �Է�

		if (!cin)	//number�� �ƴ� letter ���� �޾��� ���
			cout << "�߸��� �����Է��Դϴ�." << endl << "�ٽ� �Է����ּ���" << endl;

		else if (temp_count >= 1 && temp_count <= this->count)	//�������� �渶 �� �ȿ����� ��ȣ�� �Է� �޾��� ���
			break;
		
		else		//�Է¹��� �渶 ���� ��� �Է��� ���� ���
			cout << "�߸��� �Է��Դϴ�. �Է��� 1�̻� " << this->count << "���Ͽ��� �մϴ�." << endl;
		//���� ����
		cin.clear();												//���� ���� ���� ��� ���� ���� ���� �ֱ⿡ ���� �ݺ����� ����� ����.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		//���� ���信 �Ϸ��ν� �Լ��� ��������� ������ ������ŭ �����, ignore �ȿ� �������� ���� �־���.
	}
	//�������� �Է°��� �޾��� ��� �� ��ȯ
	return temp_count;
}

void HorseManager::Progress()
{
	srand(time(nullptr));			//srand �ȿ� �ð� �õ带 ����
									//srand((unsigned)time(0)); �������� �̷��Ե� ����!
	int loop = 0;	//�渶�� ��� ���������� �����ߴ� �� �ӽ� ���� ���� �� 0���� �ʱ�ȭ
	bool havegoal = true;	//1�� �渶 �˻��� ������ ������ true�� �ʱ�ȭ
	int time_i = 0;	//�ܼ� Ÿ�� ��� ��
	int cnt = 0;
	while (loop != this->count)	//��� �渶�� �������� ��� �ݺ����� ����
	{
		time_i++;
		loop = 0;	//���� ���� ���� ���� 0���� �ʱ�ȭ

		for (int i = 0; i < this->count; i++)
		{
			horse[i].setMove(rand() % 6);			//������ ��(0���� 5����)�� �Է� �޾� �� ��ü�� move ����� �� �Ҵ�.
			horse[i].Addposition(horse[i].getMove());
			//cout << horse[i].getPosition() << endl;
		}

		clock_t start = clock();			//1�� �ڿ� ����ϱ� ����
		while (clock() - start < 1000);		//����� ���� �ڵ�

		Show(time_i);	//���� ������� ������ִ� �Լ�

		//������ Ż������ ������ �� Ż��
		for (int i = 0; i < this->count; i++)
		{
			//���� �渶�� �������� ���� ���� ���
			if (horse[i].getPosition() != 20)
				continue;

			//�渶�� �������� ���� ���
			else
			{
				if (havegoal)
					first_win[cnt++] = i;	//��ҿ� �渶 ��ȣ ������ cnt���� 1��ŭ ����
				loop++;	//�������� 1��ŭ�� ����.
			}
		}
		if (first_win[0] != -1)
			havegoal = false;		//���� �� ���� �̻��� �渶�� ��¼��� �������� ��� 1�� �渶 �˻��� ���� �ʰԲ� havegoal ������ false �� ����.

		//��� �渶�� �� ������  loop = this->count �� ������ ��.
	}
	End_Announcement();
}


void HorseManager::Show(int time_i) const
{
	//cout << horse[0].getPosition() << ' ' << horse[1].getPosition() << ' ' << horse[2].getPosition() << ' ' << horse[3].getPosition() << endl;
	cout << endl << endl;
	cout << "Time : " << time_i << endl;
	cout << "====================================================" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << "|";
		for (int j = 0; j < horse[i].getPosition(); j++)
			cout << "--";
		cout << "(  )=> " << horse[i].getPosition() << endl;
	}
	cout << "====================================================" << endl << endl << endl;
}

void HorseManager::End_Announcement()
{
	//��Ⱑ ���� �� ��Ʈ ���
	cout << "����ڴ� ";
	for (int i = 0; first_win[i] != -1; i++)
	{
		//���� ��� ����
		if (first_win[i+1] == -1)
			cout << first_win[i] + 1 << "��° ";
		else
			cout << first_win[i] + 1 << "��°, ";
	}
	cout << "�渶�Դϴ�!" << endl;

	for (int i = 0; first_win[i] != -1; i++)
	{
		//���� ��°渶�� ���߾��� ���
		if (this->select == first_win[i] + 1)
		{
			cout << "���ϵ帳�ϴ�! ����� �¸��ϼ̽��ϴ�." << endl;
			return;
		}
	}	
		// �ƴ� ���
		cout << "����� �й��ϼ̽��ϴ�. :(" << endl;
}