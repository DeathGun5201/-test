#include"LinkList.h"
#include<iostream>
using namespace std;
#include<string.h>
#include"UserMng.h"

void AddUser(LinkList &L)
{
	int n,i;
	cout << "�������û��ĸ���" << endl;
	cin >> n;
	L = new LNode;
	L->next = NULL;//LΪͷ���
	for (i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		while (1)
		{
			cout << "�������" << i << "���û����ֻ���" << endl;
			cin >> p->data.id;//p->data�����õ���ָ�����ͣ����Ǻ������ڽṹ��Ƕ�ײ�����ָ�룬��"."���ɣ�
			//cout << p->data.id << endl;
			//cout << sizeof(p->data.id) << endl;
			IsValid_UserId(p->data.id);

			if (IsValid_UserId(p->data.id) == false)
				printf("�����ʽ�������������룡\n");
			else
				break;

		}
		cout << "�������" << i << "���û����ǳ�" << endl;
		cin >> p->data.name;
		cout << "�������" << i << "���û����Ա�" << endl;
		cin >> p->data.sex;
		cout << "�������" << i << "���û�������" << endl;
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

