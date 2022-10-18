#include"EmployeeManage.h"
#include"Employee.h"
#include"Boss.h"
#include"Manager.h"

EmployeeManage::EmployeeManage() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "花名册文件不存在！" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArr = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else {
		//文件存在，数据为空
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			cout << "文件为空！" << endl;
			this->m_EmpNum = 0;
			this->m_EmpArr = NULL;
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}//文件存在且不为空
		else {
			int num = this->get_EmpNum();
			//cout << "公司人数为：" << num << "人" << endl;
			this->m_EmpNum = num;

			this->m_EmpArr = new Workers * [this->m_EmpNum];
			this->init_Emp();
		}
	}
}

void EmployeeManage::Show_Menu() {
	cout << "***********************************" << endl;
	cout << "*******欢迎使用员工管理系统********" << endl;
	cout << "********  0.退出管理系统  *********" << endl;
	cout << "********  1.增加员工信息  *********" << endl;
	cout << "********  2.显示员工信息  *********" << endl;
	cout << "********  3.删除离职员工  *********" << endl;
	cout << "********  4.修改职工信息  *********" << endl;
	cout << "********  5.查找职工信息  *********" << endl;
	cout << "********  6.按照编号排序  *********" << endl;
	cout << "********  7.清空所有文档  *********" << endl;
	cout << "***********************************" << endl;
}

void EmployeeManage::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	exit(0);
}

void EmployeeManage::addEmp() {
	cout << "请输入添加人员数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum + 1;
		Workers** newSpace = new Workers * [newSize];
		if (this->m_EmpNum != 0) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArr[i];
			}
		}
		//添加新成员
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "名新员工ID：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "名新员工姓名：" << endl;
			cin >> name;
			cout << "请选择新员工类型：\n1、普通员工\n2、部门经理\n3、董事会成员" << endl;
			cin >> dSelect;
			Workers* worker = NULL;
			switch (dSelect)
			{
			case 1:
				cout << "请输入普通员工进入的部门号：" << endl;
				int pid;
				cin >> pid;
				worker = new Employee(id, name, pid);
				break;
			case 2:
				cout << "请输入经理进入的部门号：" << endl;
				cin >> pid;
				worker = new Manager(id, name, pid);
				break;
			case 3:
				cout << "请输入该董事会成员代号：" << endl;
				cin >> pid;
				worker = new Boss(id, name, pid);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[]this->m_EmpArr;
		this->m_EmpArr = newSpace;
		this->m_EmpNum = newSize;
		cout << "成功添加" << addNum << "名新员工" << endl;
		//更新员工文件不为空
		this->m_FileIsEmpty = false;
		this->save();
		system("pause");
		system("cls");
	}
	else {
		cout << "请输入正确的人员数量" << endl;
	}
}

EmployeeManage::~EmployeeManage() {
	if (this->m_EmpArr != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArr[i] != NULL) {
				delete this->m_EmpArr[i];
			}
		}
		delete[]this->m_EmpArr;
		this->m_EmpArr = NULL;
	}
}

void EmployeeManage::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArr[i]->m_Id << ' '
			<< this->m_EmpArr[i]->m_Name << ' '
			<< this->m_EmpArr[i]->m_PostId << ' '
			<< this->m_EmpArr[i]->getPostName() << endl;
	}
	ofs.close();
}

int EmployeeManage::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	/*int id;
	string name;
	int pid;
	string pname;*/

	string buf;
	int cnt = 0;;
	while (getline(ifs, buf)) {
		cnt++;
	}
	return cnt;
}

void EmployeeManage::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::out);
	int id;
	string name;
	int pid;
	string pname;
	int index=0;
	while (ifs >> id && ifs >> name && ifs >> pid && ifs >> pname) {
		Workers* worker = NULL;
		if (id > 10000)//普通员工 
		{
			worker = new Employee(id, name, pid);
		}
		else if(id > 1000)//部门经理
		{
			worker = new Manager(id, name, pid);
		}
		else //董事会成员
		{
			worker = new Boss(id, name, pid);
		}
		this->m_EmpArr[index] = worker;
		index++;
	}
}

