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
			L->next = p;
			CreatQ(p->data.sport);
			cout << "添加成功！" << endl;
			system("pause");
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
			CreatQ(p->data.sport);
			cout << "请输入第" << i + 1 << "个用户的昵称" << endl;//这里还得判断昵称的位数
			cin >> p->data.name;
			while (1)
			{
				if (size(p->data.name) < 4 || size(p->data.name) > 12)
				{
					cout << "昵称的位数要求是4-12位，请你重新输入" << endl;
					cin >> p->data.name;
				}
				else
				{
					break;
				}
			}
			cout << "请输入第" << i + 1 << "个用户的性别(男:m   女:f)" << endl;
			cin >> p->data.sex;
			while (1)
			{
				if (p->data.sex == 'm' || p->data.sex == 'f')
					break;
				else
				{
					cout << "请按照格式要求再次输入性别！" << endl;
					cin >> p->data.sex;
				}
			}
			cout << "请输入第" << i + 1 << "个用户的年龄" << endl;
			cin >> p->data.age;
			p->next = L->next;
			L->next = p;
			cout << "添加成功！" << endl;
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
		cout << "用户删除" << endl;
		cout << "请你选择删除方式\n1.按照手机号删除用户信息 2.按照昵称删除用户信息 0.退出删除模块" << endl;
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
				int  flag3;
				cout << "请你选择是否删除（1.是 2.否）" << endl;
				cin >> flag3;
				if (flag3 == 1)
				{
					while ((p->next) && (j < i))//这里与上面结合，因此i不再是i-1了
					{
						p = p->next;
						++j;
					}
					if (!(p->next) || (j > i))//这里同样不再是i-1了
						return ERROR;
					q = p->next;
					p->next = q->next;
					delete q;
					cout << "删除成功！" << endl;
					system("pause");
					break;
				}
				else
				{
					break;
				}
			case 2://这里是根据用户昵称来进行用户信息的删除
				cout << "请输入你想要删除的用户的昵称" << endl;
				cin >> ID;
				p = L->next;
				while (p && p->data.name == ID)
				{
					cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << "年龄" << "\n";
					cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
					p = p->next;
				}
				while (1)
				{
					cout << "请输入你想要删除的用户的手机号";
					cin >> ID;
					p = L;
					t = L->next;
					for (i = 0; i < LengthUser(L); i++)
					{
						if (ID == t->data.id)//找到了这个id，退出循环
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
						cout << "你想要删除的手机号不存在，请重新输入！" << endl;
						system("pause");
						break;
					}
					int flag;
					cout << "请确认是否删除此用户（1.确定  2.取消）" << endl;
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
						cout << "删除成功！" << endl;
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
				cout << "请你按照要求输入指令！" << endl;
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

int ReviseUser(LinkList L)//修改用户
{
	LinkList p = L->next;
	int lin, count = 0, age, len;
	string id, changeid, name, changename;
	char sex;
	while (1)
	{
		system("cls");
		cout << "1.用户号修改 2.昵称修改 3.性别修改 4.年龄修改 5.退出" << "\n";
		cout << "请选择：";
		cin >> lin;
		switch (lin)
		{
		case 1://随便输入都能继续进行，需要修改
		{
			p = L->next;
			cout << "请输入要修改的用户号：";
			cin >> id;
			//添加用户号查错的
			cout << "请输入修改后的用户号：";
			cin >> changeid;
			//用户号查错
			while (p && p->data.id != id)
			{
				p = p->next;
			}
			cout << "1.是 2.否";
			cout << "请选择是否修改：";
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
				cout << "输入要查找的昵称：";
				cin >> name;
				while (p)
				{
					if (p->data.name == name)
					{
						count++;
						if (count == 1)
							cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << "\n";
						cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << "\n";
					}
					p = p->next;
				}
				if (count == 0)
				{
					cout << "1.重新输入 2.退出\n";
					cout << "找不到该用户请选择重新输入或退出：";
					cin >> lin;
					if (lin == 1)
						continue;
					else
						return 0;
				}
				count = 0;
				cout << "请输入要修改昵称的用户的用户号：";
				cin >> id;
				//添加用户号查错的
				p = L->next;
				while (p && p->data.id != id)
				{
					count++;
					p = p->next;
				}
				if (count != 0)
				{
					cout << "1.是 2.否\n";
					cout << "请选择是否修改：";
					cin >> lin;
					if (lin == 1)
					{
						cout << "请输入修改的昵称：";
						cin >> changename;
						p->data.name = changename;
						cout << "改后用户信息如下" << endl;
						cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << "\n";
						cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << "\n";
						system("pause");
					}
					else
					{
						cout << "1.是 2.否\n";
						cout << "是否选择退出：";
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
				cout << "用户性别修改\n";
				p = L->next;
				count = 0;
				cout << "请输入要修改性别的用户的用户号：";
				cin >> id;
				//添加用户号查错的
				while (p && p->data.id != id)
				{
					count++;
					p = p->next;
				}
				if (count == LengthUser(L))
				{
					cout << "未找到该用户，可能是用户号不存在或输入错误\n";
					cout << "1.重新查找 2.退出\n";
					cout << "请选择：";
					cin >> lin;
					if (lin == 1)
						continue;
					else
						return 0;
				}
				else
				{
					cout << "1.是 2.否\n";
					cout << "请选择是否修改：";
					cin >> lin;
					if (lin == 1)
					{
						cout << "请输入修改的性别：";
						cin >> sex;
						p->data.sex = sex;
						cout << "修改完成，是否继续修改\n";
						cout << "1.继续修改 2.退出";
						cout << "请输入：";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.重新查找 2.退出\n";
						cout << "请选择：";
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
				cout << "用户年龄修改\n";
				p = L->next;
				count = 0;
				cout << "请输入要修改年龄的用户的用户号：";
				cin >> id;
				//添加用户号查错的
				while (p && p->data.id != id)
				{
					count++;
					p = p->next;
				}
				if (count == LengthUser(L))
				{
					cout << "未找到该用户，可能是用户号不存在或输入错误\n";
					cout << "1.重新查找 2.退出\n";
					cout << "请选择：";
					cin >> lin;
					if (lin == 1)
						continue;
					else
						return 0;
				}
				else
				{
					cout << "1.是 2.否\n";
					cout << "请选择是否修改：";
					cin >> lin;
					if (lin == 1)
					{
						cout << "请输入修改的年龄：";
						cin >> age;
						p->data.age = age;
						cout << "修改完成，是否继续修改\n";
						cout << "1.继续修改 2.退出";
						cout << "请输入：";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.重新查找 2.退出\n";
						cout << "请选择：";
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
			cout << "1.确认 2.返回" << endl;
			cout << "确认退出吗？\n";
			cout << "请选择：";
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
	if (p == NULL)
	{
		cout << "请您先添加用户或从文件载入" << endl;;
		//system("pause");
	}
	else
	{
		cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << "年龄" << "\n";
		while (p)
		{
			cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
			p = p->next;
		}
	}
	system("pause");
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
				while (1)
				{
					p = L->next;
					count = 0;
					cout << "请输入要查找的用户号：";
					cin >> clin;
					//添加用户号查错的
					while (p && p->data.id != clin)
					{
						p = p->next;
						count++;
					}
					if (count == LengthUser(L))
					{
						cout << "未找到该用户，可能是用户号不存在或输入错误\n";
						cout << "1.重新查找 2.退出\n";
						cout << "请选择：";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << "年龄" << "\n";
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
					cout << "输入要查找的昵称：";
					cin >> clin;
					while (p)
					{
						if (p->data.name == clin)
						{
							count++;
							if (count == 1)
								cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << "年龄" << "\n";
							cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name <<setw(16)<<p->data.sex << p->data.age<< "\n";
						}
						p = p->next;
					}
					if (count == 0)
					{
						cout << "1.重新输入 2.退出\n";
						cout << "找不到该用户请选择重新输入或退出：";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.是 2.退出\n";
						cout << "请选择是否继续查找：\n";
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
					cout << "输入要查找的性别：";
					cin >> sex;
					while (p)
					{
						if (p->data.sex == sex)
						{
							count++;
							if (count == 1)
								cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << "年龄" << "\n";
							cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
						}
						p = p->next;
					}
					if (count == 0)
					{
						cout << "1.重新输入 2.退出\n";
						cout << "找不到该用户请选择重新输入或退出：";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.是 2.退出\n";
						cout << "请选择是否继续查找：\n";
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
					cout << "输入要查找的年龄：";
					cin >> age;
					while (p)
					{
						if (p->data.age == age)
						{
							count++;
							if (count == 1)
								cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << "年龄" << "\n";
							cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << p->data.age << "\n";
						}
						p = p->next;
					}
					if (count == 0)
					{
						cout << "1.重新输入 2.退出\n";
						cout << "找不到该用户请选择重新输入或退出：";
						cin >> lin;
						if (lin == 1)
							continue;
						else
							return 0;
					}
					else
					{
						cout << "1.是 2.退出\n";
						cout << "请选择是否继续查找：\n";
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
	return 0;
}