#include"Employee.h"

Employee::Employee(int id, string name, int p_id) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_PostId = p_id;
}

void Employee::showInfo() {
	cout << "员工姓名：\t" << this->m_Name << endl;
	cout << "员工ID：\t" << this->m_Id << endl;
	cout << "员工部门编号：\t" << this->m_PostId << endl;
	cout << "员工部门：\t" << this->getPostName() << endl;
	cout << "*-----------------------------------------*" << endl;
}

string Employee::getPostName() {
	switch (this->m_PostId) {
	case 1:
		return("前端开发部门！");
		break;
	case 2:
		return("JAVA开发部门！");
		break;
	case 3:
		return("C++开发部门！");
		break;
	case 4:
		return("运维部门！");
		break;
	case 5:
		return("销售部门！");
		break;
	case 6:
		return("测试部门！");
		break;
	default:
		cout << "该员工部门编号不存在！" << endl;
		break;
	}
}