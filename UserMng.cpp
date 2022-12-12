#include<iostream>
#include<iomanip>
#include<string.h>
#include"UserMng.h"
#include"LinkList.h"
#include"Queue.h"
#include<stdlib.h>

void AddUser(LinkList &L)
{
	if (L->next == NULL)
	{
		//ͷ�巨����������
		int n, i;
		cout << "�������û��ĸ���" << endl;
		cin >> n;
		L = new LNode;
		L->next = NULL;//LΪͷ���
		for (i = 0; i < n; i++)
		{
			LNode* p = new LNode;
			while (1)
			{
				cout << "�������" << i + 1 << "���û����ֻ���" << endl;
				cin >> p->data.id;
				if (IsValid_UserId(p->data.id, n, L) == false)
					printf("�����ʽ�������������룡�������ǵ�һ�����ֲ���1���߳��ȴ���11λ��\n");
				else
					break;
			}
			cout << "�������" << i + 1 << "���û����ǳ�" << endl;
			cin >> p->data.name;
			cout << "�������" << i + 1 << "���û����Ա�" << endl;
			cin >> p->data.sex;
			cout << "�������" << i + 1 << "���û�������" << endl;
			cin >> p->data.age;
			p->next = L->next;
			L->next = p;
			CreatQ(p->data.sport);
			cout << "��ӳɹ���" << endl;
			system("pause");
		}
	}
	else
	{
		int n, i;
		cout << "�������û��ĸ���" << endl;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			LNode* p = new LNode;
			while (1)
			{
				cout << "�������" << i + 1 << "���û����ֻ���" << endl;
				cin >> p->data.id;
				if (IsValid_UserId(p->data.id, n, L) == false)
					printf("�����ʽ�������������룡�������ǵ�һ�����ֲ���1���߳��ȴ���11λ��\n");
				else
					break;
			}
			CreatQ(p->data.sport);
			cout << "�������" << i + 1 << "���û����ǳ�" << endl;//���ﻹ���ж��ǳƵ�λ��
			cin >> p->data.name;
			while (1)
			{
				if (size(p->data.name) < 4 || size(p->data.name) > 12)
				{
					cout << "�ǳƵ�λ��Ҫ����4-12λ��������������" << endl;
					cin >> p->data.name;
				}
				else
				{
					break;
				}
			}
			cout << "�������" << i + 1 << "���û����Ա�(��:m   Ů:f)" << endl;
			cin >> p->data.sex;
			while (1)
			{
				if (p->data.sex == 'm' || p->data.sex == 'f')
					break;
				else
				{
					cout << "�밴�ո�ʽҪ���ٴ������Ա�" << endl;
					cin >> p->data.sex;
				}
			}
			cout << "�������" << i + 1 << "���û�������" << endl;
			cin >> p->data.age;
			p->next = L->next;
			L->next = p;
			cout << "��ӳɹ���" << endl;
			system("pause");
		}
	}
}

bool IsValid_UserId(string Id,int n,LinkList &L)
{
	int num = size(Id);
	if ((num == 11) && (Id[0] == '1'))
	{
		LNode* t = new LNode;
		t = L->next;
		return true;
	}	
	else
		return false;
	return 0;
}

int DeleteUser(LinkList &L)
{
	while (1)
	{
		system("cls");
		int n,m,i,j;		
		string ID,name1;
		LNode* p=new LNode;
		LNode* q=new LNode;
		LNode* t = new LNode;
		p = L; j = 0;
		cout << "�û�ɾ��" << endl;
		cout << "����ѡ��ɾ����ʽ\n1.�����ֻ���ɾ���û���Ϣ 2.�����ǳ�ɾ���û���Ϣ 0.�˳�ɾ��ģ��" << endl;
		cin >> n;
		while (1)
		{
			switch (n)
			{
			case 1:
				while (1)
				{
					cout << "����������Ҫɾ�����û����ֻ���" << endl;
					cin >> ID;//������Ҫ��֤ ����Ҫɾ���ֻ����Ƿ����
					m = 0;
					t = L->next;
					for (i = 0; i < LengthUser(L); i++)
					{
						if (ID == t->data.id)
						{
							m = 1;
							break;
						}
						else
						{
							t = t->next;
						}
					}
					if (m == 0)
					{
						cout << "��������û����ֻ��Ų����ڣ�" << endl;
						continue;
					}
					else
						break;
				}
				int  flag3;
				cout << "����ѡ���Ƿ�ɾ����1.�� 2.��" << endl;
				cin >> flag3;
				if (flag3 == 1)
				{
					while ((p->next) && (j < i))//�����������ϣ����i������i-1��
					{
						p = p->next;
						++j;
					}
					if (!(p->next) || (j > i))//����ͬ��������i-1��
						return ERROR;
					q = p->next;
					p->next = q->next;
					delete q;
					cout << "ɾ���ɹ���" << endl;
					system("pause");
					break;
				}
				else
				{
					break;
				}
			case 2://�����Ǹ����û��ǳ��������û���Ϣ��ɾ��
				cout << "����������Ҫɾ�����û����ǳ�" << endl;
				cin >> ID;
				p = L->next;
				while (p && p->data.name == ID)
				{
					cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << "����" << "\n";
					cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
					p = p->next;
				}
				while (1)
				{
					cout << "����������Ҫɾ�����û����ֻ���";
					cin >> ID;
					p = L;
					t = L->next;
					for (i = 0; i < LengthUser(L); i++)
					{
						if (ID == t->data.id)//�ҵ������id���˳�ѭ��
						{
							break;
						}
						else
						{
							t = t->next;
						}
					}
					if (t->next == NULL)
					{
						cout << "����Ҫɾ�����ֻ��Ų����ڣ����������룡" << endl;
						system("pause");
						break;
					}
					int flag;
					cout << "��ȷ���Ƿ�ɾ�����û���1.ȷ��  2.ȡ����" << endl;
					cin>>flag;
					if (flag == 1)
					{
						while ((p->next) && (j < i))
						{
							p = p->next;
							++j;
						}
						if (!(p->next) || (j > i))
							return ERROR;
						q = p->next;
						p->next = q->next;
						delete q;
						cout << "ɾ���ɹ���" << endl;
						system("pause");
						break;

					}
					else
					{
						break;
					}
					
					
				}
				
			case 0:
				break;
			default:
				cout << "���㰴��Ҫ������ָ�" << endl;
				break;
			}
			break;
		}
		if (n == 0)
		{
			break;
		}
	}
}

