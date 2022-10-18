#include"Employee.h"

Employee::Employee(int id, string name, int p_id) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_PostId = p_id;
}

void Employee::showInfo() {
	cout << "Ա��������\t" << this->m_Name << endl;
	cout << "Ա��ID��\t" << this->m_Id << endl;
	cout << "Ա�����ű�ţ�\t" << this->m_PostId << endl;
	cout << "Ա�����ţ�\t" << this->getPostName() << endl;
	cout << "*-----------------------------------------*" << endl;
}

string Employee::getPostName() {
	switch (this->m_PostId) {
	case 1:
		return("ǰ�˿������ţ�");
		break;
	case 2:
		return("JAVA�������ţ�");
		break;
	case 3:
		return("C++�������ţ�");
		break;
	case 4:
		return("��ά���ţ�");
		break;
	case 5:
		return("���۲��ţ�");
		break;
	case 6:
		return("���Բ��ţ�");
		break;
	default:
		cout << "��Ա�����ű�Ų����ڣ�" << endl;
		break;
	}
}