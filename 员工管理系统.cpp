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
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出系统
			em.exitSystem();
			break;
		case 1://添加员工
			em.addEmp();
			break;
		case 2://显示员工
			em.show_Emp();
			break;
		case 3://删除员工
			em.del_Emp();
			break;
		case 4://修改员工
			em.mod_Emp();
			break;
		case 5://查找员工
			em.fine_Emp();
			break;
		case 6://排序
			em.sort_Emp();
			break;
		case 7://清空
			em.empty_Emp();
			break;
		default:
			break;
		}
	}
	return 0;
}

