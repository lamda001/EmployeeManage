#pragma once//防止头文件包含
#include<iostream>//包含输入输出流文件
using namespace std;//使用标准命名空间
#include"Workers.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Workers.h"
#include<fstream>

#define FILENAME "empFlie.txt"

class EmployeeManage {
public:
	EmployeeManage();//构造函数

	~EmployeeManage();//析构函数

	void Show_Menu();//菜单显示

	void exitSystem();//退出系统

	void addEmp();//添加员工函数

	void save();//保存文件

	int get_EmpNum();//查询文件中人数

	void init_Emp();//初始化数组

	void show_Emp();//显示成员

	void del_Emp();//删除成员

	int isExist(int id);//判断成员是否存在

	void mod_Emp();//修改成员

	void fine_Emp();//查找成员

	void sort_Emp();//成员排序

	void empty_Emp();//清空文件

	//记录数组是否为空标志
	bool m_FileIsEmpty;

	//记录员工人数
	int m_EmpNum;

	//员工数组指针
	Workers** m_EmpArr;
};

