#include"LinkList.h"
#include<iostream>
#include<iomanip>
#include<string.h>
#include"UserMng.h"
using namespace std;

void AddUser(LinkList &L)
{
	int n,i;
	cout << "�������û��ĸ���" << endl;
	cin >> n;
	L = new LNode;
	L->next = NULL;//LΪͷ���
	for (i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		while (1)
		{
			cout << "�������" << i+1 << "���û����ֻ���" << endl;
			cin >> p->data.id;//p->data�����õ���ָ�����ͣ����Ǻ������ڽṹ��Ƕ�ײ�����ָ�룬��"."���ɣ�
			//cout << p->data.id << endl;
			//cout << sizeof(p->data.id) << endl;
			//cout << size(p->data.id);
			//IsValid_UserId(p->data.id,n);

			if (IsValid_UserId(p->data.id,n,L) == false)
				printf("�����ʽ�������������룡�������ǵ�һ�����ֲ���1���߳��ȴ���11λ��\n");
			else
				break;
		}
		cout << "�������" << i+1 << "���û����ǳ�" << endl;
		cin >> p->data.name;
		cout << "�������" << i+1 << "���û����Ա�" << endl;
		cin >> p->data.sex;
		cout << "�������" << i+1 << "���û�������" << endl;
		cin >> p->data.age;
		p->next = L->next;
		p = L->next;
	}
}

bool IsValid_UserId(string Id,int n,LinkList &L)
{
	int num = size(Id);
	//cout << num << endl;
	//cout << Id[0] << endl;��Щ�����ҵĵ��Դ���Ĵ��룬��Ҫ��Ϊ�˵���
	if ((num == 11) && (Id[0] == '1'))
	{
		LNode* t = new LNode;
		t = L->next;
		//for (int i = 0; i < n; i++)
		//{
			//cout << "ִ�е���" << endl;
			//cout << t->data.id << endl;
			//t = t->next;
			/*if (t->data.id == Id)//����ʹ�����ֹ�ϵ��������Ƚ��ַ����Ƿ����
			{
				printf("�����ֻ�����ͬ��������������¼�飡");
				break;
			}
			else
				t = t->next;*/
			//����������ԭ���ˣ������һ�û�����������ݣ������ܽ��бȽϣ�ֻ����������֮���ٽ��л��ܱȽϣ��������ﶼ�����ù�
		//}
		return true;
	}	
	else
		return false;
	return 0;
}


void DeleteUser(LinkList& L)
{

}

int ReviseUser(LinkList L)//�޸��û�
{
	LinkList p = L->next;
	int lin,count=0,age;
	string clin;
	char sex;
	while (1)
	{
		cout << "1.�û����޸� 2.�ǳ��޸� 3.�Ա��޸� 4.�����޸� 5.�˳�"<<"\n";
		cout << "��ѡ��";
		cin >> lin;
		switch (lin)
		{
			case 1:
			{
				while (1)
				{
					cout << "������Ҫ�޸ĵ��û��ţ�";
					cin >> clin;
					//����û��Ų���
				}
				while (p && p->data.id != clin)
				{
					p = p->next;
				}
				cout << "�������޸ĺ���û��ţ�";
				cin >> clin;
				//�û��Ų��
				cout << "1.�� 2.��";
				cout << "��ѡ���Ƿ��޸ģ�";
				cin >> lin;
				if (lin == 1)
					p->data.id = clin;
				else
					continue;
				break;
			}
			case 2://ֻд�˲��һ�ûд�޸��е�����
			{
				while (1)
				{
					while (1)
					{
						cout << "������Ҫ�޸��ǳƵ��û����û��ţ�";
						cin >> clin;
						//����û��Ų���
					}
					while (p && p->data.id != clin)
					{
						p = p->next;
					}
					cout << "1.�� 2.��";
					cout << "��ѡ���Ƿ��޸ģ�";
					cin >> lin;
					if (lin == 1)
					{
						cout << "�������޸ĵ��ǳƣ�";
						cin >> clin;
						p->data.name = clin;
					}
					else
						continue;
					break;
				}
				
				break;
			}
			case 3:
			{
				while (1)
				{
					cout << "������Ҫ�޸��Ա���û����û��ţ�";
					cin >> clin;
					//����û��Ų���
				}
				while (p && p->data.id != clin)
				{
					p = p->next;
				}
				cout << "1.�� 2.��";
				cout << "��ѡ���Ƿ��޸ģ�";
				cin >> lin;
				if (lin == 1)
				{
					cout << "�������޸ĵ��Ա�";
					cin >> sex;
					p->data.sex = sex;
				}	
				else
					continue;
				break;
			}
			case 4:
			{
				while (1)
				{
					cout << "������Ҫ�޸�������û����û��ţ�";
					cin >> clin;
					//����û��Ų���
				}
				while (p && p->data.id != clin)
				{
					p = p->next;
				}
				cout << "1.�� 2.��";
				cout << "��ѡ���Ƿ��޸ģ�";
				cin >> lin;
				if (lin == 1)
				{
					cout << "�������޸ĵ����䣺";
					cin >> age;
					p->data.age = age;
				}
				else
					continue;
				break;
			}
			case 5:
			{
				cout << "1.ȷ�� 2.����" << "\n";
				cout << "ȷ���˳���\n";
				cout << "��ѡ��";
				if (lin == 1)
					return 0;
				else
					continue;
			}
		}
	}
}

void ShowUser(LinkList L)//��ʾ�û���Ϣ
{
	LinkList p = L->next;
	cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����"<<"\n";
	while (p)
	{
		cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age<<"\n";
	}
}

int SearchUser(LinkList L)//�����û�
{
	LinkList p = L->next;
	int lin,count=0,age;
	string clin;
	char sex;
	while (1)
	{
		cout << "1.�û��Ų��� 2.�ǳƲ��� 3.�Ա���� 4.������� 5.�˳�" << "\n";
		cout << "��ѡ��";
		cin >> lin;
		switch (lin)
		{
			case 1:
			{
				while (1)
				{
					cout << "������Ҫ���ҵ��û��ţ�";
					cin >> clin;
					//����û��Ų���
				}
				while (p && p->data.id != clin)
				{
					p = p->next;
				}
				cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
				cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				break;
			}
			case 2:
			{
				while (1)
				{
					cout << "����Ҫ���ҵ��ǳƣ�";
					cin >> clin;
					cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
					while (p)
					{
						if (p->data.name == clin)
							cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
						if (cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n")
							count++;
						p = p->next;
					}
					if (count == 0)
					{
						cout << "1.�������� 2.�˳�";
						cout << "û�и��û��û�����ѡ������������˳���";
						cin >> lin;
						if (lin == 1)
							continue;
					}
					if (lin == 2 && count == 0)
						break;
				}
				break;
			}
			case 3:
			{
				cout << "����Ҫ���ҵ��Ա�";
				cin >> sex;
				cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
				while (p)
				{
					if(p->data.sex==sex)
						cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				}
				break;
			}
			case 4:
			{
				cout << "����Ҫ���ҵ����䣺";
				cin >> age;
				cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
				while (p)
				{
					if (p->data.sex == sex)
						cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				}
				break;
			}
			case 5:
			{
				cout << "1.ȷ�� 2.����" << "\n";
				cout << "ȷ���˳���\n";
				cout << "��ѡ��";
				if (lin == 1)
					return 0;
				else
					continue;
			}
		}
	}
}