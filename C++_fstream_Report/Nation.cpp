#include "Nation.h"

istream& operator>>(istream& ins, Nation& op)
{
	cout << "���� �̸� �Է� >>";
	ins >> op.nation;
	if (op.nation == "no")		//���� no��� �Է� �޾��� ��� �ٷ� ��ȯ��
		return ins;
	cout << op.nation << "�Ǽ��� �Է� >>";
	ins >> op.capital;
	return ins;
}

ostream& operator<<(ostream& outs, Nation& op)
{
	outs << "���� : " << op.nation << ", ���� : " << op.capital << endl;
	return outs;
}

bool operator==(const Nation& op1, const Nation& op2)
{
	if (op1.capital == op2.capital && op1.nation == op2.nation)
		return true;
	else
		false;
}