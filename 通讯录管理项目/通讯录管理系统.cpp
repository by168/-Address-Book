#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//�˵����溯��
void showMenu();
//�����ϵ�˵Ľṹ��
struct Person {
	//����
	string P_name;
	//�Ա�
	int P_sex;
	//����
	int P_age;
	//�绰
	string P_phone;
	//סַ
	string P_addr;


};
//ͨѶ¼�Ľṹ�壻
struct Addressbooks {
	//ͨѶ¼�б��ֵ���ϵ������
	struct Person personArr[MAX];


	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int P_size = 0;
};

//�����ϵ�˺���
void addPerson(struct Addressbooks *abs);

//��ʾ������ϵ�˺���                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
void showPerson(struct Addressbooks *abs);

int isExist(Addressbooks* abs, string name);
//ɾ����֪��ϵ�˺���
void deletePerson(Addressbooks& abs);
//����ͨѶ¼��Ա
void findPerson(Addressbooks* abs);

//�༭ͨѶ¼
void ediaPerson(Addressbooks* abs);
//���ͨѶ¼
void cleanPerson(Addressbooks* abs);
int main() {
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	int select = 0;//�����û�ѡ������ı���
	

	while (true) {

	
		showMenu();

		cin >> select;

		switch (select) {

		case 1://1�������ϵ��
			addPerson(&abs);//���õ�ַ�����޸Ĵ��ݵ�ֵ
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ�� 
		{cout << "������ɾ������ϵ������" << endl;
		string name;
		cin >> name;

		if (isExist(&abs, name) == -1) {
			cout << "���޴���" << endl;
		}
		else {
			cout << "�ҵ�����" << endl;
		}}
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			ediaPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;

			system("pause");
			return 0;
			//break;
		default:
			break;
		}

	}
	
	
}
//�˵����溯��
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

//�����ϵ��
void addPerson(struct Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�����
	if ((*abs).P_size==MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		//�������
		string name;
		cout << "������������" << endl;
		cin >> name;
		(*abs).personArr[(*abs).P_size].P_name = name;
		//�Ա�
		cout << "�������Ա�: " << endl;

		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				(*abs).personArr[(*abs).P_size].P_sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		
		//����
		/*string t = "12345678911";
		cout << "tռ�����ֽڣ�" << sizeof(t) << endl;*/
		cout << "����������: " << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (0< age && age < 100) {
			
			(*abs).personArr[(*abs).P_size].P_age = age;
			break;
			}
			cout << "������������������" << endl;
			
		}
		//�绰
		cout << "������绰���룺 " << endl;
		string phone;
		cin >> phone;
		(*abs).personArr[(*abs).P_size].P_phone = phone;
		
		
		//סַ
		cout << "������סַ�� " << endl;

		string address;
		cin >> address;
		(*abs).personArr[(*abs).P_size].P_addr = address;

		(*abs).P_size++;

		cout << "��ӳɹ���" << endl;

		
		system("pause");//���⽨����
		system("cls");//��Ƶ����
	}
}

void showPerson(struct Addressbooks* abs) {
	//�ж�ͨѶ¼�����Ƿ�Ϊ0��
	if ((*abs).P_size == 0) {
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i=0; i < (*abs).P_size; i++) {
			cout << "������" << (*abs).personArr[i].P_name << "\t"
				<< "���䣺" << (*abs).personArr[i].P_age << "\t"
				<< "�Ա�" << ((*abs).personArr[i].P_sex ==1 ? "��":"Ů") << "\t"
				<< "��ַ��" << (*abs).personArr[i].P_addr << "\t"
				<< "�绰��" << (*abs).personArr[i].P_phone << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڡ�

int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < (*abs).P_size; i++) {
		if ((*abs).personArr[i].P_name == name) {

			return i;
		}
	}
	return -1;

}

//ɾ��ָ����ϵ�˺���
void deletePerson(Addressbooks* abs) {

	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) { 
		for (int i = ret; i < (*abs).P_size; i++) {
			(*abs).personArr[i] = (*abs).personArr[i + 1];
		}
		(*abs).P_size++;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");

	}
}
//����ָ����ϵ�˺���
void findPerson(Addressbooks*abs) {
	cout << "����������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << (*abs).personArr[ret].P_name << "\t"
			<< "�Ա�" << ((*abs).personArr[ret].P_sex == 1 ? "��" : "Ů") << "\t"
			<< "���䣺" << (*abs).personArr[ret].P_age << "\t"
			<< "�绰��" << (*abs).personArr[ret].P_phone << "\t"
			<< "סַ��" << (*abs).personArr[ret].P_addr  << endl;

	}
	else {
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}

//�޸���ϵ��
void ediaPerson(Addressbooks* abs) {
	cout << "����������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != 1) {
		string name;
		cout << "����������" << endl;
		cin >> name;
		(*abs).personArr[ret].P_name = name;
		cout << "�������Ա�" << endl;
		int sex;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				
				(*abs).personArr[ret].P_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		

		int age;
		cout << "����������" << endl;
		cin >> age;
		(*abs).personArr[ret].P_age = age;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		(*abs).personArr[ret].P_phone = phone;

		string address;
		cout << "�������ͥסַ" << endl;
		cin >> address;
		(*abs).personArr[ret].P_addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}

//���ͨѶ¼
void cleanPerson(Addressbooks*abs) {

	(*abs).P_size = 0;

	cout << "ͨѶ¼�����" << endl;

}