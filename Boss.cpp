#include "Boss.h"

Boss::Boss(int id, string name, int p_id) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_PostId = p_id;
}

void Boss::showInfo() {
	cout << "�ϰ�������\t" <<this->m_Name << endl;
	cout << "�ϰ�ID��\t" << this->m_Id << endl;
	cout << "�ϰ岿�ű�ţ�\t" << this->m_PostId << endl;
	cout << "�ϰ岿�ţ�\t" << this->getPostName() << endl;
	cout << "*-----------------------------------------*" << endl;
}

string Boss::getPostName() {
	return("���»ᣡ");
}