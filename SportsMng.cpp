#include<iostream>
#include<iomanip>
#include<string.h>
#include"SportsMng.h"
#include"LinkList.h"
#include"Queue.h"
using namespace std;

Status addsport(LinkList L)//添加运动信息
{
	int i,j;
	cout << "输入要添加用户的个数：";
	cin >> j;
	for (i = 0; i < j; i++)
	{
		int a, sport, jie, lin;//i,j用在外面的大循环，a用在里面的小循环
		string id;
		LinkList p = L->next;//问题再次出现在了这里，导致每次使用这个功能只会覆盖原来的运动数据，而不是接入到队列里！
		//上面三行原本在for外面，但是出现了bug，只能放里面，这样才能同时录入多个用户的运动数据
		while (1)
		{
			cout << "输入第" << i + 1 << "个要修改运动信息用户的用户号：";
			cin >> id;
			if (size(id) != 11)
			{
				cout << "位数不够请重新输入：";
				cin >> id;
				continue;
			}
			for (a = 0; a < 11; a++)
			{
				if (id[0] != '1' || id[a] > 57 || id[a] < 48)
				{
					cout << "输入格式有误请重新输入";
					break;
				}
			}
			if (a == 11)
				break;
			else
				continue;
		}
		while (p && p->data.id != id)
			p = p->next;
		cout << "请添加该用户当天的运动信息：";
		cin >> sport;
		jie = QueueLength(p->data.sport);
		if (jie == 7)
		{
			cout << "1.是 2.否\n";
			cout << "将删除最早数据进行添加是否继续\n";
			cout << "请选择:";
			cin >> lin;
			if (lin == 1)
			{
				DeQueue(p->data.sport);
				EnQueue(p->data.sport, sport);
				cout << "添加完成\n";
			}
			else
			{
				cout << "即将退出\n";
				system("pause");
				return 0;
			}
		}
		else
		{
			EnQueue(p->data.sport, sport);
			cout << "添加完成";
			system("pause");
		}
	}
	return 0;
}

Status ReviseSport(LinkList L)
{
	string id;//局部变量，不影响全局变量
	int n;
	cout << "请输入你想要修改的运动信息对应的用户的手机号(注：只能够修改当天的运动数据)" << endl;
	cin >> id;
	LNode* p=L->next;
	while (p && p->data.id != id)
		p = p->next;
	cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << setw(16) << "年龄" << "运动数据\n";
	cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age ;
	ShowQueue(p->data.sport);
	cout << endl;
	cout << "请输入修改后的运动数据" << endl;
	cin >> n;
	ChangeQueueRear(p->data.sport, n);
	cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << setw(16) << "年龄" << "运动数据\n";
	cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age;
	ShowQueue(p->data.sport);
	cout << endl;
	return 0;
}

Status ShowSport(LinkList L)//显示所有用户所有天数的运动信息
{
	LNode* p = L->next;
	while (p)
	{
		cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << setw(16) << "年龄" << "运动数据\n";
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age;
		ShowQueue(p->data.sport);
		cout << endl;
		p = p->next;
	}
	return 0;
}