void EmployeeManage::show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int EmployeeManage::isExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArr[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void EmployeeManage::del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空，请先进行添加功能！" << endl;
	}
	else {
		//按照员工编号删除
		cout << "请输入需要删除的员工ID：" << endl;
		int id = 0;
		cin >> id;
		int index=this->isExist(id);
		if ( index!= -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArr[i] = this->m_EmpArr[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "已完成删除操作！" << endl;
		}
		else {
			cout << "你要删除的公司员工不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void EmployeeManage::mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入需要修改的成员ID：" << endl;
		int id;
		cin >> id;
		if (this->isExist(id) != -1) {
			int ret = this->isExist(id);
			if (ret != -1) {
				int newId = 0;
				string newName = "";
				int newPId = 0;
				int choice = 0;
				int branch = 1;
				cout << "已检索到ID为" << id << "成员！" << endl;
				while (branch) {
					cout << "请输入该成员需要修改的内容" << endl;
					cout << "1.ID修改\n2.姓名修改\n3.职位PID修改" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1: {
						cout << "请输入该成员的新ID：" << endl;
						cin >> newId;
						this->m_EmpArr[ret]->m_Id = newId;
						cout << "请问是否还要继续修改该成员信息：\n0.结束\n1.修改" << endl;
						cin >> branch;
						break;
					}
					case 2:
					{
						cout << "请输入该成员的新名字：" << endl;
						cin >> newName;
						this->m_EmpArr[ret]->m_Name = newName;
						cout << "请问是否还要继续修改该成员信息：\n0.结束\n1.修改" << endl;
						cin >> branch;
						break;
					}
					case 3:
					{
						newId = this->m_EmpArr[ret]->m_Id;
						newName = this->m_EmpArr[ret]->m_Name;
						newPId = this->m_EmpArr[ret]->m_PostId;
						delete this->m_EmpArr[ret];
						cout << "请输入该成员需要的新类型：\n1.普通员工\n2.部门经理\n3.董事会" << endl;
						int choice1 = 0;
						cin >> choice1;
						switch (choice1)
						{
						case 1: {
							Workers* worker = new Employee(newId, newName, newPId);
							this->m_EmpArr[ret] = worker;
							break;
						}
						case 2: {
							Workers* worker = new Manager(newId, newName, newPId);
							this->m_EmpArr[ret] = worker;
							break;
						}
						case 3: {
							Workers* worker = new Boss(newId, newName, newPId);
							this->m_EmpArr[ret] = worker;
							break;
						}
						default:
							break;
						}
						cout << "请问是否还要继续修改该成员信息：\n0.结束\n1.修改" << endl;
						cin >> branch;
					}
					default:
						break;
					}
				}
			}
			this->save();
			cout << "修改成功！" << endl;
		}
		else {
			cout << "你输入的ID成员不存在!" << endl;
		}
		system("pause");
		system("cls");
	}
}

void EmployeeManage::fine_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空!" << endl;
	}
	else {
		while (true) {
			cout << "请输入查找方式：" << endl;
			cout << "1.按成员ID查找" << endl;
			cout << "2.按成员姓名查找" << endl;
			int select = 0;
			cin >> select;
			if (select == 1) {
				cout << "请输入成员ID:" << endl;
				int id = 0;
				cin >> id;
				int ret = this->isExist(id);
				if (ret != -1) {
					this->m_EmpArr[ret]->showInfo();
				}
				else {
					cout << "你输入的ID成员不存在！" << endl;
				}
				break;
			}
			else if (select == 2) {
				cout << "请输入成员姓名:" << endl;
				string name = "";
				cin >> name;
				int cnt = 0;
				for (int i = 0; i < this->m_EmpNum; i++) {
					if (this->m_EmpArr[i]->m_Name == name) {
						this->m_EmpArr[i]->showInfo();
						cnt++;
					}
				}
				if (cnt > 1) {
					cout << "由于名字重复，请输入ID进行精确查找:" << endl;
					int id1 = 0;
					cin >> id1;
					int ret = this->isExist(id1);
					if (ret != -1) {
						this->m_EmpArr[ret]->showInfo();
					}
					else {
						cout << "请睁开眼睛输入正确的重名ID！" << endl;
					}
				}
				break;
			}
			else {
				cout << "请输入正确的查找方式！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void EmployeeManage::sort_Emp() {
	while (true) {
		cout << "请选择排序的方式：" << endl;
		cout << "1.正序" << endl;
		cout << "2.倒序" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++) {
					if (this->m_EmpArr[i]->m_Id > this->m_EmpArr[i + 1]->m_Id) {
						this->m_EmpArr[this->m_EmpNum] = this->m_EmpArr[i];
						this->m_EmpArr[i] = this->m_EmpArr[i + 1];
						this->m_EmpArr[i + 1] = this->m_EmpArr[this->m_EmpNum];
					}
				}
			}
			//delete[]this->m_EmpArr[m_EmpNum];
			this->save();
			cout << "已经按ID大小正序排列！" << endl;
			break;
		}
		else if (choice == 2) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++) {
					if (this->m_EmpArr[i]->m_Id < this->m_EmpArr[i + 1]->m_Id) {
						this->m_EmpArr[this->m_EmpNum] = this->m_EmpArr[i];
						this->m_EmpArr[i] = this->m_EmpArr[i + 1];
						this->m_EmpArr[i + 1] = this->m_EmpArr[this->m_EmpNum];
					}
				}
			}
			//delete[]this->m_EmpArr[m_EmpNum];
			this->save();
			cout << "已经按ID大小倒序排列！" << endl;
			break;
		}
		else {
			cout << "请输入正确的排序序号！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void EmployeeManage::empty_Emp() {
	cout << "是否确认格式化？" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArr[i] != NULL) {
					delete this->m_EmpArr[i];
				}
			}
		}
		this->m_EmpNum = 0;
		delete[]this->m_EmpArr;
		this->m_FileIsEmpty = true;
		this->m_EmpArr = NULL;
		cout << "已完成格式化！" << endl;
	}
	system("pause");
	system("cls");
}