#pragma once//��ֹͷ�ļ�����
#include<iostream>//��������������ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include"Workers.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Workers.h"
#include<fstream>

#define FILENAME "empFlie.txt"

class EmployeeManage {
public:
	EmployeeManage();//���캯��

	~EmployeeManage();//��������

	void Show_Menu();//�˵���ʾ

	void exitSystem();//�˳�ϵͳ

	void addEmp();//���Ա������

	void save();//�����ļ�

	int get_EmpNum();//��ѯ�ļ�������

	void init_Emp();//��ʼ������

	void show_Emp();//��ʾ��Ա

	void del_Emp();//ɾ����Ա

	int isExist(int id);//�жϳ�Ա�Ƿ����

	void mod_Emp();//�޸ĳ�Ա

	void fine_Emp();//���ҳ�Ա

	void sort_Emp();//��Ա����

	void empty_Emp();//����ļ�

	//��¼�����Ƿ�Ϊ�ձ�־
	bool m_FileIsEmpty;

	//��¼Ա������
	int m_EmpNum;

	//Ա������ָ��
	Workers** m_EmpArr;
};

