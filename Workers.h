#pragma once
#include<iostream>
#include<string>
using namespace std;

class Workers {
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getPostName() = 0;

	int m_Id;//Ա��ID
	string m_Name;//Ա������
	int m_PostId;//Ա�����ű��
};