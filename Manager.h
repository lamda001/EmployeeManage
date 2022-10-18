#pragma once
#include<iostream>
using namespace std;
#include"Workers.h"

class Manager :public Workers {
public:
	Manager(int id, string name, int p_id);

	virtual void showInfo();

	virtual string getPostName();
};