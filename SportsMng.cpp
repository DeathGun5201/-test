#include<iostream>
#include<iomanip>
#include<string.h>
#include"SportsMng.h"
#include"LinkList.h"
using namespace std;

void addsport(LinkList L)//添加运动信息，要开始添加运动信息的步骤了，是个队列明天写
{
	int i,j,a,sport;//i,j用在外面的大循环，a用在里面的小循环
	string id;
	LinkList p = L->next;
	cout << "输入要添加用户的个数：";
	cin >> j;
	for (i = 0; i < j; i++)
	{
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
				if (id[0] != '1' || id[a]>57 || id[a]<48)
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

	}
}