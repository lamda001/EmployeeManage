#include<iostream>
#include"EmployeeManage.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Workers.h"

using namespace std;

int main() {
	/*test01();*/
	EmployeeManage em;
	int choice = 0;
	while (true) {
		em.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 0://�˳�ϵͳ
			em.exitSystem();
			break;
		case 1://���Ա��
			em.addEmp();
			break;
		case 2://��ʾԱ��
			em.show_Emp();
			break;
		case 3://ɾ��Ա��
			em.del_Emp();
			break;
		case 4://�޸�Ա��
			em.mod_Emp();
			break;
		case 5://����Ա��
			em.fine_Emp();
			break;
		case 6://����
			em.sort_Emp();
			break;
		case 7://���
			em.empty_Emp();
			break;
		default:
			break;
		}
	}
	return 0;
}

