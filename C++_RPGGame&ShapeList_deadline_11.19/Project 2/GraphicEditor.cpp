#include "GraphicEditor.h"
#include <string>

const int TOTAL_SIZE = 0;
const int LINE = 1;
const int CIRCLE = 2;
const int RECTANGLE = 3;
//�������� �ڵ��� ���ü��� ���� ������ const ����

int GraphicEditor::Menu()	//�޴� ����â ������� ����
{
	cout << "---------------------Graphic Editor---------------------" << endl;
	cout << "1. ����, 2. ����, 3. ��κ���, 4. �������, 5. ����" << endl;
	cout << "���� : ";
	string select_menu_settings;
	while (true)		//���� ���� �ݺ���
	{
		cin >> select_menu_settings;
		if (!Error(select_menu_settings, 1, 5))		//������ �߻����� ������ �ݺ��� ���
			break;
	}
	return stoi(select_menu_settings, nullptr, 10);	//string ������ ������(10����)���� ��ȯ�ؼ� ����
}

void GraphicEditor::Input()
{
	cout << endl << "1. ��, 2. �� , 3. �簢�� >> ";
	string select_shape_convert;
	int select_shape;
	while (true)		//���� ���� �ݺ���
	{
		cin >> select_shape_convert;
		if (!Error(select_shape_convert, 1, 3))	//������ �߻����� �ʾ��� ��� �ݺ��� Ż��
			break;
	}
	select_shape = stoi(select_shape_convert, nullptr, 10);	//string��-> int �� ����ȯ �� �ش� ������ ����


	switch (select_shape)		//���� ����
	{
	case LINE:
		if (size[TOTAL_SIZE] == 0)		//�ܼ� �� �Է¹��� ������ ���� ���
		{
			this->startNode = new Line(LINE);
			this->peek = this->startNode;
			this->size[TOTAL_SIZE]++;
			this->size[LINE]++;
		}
		else				//�Է� ���� ������ ���� ���
		{
			this->peek = this->peek->add(new Line(LINE));
			this->size[TOTAL_SIZE]++;
			this->size[LINE]++;
		}
		break;
	case CIRCLE:
		if (size[TOTAL_SIZE] == 0)		//�ܼ� �� �Է¹��� ������ ���� ���
		{
			this->startNode = new Circle(CIRCLE);
			this->peek = this->startNode;
			this->size[TOTAL_SIZE]++;
			this->size[CIRCLE]++;
		}
		else				//�Է� ���� ������ ���� ���
		{
			this->peek = this->peek->add(new Circle(CIRCLE));
			this->size[TOTAL_SIZE]++;
			this->size[CIRCLE]++;
		}
		break;
	case RECTANGLE:
		if (size[TOTAL_SIZE] == 0)		//�ܼ� �� �Է¹��� ������ ���� ���
		{
			this->startNode = new Rect(RECTANGLE);
			this->peek = this->startNode;
			this->size[TOTAL_SIZE]++;
			this->size[RECTANGLE]++;
		}
		else				//�Է� ���� ������ ���� ���
		{
			this->peek = this->peek->add(new Rect(RECTANGLE));
			this->size[TOTAL_SIZE]++;
			this->size[RECTANGLE]++;
		}
		break;
	}
}

