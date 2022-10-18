#include"Manager.h"

Manager::Manager(int id, string name, int p_id) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_PostId = p_id;
}

void Manager::showInfo() {
	cout << "经理姓名：\t" << this->m_Name << endl;
	cout << "经理ID：\t" << this->m_Id << endl;
	cout << "经理部门编号：\t" << this->m_PostId << endl;
	cout << "经理部门：\t" << this->getPostName() << endl;
	cout << "*-----------------------------------------*" << endl;
}

string Manager::getPostName() {
	switch (this->m_PostId) {
	case 1:
		return("开发部门经理！");
		break;
	case 2:
		return("销售部门经理！");
		break;
	case 3:
		return("产品部门经理！");
		break;
	default:
		cout << "该经理部门编号不存在！" << endl;
		break;
	}
}