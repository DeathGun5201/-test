#include<iostream>
#include<iomanip>
#include<string.h>
#include"UserMng.h"
#include"LinkList.h"


void AddUser(LinkList &L)
{
	if (L->next == NULL)
	{
		//头插法创建单链表
		int n, i;
		cout << "请输入用户的个数" << endl;
		cin >> n;
		L = new LNode;
		L->next = NULL;//L为头结点
		for (i = 0; i < n; i++)
		{
			LNode* p = new LNode;
			while (1)
			{
				cout << "请输入第" << i + 1 << "个用户的手机号" << endl;
				cin >> p->data.id;
				if (IsValid_UserId(p->data.id, n, L) == false)
					printf("输入格式错误！请重新输入！（可能是第一个数字不是1或者长度大于11位）\n");
				else
					break;
			}
			cout << "请输入第" << i + 1 << "个用户的昵称" << endl;
			cin >> p->data.name;
			cout << "请输入第" << i + 1 << "个用户的性别" << endl;
			cin >> p->data.sex;
			cout << "请输入第" << i + 1 << "个用户的年龄" << endl;
			cin >> p->data.age;
			p->next = L->next;
			//p = L->next;
			L->next = p;
		}
	}
	else
	{
		int n, i;
		cout << "请输入用户的个数" << endl;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			LNode* p = new LNode;
			while (1)
			{
				cout << "请输入第" << i + 1 << "个用户的手机号" << endl;
				cin >> p->data.id;
				if (IsValid_UserId(p->data.id, n, L) == false)
					printf("输入格式错误！请重新输入！（可能是第一个数字不是1或者长度大于11位）\n");
				else
					break;
			}
			cout << "请输入第" << i + 1 << "个用户的昵称" << endl;
			cin >> p->data.name;
			cout << "请输入第" << i + 1 << "个用户的性别" << endl;
			cin >> p->data.sex;
			cout << "请输入第" << i + 1 << "个用户的年龄" << endl;
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
		cout << "删除模块" << endl;
		cout << "请你选择删除方式\n1.按照手机号删除用户信息2.按照昵称删除用户信息0.退出删除模块" << endl;
		cin >> n;
		while (1)
		{
			switch (n)
			{
			case 1:
				while (1)
				{
					cout << "请输入你想要删除的用户的手机号" << endl;
					cin >> ID;//接下来要验证 你想要删除手机号是否存在
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
						cout << "你输入的用户的手机号不存在，请重新输入！！" << endl;
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
						cout << "你输入的用户的手机号不存在！" << endl;
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

				while ((p->next) && (j < i))//这里与上面结合，因此i不再是i-1了
				{
					p = p->next;
					++j;
				}
				if (!(p->next) || (j > i ))//这里同样不再是i-1了
					return ERROR;
				q = p->next;
				p->next = q->next;
				delete q;
				cout << "删除成功！" << endl;
				break;
			case 2://这里是根据用户昵称来进行用户信息的删除
				cout << "请输入你想要删除的用户的昵称" << endl;
				cin >> ID;
				p = L->next;
				while (p && p->data.name == ID)
				{
					cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
					cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
					p = p->next;
				}
				cout << "请输入你想要删除的用户的手机号";
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
				cout << "删除成功！" << endl;
				break; */
			case 0:
				break;
			default:cout << "请你按照要求输入指令！" << endl;
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
		cout << "手机号\t昵称\t性别\t年龄" << endl;
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


int ReviseUser(LinkList L)//修改用户
{
	LinkList p = L->next;
	int lin, count = 0, age;
	string clin1,clin;
	char sex;
	while (1)
	{
		cout << "1.用户号修改 2.昵称修改 3.性别修改 4.年龄修改 5.退出" << "\n";
		cout << "请选择：";
		cin >> lin;
		switch (lin)
		{
		case 1:
		{
			p = L->next;
			cout << "请输入要修改的用户号：";
			cin >> clin;
			//添加用户号查错的
			cout << "请输入修改后的用户号：";
			cin >> clin1;
			//用户号查错
			while (p && p->data.id!=clin)
			{
				p = p->next;
			}
			cout << "1.是 2.否";
			cout << "请选择是否修改：";
			cin >> lin;
			if (lin == 1)
				p->data.id = clin1;
			else
				continue;
			break;
		}
		//case 2:
		case 2://只写了查找还没写修改有点问题
		{
			while (1)
			{
				cout << "输入要查找的昵称：";
				cin >> clin1;
				cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
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
				cout << "请输入要修改昵称的用户的用户号：";
				cin >> clin;
				//添加用户号查错的
				p = L->next;
				while (p && p->data.id != clin)
				{
					/*cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
					if (cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n")
						count++;*/
					p = p->next;
				}
				if (count == 0)
					cout << "1.是 2.否";
				cout << "请选择是否修改：";
				cin >> lin;
				if (lin == 1)
				{
					/*cout << "1.重新输入 2.退出";
					cout << "没有该用户用户，请选择重新输入或退出：";
					cin >> lin;
					if (lin == 1)
						continue;
					cout << "请输入修改的昵称：";
					cin >> clin;*/
					cout << "请输入修改为什么昵称" ;
					cin >> clin1;
					p->data.name = clin1;
					cout << "改后用户信息如下" << endl;
					cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
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
			cout << "请输入要修改性别的用户的用户号：";
			cin >> clin;
			//添加用户号查错的
			while (p && p->data.id != clin)
			{
				p = p->next;
			}
			cout << "1.是 2.否";
			cout << "请选择是否修改：";
			cin >> lin;
			if (lin == 1)
			{
				cout << "请输入修改的性别：";
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

			cout << "请输入要修改年龄的用户的用户号：";
			cin >> clin;
			//添加用户号查错的
			while (p && p->data.id != clin)
			{
				p = p->next;
			}
			cout << "1.是 2.否";
			cout << "请选择是否修改：";
			cin >> lin;
			if (lin == 1)
			{
				cout << "请输入修改的年龄：";
				cin >> age;
				p->data.age = age;
			}
			else
				continue;
			break;
		}
		case 5:
		{
			cout << "1.确认 2.返回" << "\n";
			cout << "确认退出吗？\n";
			cout << "请选择";
			cin >> lin;
			if (lin == 1)
				return 0;
			else
				continue;
		}
		}
	}
}

void ShowUser(LinkList L)//显示用户信息
{
	LinkList p = L->next;
	cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
	while (p)
	{
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << "\n";
		p = p->next;
	}
	if (p == NULL)
	{
		cout << "请添加用户或从文件载入";
		system("pause");
	}
}

int SearchUser(LinkList L)//查找用户
{
	LinkList p = L->next;
	int lin, count = 0, age;
	string clin;
	char sex;
	while (1)
	{
		cout << "1.用户号查找 2.昵称查找 3.性别查找 4.年龄查找 5.退出" << "\n";
		cout << "请选择：";
		cin >> lin;
		switch (lin)
		{
		case 1:
		{
			p = L->next;
			cout << "请输入要查找的用户号：";
			cin >> clin;
			//添加用户号查错的
			while (p && p->data.id != clin)
			{
				p = p->next;
			}
			cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
			cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
			break;
		}
		case 2:
		{
			while (1)
			{
				p = L->next;
				cout << "输入要查找的昵称：";
				cin >> clin;
				cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
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
					cout << "输入要查找的昵称：";
					cin >> clin;
					cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
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
					cout << "1.重新输入 2.退出";
					cout << "没有该用户用户，请选择重新输入或退出：";
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
			cout << "输入要查找的性别：";
			cin >> sex;
			cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
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
			cout << "输入要查找的年龄：";
			cin >> age;
			cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
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
			cout << "1.确认 2.返回" << "\n";
			cout << "确认退出吗？\n";
			cout << "请选择";
			cin >> lin;
			if (lin == 1)
				return 0;
			else
				continue;
		}
		}
	}
}
