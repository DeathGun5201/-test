#include"LinkList.h"
#include<iostream>
#include<iomanip>
#include<string.h>
#include"UserMng.h"
using namespace std;

void AddUser(LinkList &L)
{
	int n,i;
	cout << "请输入用户的个数" << endl;
	cin >> n;
	L = new LNode;
	L->next = NULL;//L为头结点
	for (i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		while (1)
		{
			cout << "请输入第" << i+1 << "个用户的手机号" << endl;
			cin >> p->data.id;//p->data这里用的是指针类型，但是后面由于结构体嵌套不再是指针，用"."即可！
			//cout << p->data.id << endl;
			//cout << sizeof(p->data.id) << endl;
			//cout << size(p->data.id);
			//IsValid_UserId(p->data.id,n);

			if (IsValid_UserId(p->data.id,n,L) == false)
				printf("输入格式错误！请重新输入！（可能是第一个数字不是1或者长度大于11位）\n");
			else
				break;
		}
		cout << "请输入第" << i+1 << "个用户的昵称" << endl;
		cin >> p->data.name;
		cout << "请输入第" << i+1 << "个用户的性别" << endl;
		cin >> p->data.sex;
		cout << "请输入第" << i+1 << "个用户的年龄" << endl;
		cin >> p->data.age;
		p->next = L->next;
		p = L->next;
	}
}

bool IsValid_UserId(string Id,int n,LinkList &L)
{
	int num = size(Id);
	//cout << num << endl;
	//cout << Id[0] << endl;这些都是我的调试代码的代码，主要是为了调试
	if ((num == 11) && (Id[0] == '1'))
	{
		LNode* t = new LNode;
		t = L->next;
		//for (int i = 0; i < n; i++)
		//{
			//cout << "执行到了" << endl;
			//cout << t->data.id << endl;
			//t = t->next;
			/*if (t->data.id == Id)//可以使用这种关系运算符来比较字符串是否相等
			{
				printf("存在手机号相同的情况，请你重新检查！");
				break;
			}
			else
				t = t->next;*/
			//这里我明白原因了，就是我还没有输入完数据，还不能进行比较，只能是输入完之后再进行汇总比较，所以这里都是无用功
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

int ReviseUser(LinkList L)//修改用户
{
	LinkList p = L->next;
	int lin,count=0,age;
	string clin;
	char sex;
	while (1)
	{
		cout << "1.用户号修改 2.昵称修改 3.性别修改 4.年龄修改 5.退出"<<"\n";
		cout << "请选择：";
		cin >> lin;
		switch (lin)
		{
			case 1:
			{
				while (1)
				{
					cout << "请输入要修改的用户号：";
					cin >> clin;
					//添加用户号查错的
				}
				while (p && p->data.id != clin)
				{
					p = p->next;
				}
				cout << "请输入修改后的用户号：";
				cin >> clin;
				//用户号查错
				cout << "1.是 2.否";
				cout << "请选择是否修改：";
				cin >> lin;
				if (lin == 1)
					p->data.id = clin;
				else
					continue;
				break;
			}
			case 2://只写了查找还没写修改有点问题
			{
				while (1)
				{
					while (1)
					{
						cout << "请输入要修改昵称的用户的用户号：";
						cin >> clin;
						//添加用户号查错的
					}
					while (p && p->data.id != clin)
					{
						p = p->next;
					}
					cout << "1.是 2.否";
					cout << "请选择是否修改：";
					cin >> lin;
					if (lin == 1)
					{
						cout << "请输入修改的昵称：";
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
					cout << "请输入要修改性别的用户的用户号：";
					cin >> clin;
					//添加用户号查错的
				}
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
				while (1)
				{
					cout << "请输入要修改年龄的用户的用户号：";
					cin >> clin;
					//添加用户号查错的
				}
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
	cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄"<<"\n";
	while (p)
	{
		cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age<<"\n";
	}
}

int SearchUser(LinkList L)//查找用户
{
	LinkList p = L->next;
	int lin,count=0,age;
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
					cout << "请输入要查找的用户号：";
					cin >> clin;
					//添加用户号查错的
				}
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
					cout << "输入要查找的昵称：";
					cin >> clin;
					cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
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
						cout << "1.重新输入 2.退出";
						cout << "没有该用户用户，请选择重新输入或退出：";
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
				cout << "输入要查找的性别：";
				cin >> sex;
				cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
				while (p)
				{
					if(p->data.sex==sex)
						cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				}
				break;
			}
			case 4:
			{
				cout << "输入要查找的年龄：";
				cin >> age;
				cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
				while (p)
				{
					if (p->data.sex == sex)
						cout << std::left << setw(15) << p->data.id << std::left << setw(15) << p->data.name << std::left << setw(15) << p->data.sex << std::left << setw(15) << p->data.age << "\n";
				}
				break;
			}
			case 5:
			{
				cout << "1.确认 2.返回" << "\n";
				cout << "确认退出吗？\n";
				cout << "请选择";
				if (lin == 1)
					return 0;
				else
					continue;
			}
		}
	}
}