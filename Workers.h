#pragma once
#include<iostream>
#include<string>
using namespace std;

class Workers {
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getPostName() = 0;

	int m_Id;//员工ID
	string m_Name;//员工名字
	int m_PostId;//员工部门编号
};