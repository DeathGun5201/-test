#include<iostream>
#include<iomanip>
#include<string.h>
#include"SportsMng.h"
#include"LinkList.h"
#include"Queue.h"
using namespace std;

Status addsport(LinkList L)//����˶���Ϣ
{
	int i,j;
	cout << "����Ҫ����û��ĸ�����";
	cin >> j;
	for (i = 0; i < j; i++)
	{
		int a, sport, jie, lin;//i,j��������Ĵ�ѭ����a���������Сѭ��
		string id;
		LinkList p = L->next;//�����ٴγ��������������ÿ��ʹ���������ֻ�Ḳ��ԭ�����˶����ݣ������ǽ��뵽�����
		//��������ԭ����for���棬���ǳ�����bug��ֻ�ܷ����棬��������ͬʱ¼�����û����˶�����
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
				if (id[0] != '1' || id[a] > 57 || id[a] < 48)
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
		jie = QueueLength(p->data.sport);
		if (jie == 7)
		{
			cout << "1.�� 2.��\n";
			cout << "��ɾ���������ݽ�������Ƿ����\n";
			cout << "��ѡ��:";
			cin >> lin;
			if (lin == 1)
			{
				DeQueue(p->data.sport);
				EnQueue(p->data.sport, sport);
				cout << "������\n";
			}
			else
			{
				cout << "�����˳�\n";
				system("pause");
				return 0;
			}
		}
		else
		{
			EnQueue(p->data.sport, sport);
			cout << "������";
			system("pause");
		}
	}
	return 0;
}

Status ReviseSport(LinkList L)
{
	string id;//�ֲ���������Ӱ��ȫ�ֱ���
	int n;
	cout << "����������Ҫ�޸ĵ��˶���Ϣ��Ӧ���û����ֻ���(ע��ֻ�ܹ��޸ĵ�����˶�����)" << endl;
	cin >> id;
	LNode* p=L->next;
	while (p && p->data.id != id)
		p = p->next;
	cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << setw(16) << "����" << "�˶�����\n";
	cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age ;
	ShowQueue(p->data.sport);
	cout << endl;
	cout << "�������޸ĺ���˶�����" << endl;
	cin >> n;
	ChangeQueueRear(p->data.sport, n);
	cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << setw(16) << "����" << "�˶�����\n";
	cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age;
	ShowQueue(p->data.sport);
	cout << endl;
	return 0;
}

Status ShowSport(LinkList L)//��ʾ�����û������������˶���Ϣ
{
	LNode* p = L->next;
	while (p)
	{
		cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << setw(16) << "����" << "�˶�����\n";
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age;
		ShowQueue(p->data.sport);
		cout << endl;
		p = p->next;
	}
	return 0;
}