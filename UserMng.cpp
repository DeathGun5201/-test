#include"LinkList.h"
#include<iostream>
using namespace std;
#include<string.h>
#include"UserMng.h"

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
			cout << "请输入第" << i << "个用户的手机号" << endl;
			cin >> p->data.id;//p->data这里用的是指针类型，但是后面由于结构体嵌套不再是指针，用"."即可！
			//cout << p->data.id << endl;
			//cout << sizeof(p->data.id) << endl;
			IsValid_UserId(p->data.id);

			if (IsValid_UserId(p->data.id) == false)
				printf("输入格式错误！请重新输入！\n");
			else
				break;

		}
		cout << "请输入第" << i << "个用户的昵称" << endl;
		cin >> p->data.name;
		cout << "请输入第" << i << "个用户的性别" << endl;
		cin >> p->data.sex;
		cout << "请输入第" << i << "个用户的年龄" << endl;
		cin >> p->data.age;
		p->next = L->next;
		p = L->next;
	}
}

bool IsValid_UserId(string Id)
{
	int num = size(Id);
	//cout << num << endl;
	if (num == 12)
		return true;
	else
		return false;
	return 0;
}

