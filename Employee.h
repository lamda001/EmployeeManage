#pragma once
#include<iostream>
using namespace std;
#include"Workers.h"

//‘±π§¿‡
class Employee:public Workers {
public:
	Employee(int id, string name, int p_id);

	virtual void showInfo();

	virtual string getPostName();
};