#include "Manager.h"
#include <ctime>
constexpr auto NATION_NAME = true;
constexpr auto CAPITAL_NAME = false;

#pragma region �����Ǻ���
bool isError(const string& errorcode, const int size)
{
	int temp_int_errorcode;                                                               //int�� �����ڵ� �Ǻ� ����
	if ((errorcode.length() != 1) || (errorcode.length() == 1 && !isdigit(errorcode[0]))) //�Է¹��� ���ڿ��� ���̰� 2�ڸ� �̻��̰ų�, 1�ڸ��� �� �� ���ڰ� ���ڰ� �ƴ� ���
	{                                                                                     //���� �޽��� ���
		cout << endl;
		cout << "�߸��� �Է��Դϴ�. 1���� " << size << "������ ��ȣ �� �ϳ��� �����Ͽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
		cout << endl;
	}
	else //�������� �ϳ��� ���ڸ� �Է� ���� ���
	{
		temp_int_errorcode = stoi(errorcode, nullptr, 10);       //int������ ����ȯ�Ͽ� ����
		if (temp_int_errorcode > size || temp_int_errorcode < 1) //�Է¹��� ���ڸ� �� �� 1�� size ũ�� ��ŭ�� ���̿� ���� ���� ������ ��� ���� �޽��� ���
		{
			cout << endl;
			cout << "�߸��� �Է��Դϴ�. 1���� " << size << "������ ��ȣ �� �ϳ��� �����Ͽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
			cout << endl;
		}
		else //��Ȯ�� ���� �Է����� ��� ���� �߻����� �ʾ����Ƿ� false ��ȯ
			return false;
	}
	return true; //������ �˻��Ǿ����Ƿ� true ��ȯ
}
#pragma endregion

#pragma region ������ �޴�
int AdministratorMode(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Source File Upload" << endl;
		cout << "[2] Update Information" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 2))
		{
			break;
		}
	}
	return stoi(select);
}
#pragma endregion

#pragma region �������� ���� �޴�
int Update_Information_Menu(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Rename Capital" << endl;
		cout << "[2] Insert Nation" << endl;
		cout << "[3] Delete_Nation" << endl;
		cout << "[4] BackUp" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 4))
		{
			break;
		}
	}
	return stoi(select);
}
#pragma endregion

#pragma region ���� �޴�
int UserMode(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Search Capital Information" << endl;
		cout << "[2] Quiz" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 2))
		{
			break;
		}
	}
	return stoi(select);
}
#pragma endregion

#pragma region ���� ���� �˻� ���� �޴�
int Search_Capital_Information_Menu(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Individual Search by Nation Name" << endl;
		cout << "[2] Print All of Nation's Information" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 2))
			break;
	}
	return stoi(select);
}
#pragma endregion

#pragma region-- ---------------------���⼭���ʹ� ����Լ�-- ----------------------

#pragma endregion

#pragma region �����ߺ��˻� �� �ߺ��� ��ġ ��ȯ
vector<Nation>::iterator Manager::Find_Overlap(const Nation& nation_object)		//Nation ��ü�� ���� �ߺ��˻�
{
	for (vector<Nation>::iterator it = v.begin(); it < v.end(); it++)
	{
		if (nation_object == *it)		//�������
		{
			return it;	//�ش� ������ ��ġ ��ȯ
		}
	}
	return v.end();		//�ߺ��� ������ ������ end�� ��ȯ
}
vector<Nation>::iterator Manager::Find_Overlap(const string& nation_name)		// ���� �̸��� ���� �ߺ��˻�
{
		for (vector<Nation>::iterator it = v.begin(); it < v.end(); it++)
		{
			if (nation_name == it->getNation())		//���� ���
			{
				return it;	//�ش� ������ ��ġ ��ȯ
			}
		}
	return v.end();		//�ߺ��� ������ ������ end�� ��ȯ
}
#pragma endregion

