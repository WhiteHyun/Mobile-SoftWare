#include "Horse.h"


Horse::Horse()
{
	this->move = 0;	// �ܼ� �����Ҵ��� ���� 0���� �ʱ�ȭ
	this->position = 0;	// ����� �� ���������κ��� ����ϱ� ������ 0���� �ʱ�ȭ
}

void Horse::Addposition(int move)
{
	if (this->position == 20) {}		//�̹� ��¼��� �ִ� ��� �Ѿ
	else if (this->position + move > 20)		//���� ������ �Է¹��� move�� ����ġ�� ���� ���� �ְ�Ÿ��� 20���� �ʰ��� ���
		this->position = 20;		//���� 20���� �ʱ�ȭ���ش�.
	else
		this->position += move;		//�װ� �ƴ϶�� ����ġ���� ������ ����ŭ �����ش�.
	
}