void GraphicEditor::Delete()
{
	if (size[TOTAL_SIZE] == 0)	//�����ϴ� ������ ���� ���
	{
		cout << "������ ��尡 �����ϴ�!! �켱������ ������ �������ּ���!" << endl;
		return;
	}

	Shape* deleteNode = startNode;	//������ ��带 ����Ű�� �ӽ� ���
	Shape* changeNode;	//������ ��� �տ� �ִ� ����� next�� �������ִ� �ӽ� ���

	cout << "�����ϰ��� �ϴ� ������ �ε���>> ";

	string input_index_string;		//������ �ε��� �Է� ����
	int index;						//���� �ε��� ��ȯ���� ����

	while (true)		//���� ���� �ݺ���
	{
		cin >> input_index_string;
		if (!Error(input_index_string, 0, this->size[TOTAL_SIZE] - 1))		//������ ������� ������ �ݺ��� Ż��
			break;
	}
	index = stoi(input_index_string, nullptr, 10);

	if (index == 0)	//������ ��尡 ù ����� ��
	{
		if (peek == startNode)		//ù ��尡 peek�� ���
		{
			startNode = nullptr;
			peek = nullptr;
		}
		else						//ù ��尡 peek �� �ƴ� ���
		{
			startNode = startNode->add(startNode->getNext());
		}
		switch (deleteNode->getShape())	//������ ���� �˻�(search) �� ������ ����(size)�� 1�� discount
		{
		case LINE:
			this->size[LINE]--;
			break;
		case CIRCLE:
			this->size[CIRCLE]--;
			break;
		case RECTANGLE:
			this->size[RECTANGLE]--;
			break;
		}
		this->size[TOTAL_SIZE]--;		//�� ������ ����(size)�� 1 discount.
		delete[] deleteNode;	//��� ����
	}
	else			//������ ��尡 ù ��尡 �ƴ� ���
	{
		for (int i = 0; i < index - 1; i++)		//������ �ε���(���)�� �ֱ� �ٷ� �� ������ deleteNode�� Search �� ����, �� ������ �ε���(���)�� �� ����
		{
			deleteNode = deleteNode->getNext();
		}
		changeNode = deleteNode;				//������ ����� �� ������ �ش� ������ ����
		deleteNode = deleteNode->getNext();	//next�� ������ ������ ���� �̵�

		if (deleteNode == peek)			// ���� �����Ϸ��� ��尡 ���� ������(peek) �� ���
		{
			changeNode->add(deleteNode->getNext());
			this->peek = changeNode;
		}
		else  if(deleteNode != peek/* && deleteNode != nullptr*/)		//ù ���� ������ ��� ������ ����� ���
			changeNode->add(deleteNode->getNext());

		switch (deleteNode->getShape())
		{
		case LINE:
			this->size[LINE]--;
			break;
		case CIRCLE:
			this->size[CIRCLE]--;
			break;
		case RECTANGLE:
			this->size[RECTANGLE]--;
			break;
		}
		this->size[TOTAL_SIZE]--;
		delete deleteNode;
	}
}

void GraphicEditor::AllShow() const
{
	int i = 0;
	if (size[TOTAL_SIZE] == 0)
	{
		cout << "���� ������ �������� �ʽ��ϴ�. ������ ���� ������ �������ּ���." << endl;
		return;
	}
	else
	{
		for (Shape* tempNode = startNode; tempNode != nullptr; tempNode = tempNode->add(tempNode->getNext()))
		{
			cout << i << ": ";
			tempNode->paint();
			i++;
		}
	}

}

void GraphicEditor::Statistic_Information()
{
	if (size[TOTAL_SIZE] == 0)
		cout << "���� ������ �������� �ʽ��ϴ�. ������ ���� ������ �������ּ���." << endl;
	else
	{
		cout << "1. �� ������ ���� : " << size[LINE] << endl
			 << "2. �� ������ ���� : " << size[CIRCLE] << endl
			 << "3. �簢�� ������ ���� : " << size[RECTANGLE] << endl
			 << "�� ������ ���� : " << size[TOTAL_SIZE] << endl;
	}
}

bool GraphicEditor::Error(const string& errorcode, const int size_start, const int size_end)
{
	int temp_int_errorcode;	//int�� �����ڵ� �Ǻ� ����

	for (unsigned int i = 0; i < errorcode.length(); i++)	//���� ���� ó�� �ݺ���
	{
		if (!isdigit(errorcode[i]))	//�Է¹��� ���ڿ� �߿� ���ڰ� �ϳ��� �ִ� ���
		{	//���� �޽��� ���
			cout << endl;
			cout << "�߸��� �Է��Դϴ�. " << size_start << "���� " << size_end << "������ ��ȣ �� �ϳ��� �����Ͽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
			cout << endl;
			return true;	//���� �߻������Ƿ� true ��ȯ
		}
	}

	temp_int_errorcode = stoi(errorcode, nullptr, 10);	//int������ ����ȯ�Ͽ� ����

	if (temp_int_errorcode > size_end || temp_int_errorcode < size_start)	//�Է¹��� ���ڸ� �� �� size_start�� size_end ũ�� ��ŭ�� ���̿� ���� ���� ������ ��� ���� �޽��� ���
	{
		cout << endl;
		cout << "�߸��� �Է��Դϴ�. " << size_start << "���� " << size_end << "������ ��ȣ �� �ϳ��� �����Ͽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
		cout << endl;
	}
	else	//��Ȯ�� ���� �Է����� ��� ���� �߻����� �ʾ����Ƿ� false ��ȯ
		return false;


	return true;	//������ �˻��Ǿ����Ƿ� true ��ȯ
}