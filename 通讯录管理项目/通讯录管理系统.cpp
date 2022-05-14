#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//菜单界面函数
void showMenu();
//设计联系人的结构体
struct Person {
	//姓名
	string P_name;
	//性别
	int P_sex;
	//年龄
	int P_age;
	//电话
	string P_phone;
	//住址
	string P_addr;


};
//通讯录的结构体；
struct Addressbooks {
	//通讯录中保持的联系人数组
	struct Person personArr[MAX];


	//通讯录中当前记录的联系人个数
	int P_size = 0;
};

//添加联系人函数
void addPerson(struct Addressbooks *abs);

//显示所有联系人函数                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
void showPerson(struct Addressbooks *abs);

int isExist(Addressbooks* abs, string name);
//删除已知联系人函数
void deletePerson(Addressbooks& abs);
//查找通讯录人员
void findPerson(Addressbooks* abs);

//编辑通讯录
void ediaPerson(Addressbooks* abs);
//清空通讯录
void cleanPerson(Addressbooks* abs);
int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	int select = 0;//创建用户选择输入的变量
	

	while (true) {

	
		showMenu();

		cin >> select;

		switch (select) {

		case 1://1、添加联系人
			addPerson(&abs);//利用地址传递修改传递的值
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人 
		{cout << "请输入删除的联系人姓名" << endl;
		string name;
		cin >> name;

		if (isExist(&abs, name) == -1) {
			cout << "查无此人" << endl;
		}
		else {
			cout << "找到此人" << endl;
		}}
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			ediaPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;

			system("pause");
			return 0;
			//break;
		default:
			break;
		}

	}
	
	
}
//菜单界面函数
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

//添加联系人
void addPerson(struct Addressbooks* abs) {
	//判断通讯录是否满了
	if ((*abs).P_size==MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		//添加姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		(*abs).personArr[(*abs).P_size].P_name = name;
		//性别
		cout << "请输入性别: " << endl;

		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				(*abs).personArr[(*abs).P_size].P_sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		
		//年龄
		/*string t = "12345678911";
		cout << "t占多少字节：" << sizeof(t) << endl;*/
		cout << "请输入年龄: " << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (0< age && age < 100) {
			
			(*abs).personArr[(*abs).P_size].P_age = age;
			break;
			}
			cout << "输入有误，请重新输入" << endl;
			
		}
		//电话
		cout << "请输入电话号码： " << endl;
		string phone;
		cin >> phone;
		(*abs).personArr[(*abs).P_size].P_phone = phone;
		
		
		//住址
		cout << "请输入住址： " << endl;

		string address;
		cin >> address;
		(*abs).personArr[(*abs).P_size].P_addr = address;

		(*abs).P_size++;

		cout << "添加成功！" << endl;

		
		system("pause");//任意建继续
		system("cls");//清频操作
	}
}

void showPerson(struct Addressbooks* abs) {
	//判断通讯录人数是否为0；
	if ((*abs).P_size == 0) {
		cout << "当前通讯录为空" << endl;
	}
	else {
		for (int i=0; i < (*abs).P_size; i++) {
			cout << "姓名：" << (*abs).personArr[i].P_name << "\t"
				<< "年龄：" << (*abs).personArr[i].P_age << "\t"
				<< "性别：" << ((*abs).personArr[i].P_sex ==1 ? "男":"女") << "\t"
				<< "地址：" << (*abs).personArr[i].P_addr << "\t"
				<< "电话：" << (*abs).personArr[i].P_phone << endl;
		}
	}
	system("pause");
	system("cls");
}

//检查联系人是否存在。

int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < (*abs).P_size; i++) {
		if ((*abs).personArr[i].P_name == name) {

			return i;
		}
	}
	return -1;

}

//删除指定联系人函数
void deletePerson(Addressbooks* abs) {

	cout << "请输入你要删除的联系人" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) { 
		for (int i = ret; i < (*abs).P_size; i++) {
			(*abs).personArr[i] = (*abs).personArr[i + 1];
		}
		(*abs).P_size++;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");

	}
}
//查找指定联系人函数
void findPerson(Addressbooks*abs) {
	cout << "请输入你需要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << (*abs).personArr[ret].P_name << "\t"
			<< "性别：" << ((*abs).personArr[ret].P_sex == 1 ? "男" : "女") << "\t"
			<< "年龄：" << (*abs).personArr[ret].P_age << "\t"
			<< "电话：" << (*abs).personArr[ret].P_phone << "\t"
			<< "住址：" << (*abs).personArr[ret].P_addr  << endl;

	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//修改联系人
void ediaPerson(Addressbooks* abs) {
	cout << "请输入您需要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != 1) {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		(*abs).personArr[ret].P_name = name;
		cout << "请输入性别" << endl;
		int sex;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				
				(*abs).personArr[ret].P_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		(*abs).personArr[ret].P_age = age;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		(*abs).personArr[ret].P_phone = phone;

		string address;
		cout << "请输入家庭住址" << endl;
		cin >> address;
		(*abs).personArr[ret].P_addr = address;

		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//清空通讯录
void cleanPerson(Addressbooks*abs) {

	(*abs).P_size = 0;

	cout << "通讯录已清空" << endl;

}