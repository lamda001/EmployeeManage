#include"Manager.h"

Manager::Manager(int id, string name, int p_id) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_PostId = p_id;
}

void Manager::showInfo() {
	cout << "����������\t" << this->m_Name << endl;
	cout << "����ID��\t" << this->m_Id << endl;
	cout << "�����ű�ţ�\t" << this->m_PostId << endl;
	cout << "�����ţ�\t" << this->getPostName() << endl;
	cout << "*-----------------------------------------*" << endl;
}

string Manager::getPostName() {
	switch (this->m_PostId) {
	case 1:
		return("�������ž���");
		break;
	case 2:
		return("���۲��ž���");
		break;
	case 3:
		return("��Ʒ���ž���");
		break;
	default:
		cout << "�þ����ű�Ų����ڣ�" << endl;
		break;
	}
}