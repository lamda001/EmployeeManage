#pragma once
#include<iostream>
using namespace std;
#include"Workers.h"

class Boss :public Workers {
public:
	Boss(int id, string name, int p_id);

	virtual void showInfo();

	virtual string getPostName();
};