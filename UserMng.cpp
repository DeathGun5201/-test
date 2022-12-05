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