int LengthUser(LinkList& L)
{
	int count1 = 0;
	LNode* p = new LNode;
	p = L;
	while (p->next != NULL)
	{
		count1++;
		p = p->next;
	}
	return count1;
}

int ReviseUser(LinkList L)//�޸��û�
{
	LinkList p = L->next;
	int lin, count = 0, age, len;
	string id, changeid, name, changename;
	char sex;
	while (1)
	{
		system("cls");
		cout << "1.�û����޸� 2.�ǳ��޸� 3.�Ա��޸� 4.�����޸� 5.�˳�" << "\n";
		cout << "��ѡ��";
		cin >> lin;
		switch (lin)
		{
		case 1://������붼�ܼ������У���Ҫ�޸�
		{
			p = L->next;
			cout << "������Ҫ�޸ĵ��û��ţ�";
			cin >> id;
			//����û��Ų���
			cout << "�������޸ĺ���û��ţ�";
			cin >> changeid;
			//�û��Ų��
			while (p && p->data.id != id)
			{
				p = p->next;
			}
			cout << "1.�� 2.��";
			cout << "��ѡ���Ƿ��޸ģ�";
			cin >> lin;
			if (lin == 1)
				p->data.id = changeid;
			break;
		}
		case 2:
		{
			while (1)
			{
				p = L->next;
				cout << "����Ҫ���ҵ��ǳƣ�";
				cin >> name;
				while (p)
				{
					if (p->data.name == name)
					{
						count++;
						if (count == 1)
							cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << "\n";
						cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << "\n";
					}
					p = p->next;
				}
				if (count == 0)
				{
					cout << "1.�������� 2.�˳�\n";
					cout << "�Ҳ������û���ѡ������������˳���";
					cin >> lin;
					if (lin == 1)
						continue;
					else
						return 0;
				}
				count = 0;
				cout << "������Ҫ�޸��ǳƵ��û����û��ţ�";
				cin >> id;
				//����û��Ų���
				p = L->next;
				while (p && p->data.id != id)
				{
					count++;
					p = p->next;
				}
				if (count != 0)
				{
					cout << "1.�� 2.��\n";
					cout << "��ѡ���Ƿ��޸ģ�";
					cin >> lin;
					if (lin == 1)
					{
						cout << "�������޸ĵ��ǳƣ�";
						cin >> changename;
						p->data.name = changename;
						cout << "�ĺ��û���Ϣ����" << endl;
						cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << "\n";
						cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << "\n";
						system("pause");
					}
					else
					{
						cout << "1.�� 2.��\n";
						cout << "�Ƿ�ѡ���˳���";
						cin >> lin;
						if (lin == 1)
							return 0;
						else
							continue;
					}
				}
				break;
			}
			break;
		}
		case 3:
		{
			while (1)
			{
				system("cls");
				cout << "�û��Ա��޸�\n";
				p = L->next;
				count = 0;
				cout << "������Ҫ�޸��Ա���û����û��ţ�";
				cin >> id;
				//����û��Ų���
				while (p && p->data.id != id)
				{
					count++;
					p = p->next;
				}
				if (count == LengthUser(L))
				{
					cout << "δ�ҵ����û����������û��Ų����ڻ��������\n";
					cout << "1.���²��� 2.�˳�\n";
					cout << "��ѡ��";
					cin >> lin;
					if (lin == 1)
						continue;
					else
						return 0;
				}
				else
				{
					cout << "1.�� 2.��\n";
					cout << "��ѡ���Ƿ��޸ģ�";
					cin >> lin;
					if (lin == 1)
					{
						cout << "�������޸ĵ��Ա�";
						cin >> sex;
						p->data.sex = sex;
						cout << "�޸���ɣ��Ƿ�����޸�\n";
						cout << "1.�����޸� 2.�˳�";
						cout << "�����룺";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.���²��� 2.�˳�\n";
						cout << "��ѡ��";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
				}
			}
			break;
		}
		case 4:
		{
			while (1)
			{
				system("cls");
				cout << "�û������޸�\n";
				p = L->next;
				count = 0;
				cout << "������Ҫ�޸�������û����û��ţ�";
				cin >> id;
				//����û��Ų���
				while (p && p->data.id != id)
				{
					count++;
					p = p->next;
				}
				if (count == LengthUser(L))
				{
					cout << "δ�ҵ����û����������û��Ų����ڻ��������\n";
					cout << "1.���²��� 2.�˳�\n";
					cout << "��ѡ��";
					cin >> lin;
					if (lin == 1)
						continue;
					else
						return 0;
				}
				else
				{
					cout << "1.�� 2.��\n";
					cout << "��ѡ���Ƿ��޸ģ�";
					cin >> lin;
					if (lin == 1)
					{
						cout << "�������޸ĵ����䣺";
						cin >> age;
						p->data.age = age;
						cout << "�޸���ɣ��Ƿ�����޸�\n";
						cout << "1.�����޸� 2.�˳�";
						cout << "�����룺";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.���²��� 2.�˳�\n";
						cout << "��ѡ��";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
				}
			}
			break;
		}
		case 5:
		{
			cout << "1.ȷ�� 2.����" << endl;
			cout << "ȷ���˳���\n";
			cout << "��ѡ��";
			cin >> lin;
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
	if (p == NULL)
	{
		cout << "����������û�����ļ�����" << endl;;
		//system("pause");
	}
	else
	{
		cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << "����" << "\n";
		while (p)
		{
			cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
			p = p->next;
		}
	}
	system("pause");
}

int SearchUser(LinkList L)//�����û�
{
	LinkList p = L->next;
	int lin, count = 0, age;
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
					p = L->next;
					count = 0;
					cout << "������Ҫ���ҵ��û��ţ�";
					cin >> clin;
					//����û��Ų���
					while (p && p->data.id != clin)
					{
						p = p->next;
						count++;
					}
					if (count == LengthUser(L))
					{
						cout << "δ�ҵ����û����������û��Ų����ڻ��������\n";
						cout << "1.���²��� 2.�˳�\n";
						cout << "��ѡ��";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << "����" << "\n";
						cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
					}
				}
				break;
			}
			case 2:
			{
				while (1)
				{
					count = 0;
					p = L->next;
					cout << "����Ҫ���ҵ��ǳƣ�";
					cin >> clin;
					while (p)
					{
						if (p->data.name == clin)
						{
							count++;
							if (count == 1)
								cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << "����" << "\n";
							cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name <<setw(16)<<p->data.sex << p->data.age<< "\n";
						}
						p = p->next;
					}
					if (count == 0)
					{
						cout << "1.�������� 2.�˳�\n";
						cout << "�Ҳ������û���ѡ������������˳���";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.�� 2.�˳�\n";
						cout << "��ѡ���Ƿ�������ң�\n";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
				}
				break;
			}
			case 3:
			{
				while (1)
				{
					count = 0;
					p = L->next;
					cout << "����Ҫ���ҵ��Ա�";
					cin >> sex;
					while (p)
					{
						if (p->data.sex == sex)
						{
							count++;
							if (count == 1)
								cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << "����" << "\n";
							cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
						}
						p = p->next;
					}
					if (count == 0)
					{
						cout << "1.�������� 2.�˳�\n";
						cout << "�Ҳ������û���ѡ������������˳���";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.�� 2.�˳�\n";
						cout << "��ѡ���Ƿ�������ң�\n";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
				}
				break;
			}
			case 4:
			{
				while (1)
				{
					count = 0;
					p = L->next;
					cout << "����Ҫ���ҵ����䣺";
					cin >> age;
					while (p)
					{
						if (p->data.age == age)
						{
							count++;
							if (count == 1)
								cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << "����" << "\n";
							cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
						}
						p = p->next;
					}
					if (count == 0)
					{
						cout << "1.�������� 2.�˳�\n";
						cout << "�Ҳ������û���ѡ������������˳���";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.�� 2.�˳�\n";
						cout << "��ѡ���Ƿ�������ң�\n";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
				}
				break;
			}
			case 5:
			{
				cout << "1.ȷ�� 2.����" << "\n";
				cout << "ȷ���˳���\n";
				cout << "��ѡ��";
				cin >> lin;
				if (lin == 1)
					return 0;
				else
					continue;
			}
		}
	}
	return 0;
}