#include<iostream>
#include<iomanip>
#include<string.h>
#include"UserMng.h"
#include"LinkList.h"


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
			//p = L->next;
			L->next = p;
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
			cout << "�������" << i + 1 << "���û����ǳ�" << endl;
			cin >> p->data.name;
			cout << "�������" << i + 1 << "���û����Ա�" << endl;
			cin >> p->data.sex;
			cout << "�������" << i + 1 << "���û�������" << endl;
			cin >> p->data.age;
			p->next = L->next;
			//p = L->next;
			L->next = p;
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
		int n,m,i,j;		
		string ID,name1;
		LNode* p=new LNode;
		LNode* q=new LNode;
		LNode* t = new LNode;
		p = L; j = 0;
		cout << "ɾ��ģ��" << endl;
		cout << "����ѡ��ɾ����ʽ\n1.�����ֻ���ɾ���û���Ϣ2.�����ǳ�ɾ���û���Ϣ0.�˳�ɾ��ģ��" << endl;
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
					/*m = 0;
					p = L->next;
					while (1)
					{
						if (p && p->data.id == ID)
						{
							m++;
							break;
						}
						else
						{
							p = p->next;
						}
					}
					if (m == 1)
					{
						break;
					}
					else
					{
						cout << "��������û����ֻ��Ų����ڣ����������룡��" << endl;
						continue;
					}*/
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
					
				
				
				/*while (p != NULL)
				{
					if (ID ==p->data.id)
					{
						q = p->next;
						p->next = q->next;
						delete q;
					}
					else
					{
						p = p->next;
					}
				}*/

				while ((p->next) && (j < i))//�����������ϣ����i������i-1��
				{
					p = p->next;
					++j;
				}
				if (!(p->next) || (j > i ))//����ͬ��������i-1��
					return ERROR;
				q = p->next;
				p->next = q->next;
				delete q;
				cout << "ɾ���ɹ���" << endl;
				break;
			case 2://�����Ǹ����û��ǳ��������û���Ϣ��ɾ��
				cout << "����������Ҫɾ�����û����ǳ�" << endl;
				cin >> ID;
				p = L->next;
				while (p && p->data.name == ID)
				{
					cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
					cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
					p = p->next;
				}
				cout << "����������Ҫɾ�����û����ֻ���";
				cin >> ID;
				p = L;
				t = L->next;
				for (i = 0; i < LengthUser(L); i++)
				{
					if (ID == t->data.id)
					{
						break;
					}
					else
					{
						t = t->next;
					}
				}
				/*while (p != NULL)
				{
					if (ID ==p->data.id)
					{
						q = p->next;
						p->next = q->next;
						delete q;
					}
					else
					{
						p = p->next;
					}
				}*/

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
				//while (p && p->data.id != ID)
				//{
					//p = p->next;
				//}
				
				/*for (i = 0; i < LengthUser(L); i++)
				{
					t = L->next;
					if (ID == t->data.name)
					{
						m = i;
					}
				}
				//while (p != NULL)
				//{
					//if (ID ==p->data.id)
					//{
						//q = p->next;
						//p->next = q->next;
						//delete q;
					//}
					//else
					//{
						//p = p->next;
					//}
				//}
				while ((p->next) && (j < i - 1))
				{
					p = p->next;
					++j;
				}
				if (!(p->next) || (j > i - 1))
					return ERROR;
				q = p->next;
				p->next = q->next;
				delete q;
				cout << "ɾ���ɹ���" << endl;
				break; */
			case 0:
				break;
			default:cout << "���㰴��Ҫ������ָ�" << endl;
				break;
			}
			break;
		}
		//system("pause");
		//system("cls");
		if (n == 0)
		{
			break;
		}
	}
}
/*void ShowUser(LinkList& L)
{
	LNode* p = L->next;
	while (p != NULL)
	{
		cout << "�ֻ���\t�ǳ�\t�Ա�\t����" << endl;
		cout << p->data.id << "\t" << p->data.name << "\t" << p->data.sex << "\t" << p->data.age << endl;
		p = p->next;
	}
}*/
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
	int lin, count = 0, age;
	string clin1,clin;
	char sex;
	while (1)
	{
		cout << "1.�û����޸� 2.�ǳ��޸� 3.�Ա��޸� 4.�����޸� 5.�˳�" << "\n";
		cout << "��ѡ��";
		cin >> lin;
		switch (lin)
		{
		case 1:
		{
			p = L->next;
			cout << "������Ҫ�޸ĵ��û��ţ�";
			cin >> clin;
			//����û��Ų���
			cout << "�������޸ĺ���û��ţ�";
			cin >> clin1;
			//�û��Ų��
			while (p && p->data.id!=clin)
			{
				p = p->next;
			}
			cout << "1.�� 2.��";
			cout << "��ѡ���Ƿ��޸ģ�";
			cin >> lin;
			if (lin == 1)
				p->data.id = clin1;
			else
				continue;
			break;
		}
		//case 2:
		case 2://ֻд�˲��һ�ûд�޸��е�����
		{
			while (1)
			{
				cout << "����Ҫ���ҵ��ǳƣ�";
				cin >> clin1;
				cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
				/*while (p)
				{
					if(p->data.name == clin)
					{
						cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
						if (p->data.id != clin)
						{

						}
					}
					
					p = p->next;
				}*/
				while (p && p->data.name == clin1)
				{
					cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
					p = p->next;
				}
				cout << "������Ҫ�޸��ǳƵ��û����û��ţ�";
				cin >> clin;
				//����û��Ų���
				p = L->next;
				while (p && p->data.id != clin)
				{
					/*cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
					if (cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n")
						count++;*/
					p = p->next;
				}
				if (count == 0)
					cout << "1.�� 2.��";
				cout << "��ѡ���Ƿ��޸ģ�";
				cin >> lin;
				if (lin == 1)
				{
					/*cout << "1.�������� 2.�˳�";
					cout << "û�и��û��û�����ѡ������������˳���";
					cin >> lin;
					if (lin == 1)
						continue;
					cout << "�������޸ĵ��ǳƣ�";
					cin >> clin;*/
					cout << "�������޸�Ϊʲô�ǳ�" ;
					cin >> clin1;
					p->data.name = clin1;
					cout << "�ĺ��û���Ϣ����" << endl;
					cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
					cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				}
				if (lin == 2/* && count == 0*/)
					break;
				break;
			}

			break;
		}
		case 3:
		{
			p = L->next;
			cout << "������Ҫ�޸��Ա���û����û��ţ�";
			cin >> clin;
			//����û��Ų���
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
			p = L->next;

			cout << "������Ҫ�޸�������û����û��ţ�";
			cin >> clin;
			//����û��Ų���
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
	cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
	while (p)
	{
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << "\n";
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "������û�����ļ�����";
		system("pause");
	}
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
			p = L->next;
			cout << "������Ҫ���ҵ��û��ţ�";
			cin >> clin;
			//����û��Ų���
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
				p = L->next;
				cout << "����Ҫ���ҵ��ǳƣ�";
				cin >> clin;
				cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
				/*while (p)
				{
					if(p->data.name == clin)
					{
						cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
						if (p->data.id != clin)
						{

						}
					}

					p = p->next;
				}*/
				while (p && p->data.name == clin)
				{
					cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
					p = p->next;
				}
				break;

				/*while (1)
				{
					cout << "����Ҫ���ҵ��ǳƣ�";
					cin >> clin;
					cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
					while (p)
					{
						if (p->data.name == clin)
							cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
						//if (cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n")
							//count++;
						else
						{
							p = p->next;
						}
					}
					break;
				}*/
				
				/*if (count == 0)
				{
					cout << "1.�������� 2.�˳�";
					cout << "û�и��û��û�����ѡ������������˳���";
					cin >> lin;
					if (lin == 1)
						continue;
				}
				if (lin == 2 && count == 0)
					break;*/
			}
			break;
		}
		case 3:
		{
			p = L->next;
			cout << "����Ҫ���ҵ��Ա�";
			cin >> sex;
			cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
			while (p)
			{
				if (p->data.sex == sex)
					cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				p = p->next;
			}
			break;
		}
		case 4:
		{
			p = L->next;
			cout << "����Ҫ���ҵ����䣺";
			cin >> age;
			cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
			while (p)
			{
				if (p->data.age == age)
					cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				p = p->next;
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
}
