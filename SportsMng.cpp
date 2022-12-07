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
		int a, sport1, jie, lin;//i,j��������Ĵ�ѭ����a���������Сѭ��
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
		cin >> sport1;
		jie = EnQueue(p->data.sport, sport1);
		if (jie == -1)
		{
			cout << "1.ɾ�� 2.�˳�\n";
			cout << "��������ѡ��ɾ��Ԫ�ػ��˳���";
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


Status ReviseSport(LinkList L)
{
	string id;//�ֲ���������Ӱ��ȫ�ֱ���
	int n;
	cout << "����������Ҫ�޸ĵ��˶���Ϣ��Ӧ���û����ֻ���(ע��ֻ�ܹ��޸ĵ�����˶�����)" << endl;
	cin >> id;
	LNode* p=L->next;
	while (p && p->data.id != id)
		p = p->next;
	cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
	cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << "\n";
	ShowQueue(p->data.sport);
	cout << "�������޸ĺ���˶�����" << endl;
	cin >> n;
	ReviseSport2(p->data.sport,n);
	cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << "\n";
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

Status ShowSport(LinkList L)//��ʾ�����û������������˶���Ϣ
{
	LNode* p = L->next;
	while (p)
	{
		cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << std::left << setw(16) << "�˶�����"<<"\n";
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
		cout << "���û�Ŀǰ����δ�˶���" << endl;
	}
	m=QueueLength(Q);
	//cout << "��ʱ�ĳ���Ϊ" << m << "  ";//����������֪�����ٴΰ�����˶���Ϣû����ӽ�ȥ�˶����ݣ�ֻ�Ƕ�ԭ�����˶����ݽ����˸���
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