#pragma region �޴�
void Manager::Menu()
{
	string input_select;
	int select;
	bool end = false;
	while (!end)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Administrator Mode" << endl;
		cout << "[2] User Mode" << endl;
		cout << "[3] Program Exit" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		while (true) //���� ���� �ݺ���
		{
			cin >> input_select;
			if (!isError(input_select, 3))
			{
				select = stoi(input_select);
				break;
			}
		}

		switch (select)
		{
#pragma region �����ڸ���� ��
		case ADMIN:
			select = AdministratorMode(input_select); //�ڽĸ޴��� �������� �Է¹޾� ���Ҵ� �� ����ġ�� ����
			switch (select)
			{
			case SOURCE_FILE_UPLOAD:
				Upload();
				break;
			case UPDATE_INFORMATION:
				select = Update_Information_Menu(input_select);
				switch (select)
				{
				case RENAME_CAPITAL:
					Rename_Capital();
					break;

				case INSERT_NATION:
					Insert_Nation();
					break;

				case DELETE_NATION:
					Delete_Nation();
					break;

				case BACKUP:
					BackUp();
					break;
				}
				break;
			}
			break;
#pragma endregion

#pragma region ��������� ��

		case USER:
			select = UserMode(input_select);
			switch (select)
			{
			case SEARCH_CAPITAL_INFORMATION:
				select = Search_Capital_Information_Menu(input_select);
				switch (select)
				{
				case INDIVIDUAL_SEARCH:
					Individual_Search();
					break;
				case ALL_PRINT:
					All_Print();
					break;
				}
				break;
			case QUIZ:
				Quiz();
				break;
			}
			break;
#pragma endregion
		default:
			cout << endl
				<< "System Exit" << endl;
			end = true;
			break;
		}
	}
}
#pragma endregion

#pragma region Upload
void Manager::Upload()
{
	int count = 0;		//�ߺ��Ǵ� ����, ������ ������ ������ ����
	string line;		//������ �� ���پ��� �Է¹޾� ������ ����
	int divide_index;	//�����̸��� ������ ������ �������� ������ �Ǵ� �ε��� ����
	Nation nation;
	ifstream fin("nation.txt");		//�ش� �ؽ�Ʈ ���� ����
	if (!fin)
	{
		cout << "ERROR!!!" << endl; //�б� �����ϰ�� ���� ��� �� ����
		return;
	}
	while (getline(fin, line))
	{
		divide_index = line.find(":");		//:�� �������� ������ �����ϱ� ���� �ڵ�
		nation.setNation(line.substr(0, divide_index));						// : �� �������� �����
		nation.setCapital(line.substr((divide_index + 1), line.length()));	// ������ ���� �Է¹���
		if (Find_Overlap(nation) != v.end())                               //�׸��� �ߺ��Ǵ� ����� ���� ��� �ߺ� ���� ���� Increment
		{
			count++;
			continue;
		}
		else //�������� ���� ��� ���Ϳ� ����
			v.push_back(nation);
	}
	cout << "Upload Finished" << endl;
	if (count != 0) //���� �ߺ��Ǵ� ����� ���� ��� �˷���!
		cout << endl
		<< "System: �ߺ��Ǵ� ���� " << count << "�� �߰��Ͽ��⿡, �ߺ��Ǿ� ���� �ʾ����� �̸� �˷��帳�ϴ�." << endl;
	fin.close();
}
#pragma endregion

#pragma region �����̸� ����
void Manager::Rename_Capital()
{
	string input;
	if (v.size() == 0)
		cout << "������ ������ �����ϴ�!" << endl;
	else
	{
		cout << "������ �����Ϸ��� ������ �Է����ּ���. �Է��� ���� ���� �ش� ���������� �˻��մϴ�." << endl;
		cin >> input;
		auto it = Find_Overlap(input);		//�ߺ����� �ƴ��� �����ϰ� �׿� ���� ��ġ�� it�� ����
		if (it != v.end())	//���� �ߺ��� ���(���� �̸��� ��ģ ���)
		{
			cout << "������ ������ �̸��� �����ּ��� >>";
			cin >> input;
			it->setCapital(input);
			cout << "�����Ǿ����ϴ�." << endl;
		}
		else		//������ ���ο� ���� ���
			cout << "�����Ϸ��� ������ �������� �ʽ��ϴ�." << endl;
	}
}
#pragma endregion

