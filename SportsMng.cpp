#include<iostream>
#include<iomanip>
#include<string.h>
#include"SportsMng.h"
#include"LinkList.h"
using namespace std;

void addsport(LinkList L)//����˶���Ϣ��Ҫ��ʼ����˶���Ϣ�Ĳ����ˣ��Ǹ���������д
{
	int i,j,a,sport;//i,j��������Ĵ�ѭ����a���������Сѭ��
	string id;
	LinkList p = L->next;
	cout << "����Ҫ����û��ĸ�����";
	cin >> j;
	for (i = 0; i < j; i++)
	{
		while (1)
		{
			cout << "�����" << i + 1 << "��Ҫ�޸��˶���Ϣ�û����û��ţ�";
			cin >> id;
			if (size(id) != 11)
			{
				cout << "λ���������������룺";
				cin >> id;
				continue;
			}
			for (a = 0; a < 11; a++)
			{
				if (id[0] != '1' || id[a]>57 || id[a]<48)
				{
					cout << "�����ʽ��������������";
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
		cout << "����Ӹ��û�������˶���Ϣ��";

	}
}