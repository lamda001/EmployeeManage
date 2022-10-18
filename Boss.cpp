#include "Boss.h"

Boss::Boss(int id, string name, int p_id) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_PostId = p_id;
}

void Boss::showInfo() {
	cout << "老板姓名：\t" <<this->m_Name << endl;
	cout << "老板ID：\t" << this->m_Id << endl;
	cout << "老板部门编号：\t" << this->m_PostId << endl;
	cout << "老板部门：\t" << this->getPostName() << endl;
	cout << "*-----------------------------------------*" << endl;
}

string Boss::getPostName() {
	return("董事会！");
}