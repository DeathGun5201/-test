#include<iostream>
#include<iomanip>
#include<string.h>
#include"SportsMng.h"
#include"LinkList.h"
#include"Queue.h"
using namespace std;

Status addsport(LinkList L)//����˶���Ϣ
{
	int i,j,a,sport,jie,lin;//i,j��������Ĵ�ѭ����a���������Сѭ��
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
		cin >> sport;
		jie=EnQueue(p->data.sport, sport);
		if (jie == -1)
		{
			cout << "1.ɾ�� 2.�˳�\n";
			cout << "ջ������ѡ��ɾ��Ԫ�ػ��˳���";
			cin >> lin;
			switch (lin)
			{
				case 1:
				{
					cout << "������ɾ��������";
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