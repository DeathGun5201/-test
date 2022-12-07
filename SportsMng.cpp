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
		int a, sport1, jie, lin;//i,j用在外面的大循环，a用在里面的小循环
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
		cin >> sport1;
		jie = EnQueue(p->data.sport, sport1);
		if (jie == -1)
		{
			cout << "1.删除 2.退出\n";
			cout << "队满，请选择删除元素或退出：";
			cin >> lin;
			switch (lin)
			{
			case 1:
			{
				cout << "请输入删除个数：";
				cin >> lin;
				for (a = 0; a < lin; a++)
					DeQueue(p->data.sport);
				break;
			}
			case 2:
				return 0;
			}
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
	cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
	cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << "\n";
	ShowQueue(p->data.sport);
	cout << "请输入修改后的运动数据" << endl;
	cin >> n;
	ReviseSport2(p->data.sport,n);
	cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << "\n";
	cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << "\n";
	ShowQueue(p->data.sport);
	return 0;
}

Status ReviseSport2(SqQueue& Q,int n)
{
	int m;
	m = QueueLength(Q);
	Q.base[m - 1] = n;
	return 0;
}

Status ShowSport(LinkList L)//显示所有用户所有天数的运动信息
{
	LNode* p = L->next;
	while (p)
	{
		cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << std::left << setw(16) << "运动数据"<<"\n";
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age;
		ShowQueue(p->data.sport);cout << " "<<"\n";
		
		p = p->next;
	}
	return 0;
}

Status ShowQueue(SqQueue& Q)
{
	int m; int i = 0;
	if (Q.head == Q.rear)
	{
		cout << "该用户目前还尚未运动！" << endl;
	}
	m=QueueLength(Q);
	//cout << "此时的长度为" << m << "  ";//根据这里我知道了再次按添加运动信息没有添加进去运动数据，只是对原来的运动数据进行了覆盖
	for(i = 0; i < m; i++)
	{
		cout << Q.base[i];
	}
	/*while (Q.head != Q.rear)
	{

		cout << Q.base[Q.head];
		Q.head = (Q.head + 1) % 8;
	}*/
	return OK;
}

