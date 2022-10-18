#include"EmployeeManage.h"
#include"Employee.h"
#include"Boss.h"
#include"Manager.h"

EmployeeManage::EmployeeManage() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�������ļ������ڣ�" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArr = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else {
		//�ļ����ڣ�����Ϊ��
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			cout << "�ļ�Ϊ�գ�" << endl;
			this->m_EmpNum = 0;
			this->m_EmpArr = NULL;
			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}//�ļ������Ҳ�Ϊ��
		else {
			int num = this->get_EmpNum();
			//cout << "��˾����Ϊ��" << num << "��" << endl;
			this->m_EmpNum = num;

			this->m_EmpArr = new Workers * [this->m_EmpNum];
			this->init_Emp();
		}
	}
}

void EmployeeManage::Show_Menu() {
	cout << "***********************************" << endl;
	cout << "*******��ӭʹ��Ա������ϵͳ********" << endl;
	cout << "********  0.�˳�����ϵͳ  *********" << endl;
	cout << "********  1.����Ա����Ϣ  *********" << endl;
	cout << "********  2.��ʾԱ����Ϣ  *********" << endl;
	cout << "********  3.ɾ����ְԱ��  *********" << endl;
	cout << "********  4.�޸�ְ����Ϣ  *********" << endl;
	cout << "********  5.����ְ����Ϣ  *********" << endl;
	cout << "********  6.���ձ������  *********" << endl;
	cout << "********  7.��������ĵ�  *********" << endl;
	cout << "***********************************" << endl;
}

void EmployeeManage::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	exit(0);
}

void EmployeeManage::addEmp() {
	cout << "�����������Ա������" << endl;
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
		//����³�Ա
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����Ա��ID��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����Ա��������" << endl;
			cin >> name;
			cout << "��ѡ����Ա�����ͣ�\n1����ͨԱ��\n2�����ž���\n3�����»��Ա" << endl;
			cin >> dSelect;
			Workers* worker = NULL;
			switch (dSelect)
			{
			case 1:
				cout << "��������ͨԱ������Ĳ��źţ�" << endl;
				int pid;
				cin >> pid;
				worker = new Employee(id, name, pid);
				break;
			case 2:
				cout << "�����뾭�����Ĳ��źţ�" << endl;
				cin >> pid;
				worker = new Manager(id, name, pid);
				break;
			case 3:
				cout << "������ö��»��Ա���ţ�" << endl;
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
		cout << "�ɹ����" << addNum << "����Ա��" << endl;
		//����Ա���ļ���Ϊ��
		this->m_FileIsEmpty = false;
		this->save();
		system("pause");
		system("cls");
	}
	else {
		cout << "��������ȷ����Ա����" << endl;
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
		if (id > 10000)//��ͨԱ�� 
		{
			worker = new Employee(id, name, pid);
		}
		else if(id > 1000)//���ž���
		{
			worker = new Manager(id, name, pid);
		}
		else //���»��Ա
		{
			worker = new Boss(id, name, pid);
		}
		this->m_EmpArr[index] = worker;
		index++;
	}
}

void EmployeeManage::show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ�գ����Ƚ�����ӹ��ܣ�" << endl;
	}
	else {
		//����Ա�����ɾ��
		cout << "��������Ҫɾ����Ա��ID��" << endl;
		int id = 0;
		cin >> id;
		int index=this->isExist(id);
		if ( index!= -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArr[i] = this->m_EmpArr[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "�����ɾ��������" << endl;
		}
		else {
			cout << "��Ҫɾ���Ĺ�˾Ա�������ڣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void EmployeeManage::mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������Ҫ�޸ĵĳ�ԱID��" << endl;
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
				cout << "�Ѽ�����IDΪ" << id << "��Ա��" << endl;
				while (branch) {
					cout << "������ó�Ա��Ҫ�޸ĵ�����" << endl;
					cout << "1.ID�޸�\n2.�����޸�\n3.ְλPID�޸�" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1: {
						cout << "������ó�Ա����ID��" << endl;
						cin >> newId;
						this->m_EmpArr[ret]->m_Id = newId;
						cout << "�����Ƿ�Ҫ�����޸ĸó�Ա��Ϣ��\n0.����\n1.�޸�" << endl;
						cin >> branch;
						break;
					}
					case 2:
					{
						cout << "������ó�Ա�������֣�" << endl;
						cin >> newName;
						this->m_EmpArr[ret]->m_Name = newName;
						cout << "�����Ƿ�Ҫ�����޸ĸó�Ա��Ϣ��\n0.����\n1.�޸�" << endl;
						cin >> branch;
						break;
					}
					case 3:
					{
						newId = this->m_EmpArr[ret]->m_Id;
						newName = this->m_EmpArr[ret]->m_Name;
						newPId = this->m_EmpArr[ret]->m_PostId;
						delete this->m_EmpArr[ret];
						cout << "������ó�Ա��Ҫ�������ͣ�\n1.��ͨԱ��\n2.���ž���\n3.���»�" << endl;
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
						cout << "�����Ƿ�Ҫ�����޸ĸó�Ա��Ϣ��\n0.����\n1.�޸�" << endl;
						cin >> branch;
					}
					default:
						break;
					}
				}
			}
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
		else {
			cout << "�������ID��Ա������!" << endl;
		}
		system("pause");
		system("cls");
	}
}

void EmployeeManage::fine_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		while (true) {
			cout << "��������ҷ�ʽ��" << endl;
			cout << "1.����ԱID����" << endl;
			cout << "2.����Ա��������" << endl;
			int select = 0;
			cin >> select;
			if (select == 1) {
				cout << "�������ԱID:" << endl;
				int id = 0;
				cin >> id;
				int ret = this->isExist(id);
				if (ret != -1) {
					this->m_EmpArr[ret]->showInfo();
				}
				else {
					cout << "�������ID��Ա�����ڣ�" << endl;
				}
				break;
			}
			else if (select == 2) {
				cout << "�������Ա����:" << endl;
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
					cout << "���������ظ���������ID���о�ȷ����:" << endl;
					int id1 = 0;
					cin >> id1;
					int ret = this->isExist(id1);
					if (ret != -1) {
						this->m_EmpArr[ret]->showInfo();
					}
					else {
						cout << "�������۾�������ȷ������ID��" << endl;
					}
				}
				break;
			}
			else {
				cout << "��������ȷ�Ĳ��ҷ�ʽ��" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void EmployeeManage::sort_Emp() {
	while (true) {
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
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
			cout << "�Ѿ���ID��С�������У�" << endl;
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
			cout << "�Ѿ���ID��С�������У�" << endl;
			break;
		}
		else {
			cout << "��������ȷ��������ţ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void EmployeeManage::empty_Emp() {
	cout << "�Ƿ�ȷ�ϸ�ʽ����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;

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
		cout << "����ɸ�ʽ����" << endl;
	}
	system("pause");
	system("cls");
}