#pragma region ���ο� ���� �߰�
void Manager::Insert_Nation()
{
	Nation nation;
	cout << "�߰��� ������ �̸��� �Է����ּ���." << endl;
	while (true)
	{
		cin >> nation;
		if (nation.getNation() == "no")
		{
			cout << endl
				<< "�߰��� ����ġ�ڽ��ϴ�." << endl;
			break;
		}
		if (Find_Overlap(nation) != v.end()) //�ߺ��˻�
		{
			cout << "�̹� �����ϴ� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
		}
		else //�ߺ��� �ƴ� ���
		{
			v.push_back(nation);
			cout << "�ش� ���� �߰��Ͽ����ϴ�." << endl;
		}
	}
}
#pragma endregion

#pragma region ���� ����
void Manager::Delete_Nation()
{
	string nation_name;
	if (v.size() == 0)
		cout << "������ ������ �������� �ʽ��ϴ�." << endl;
	else
	{
		cout << "������ ������ �Է��Ͽ��ֽʽÿ�.";
		cin >> nation_name;
		auto it = Find_Overlap(nation_name);		//�ߺ��˻� �� �ش� ��ġ�� ��ȯ
		if (Find_Overlap(nation_name) != v.end())	//�ߺ��Ǵ� ���� ���� ���
		{
			v.erase(it);		//�ش� ��ġ�� ���� ����
			cout << "�����Ǿ����ϴ�." << endl;
		}
		else				//�ߺ��� �������(���ϰ� ���� �ʴ� ���)
		{
			cout << "�������� �ʴ� �����Դϴ�." << endl;
		}
	}
}
#pragma endregion

#pragma region �ҽ����� ���
void Manager::BackUp()
{
	Nation nation;
	auto it = v.begin();
	if (v.size() == 0)
	{
		cout << "����� ������ �����ϴ�." << endl;
	}
	else
	{
		ofstream fout("nation.txt", ios::out);		//fout ��Ʈ���� ���� ����
		if (!fout)		//���� ���⿡ ������ ��� ����
		{
			cout << "ERROR!!!" << endl;
			return;
		}
		for (auto it = v.begin(); it < v.end(); it++)	//������ ��� ���� ����
			fout << it->getNation() << ":" << it->getCapital() << endl;

		cout << "It completely backuped" << endl;
		fout.close();
	}
}
#pragma endregion

#pragma region �����̸����� ���� �˻�
void Manager::Individual_Search()
{
	string nation_name;
	if (v.size() == 0)
		cout << "�˻��� ���� �������� �ʽ��ϴ�!" << endl;
	else
	{
		cout << "�ش� ���� �˻��Ͽ� ������ �˾ƺ�����!" << endl;
		cout << "���� : ";
		cin >> nation_name;
		auto it = Find_Overlap(nation_name);		//�˻��� ���� ���� ���ο� �����ϴ��� ���� Ȯ�� �� �׿� ���� ��ġ ����
		if (it != v.end())		//���� ������ ���
		{
			cout << it->getNation() << "�� ������ " << it->getCapital() << "�Դϴ�." << endl;
		}
		else
			cout << "�ش� ����� �����Ϳ� �������� �ʽ��ϴ�!" << endl;
	}
}
#pragma endregion

#pragma region �������� ��ü ���
void Manager::All_Print()
{
	int count = 1;
	if (v.size() == 0)
		cout << endl
		<< "����� ���� �����ϴ�." << endl;
	else
	{
		for (auto it = v.begin(); it < v.end(); it++)
		{
			cout << "[" << count << "] " << *it;
			count++;
		}
	}
}
#pragma endregion

#pragma region ����
void Manager::Quiz()
{
	srand(time(nullptr));
	int index;
	string answer;
	int score = 0;
	int i;
	for (i = 0; i < 4; i++)
	{
		index = rand() % v.size();
		cout << "[���� " << i + 1 << "] " << v[index].getNation() << "�� ������?" << endl;
		cout << "���� : ";
		cin >> answer;
		if (answer == "9")
		{
			break;
		}
		else if (answer == v[index].getCapital())
		{
			score++;
		}
	}
	cout << "���� ����Ǯ�� �� : " << i << endl;
	cout << "�׿� ���� ����� : " << (float)score * 100 / i << "%" << endl;
}
#pragma endregion