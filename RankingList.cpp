#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include"LinkList.h"
using namespace std;

Status todaylist(LinkList L)//�����˶����а�
{
	string id[1000],toid;
	int todaysport[1000],i=0,j,lin;
	LinkList p=L->next;
	while (p)
	{
		id[i] = p->data.id;//������������id¼�뵽�ַ���������
		if (0 < p->data.sport.rear <= 7)//if,else¼�뵱���˶�����
			todaysport[i] = p->data.sport.base[p->data.sport.rear - 1];
		else
		{
			todaysport[i] = p->data.sport.base[7];
		}
		i++;
	}
	for (i = 0; i < 1000 - 1; i++)//�����˶��������ð�����򣬶Խ����˶����������λ��ʱ˳�㽫id��˳��ı�
	{
		for (j = 0; j < 1000 - 1 - i; j++)
		{
			if (todaysport[j] > todaysport[j + 1])
			{
				lin = todaysport[j + 1];
				toid = id[j + 1];
				todaysport[j + 1] = todaysport[j];
				id[j + 1] = id[j];
				todaysport[j] = lin;
				id[j] = toid;
			}
		}
	}
	cout << "�����˶����а�\n";
	cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << std::left << setw(16) << "�����˶�����" "\n";
	for (i = 0; i < 1000; i++)
	{
		p = L->next;//ÿ��forѭ����ʼָ��ȥ
		while (p && p->data.id != id[i])//�ҵ�id����ʾ��Ϣ
			p = p->next;
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << std::left << setw(16) << todaysport[i]<<endl;
	}
	return 0;
}

Status serlist(LinkList L)//�����˶����а�
{
	int sersport[1000], i = 0, j=0, k=0;//sersport�洢ÿ���û���������˶�����
	int sport[7],day[7],count=0,daycount=0,lin;//sport�����洢���û��˶����ݣ�day�����洢�����˶�����
	string id[1000], toid;//id����洢�û�id
	LinkList p = L->next;
	while (p)
	{
		j = 0;//��ͷ��ʼ�������ڴ洢�û��˶�����
		day[7] = { 0 };//��ͷ��ʼ������ֹ�ϸ��û������ݱ��õ�����û�����
		for (i = L->data.sport.head; i < L->data.sport.rear - 1; (L->data.sport.head + 1) % 8)//�����û������˶����ݴ�ͷ����β
		{
			sport[j] = L->data.sport.base[i];
			j++;
		}
		for (j = 0; j < 7; j++)//���⵽87��ͳ�������˶�����������˵0,1,0,4,7,8,0����ôday�����оͻ�洢1��3
		{
			if (sport[j] == 0)
				continue;
			else
			{
				if (sport[j + 1] == 0)
				{
					count++;//��������������
					day[daycount] = count;//�����������洢��������¼������
					daycount++;//������¼����ָ�����
					count = 0;//������������
				}
				else
					count++;
			}
		}
		if (j == 7 && count != 0)
		{
			day[daycount] = count;
			daycount++;//������¼����ָ�����
			count = 0;//������������
		}
		for (i = 0; i < 7; i++)//ð�������day����������򣬽����ķŵ���ͷ
		{
			for (j = 0; j < 7 - 1 - i; j++)
			if (day[j] < day[j + 1])
			{
				lin = day[j];
				day[j] = day[j + 1];
				day[j + 1] = lin;
			}
		}
		id[k] = p->data.id;
		sersport[k] = day[0];
		k++;
	}
	for (i = 0; i < 1000 - 1; i++)//�������˶��������ð�����򣬶������˶����������λ��ʱ˳�㽫id��˳��ı�
	{
		for (j = 0; j < 1000 - 1 - i; j++)
		{
			if (sersport[j] > sersport[j + 1])
			{
				lin = sersport[j + 1];
				toid = id[j + 1];
				sersport[j + 1] = sersport[j];
				id[j + 1] = id[j];
				sersport[j] = lin;
				id[j] = toid;
			}
		}
	}
	cout << "�����˶����а�\n";
	cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << std::left << setw(16) << "�����˶�����" "\n";
	for (i = 0; i < 1000; i++)
	{
		p = L->next;//ÿ��forѭ����ʼָ��ȥ
		while (p && p->data.id != id[i])//�ҵ�id����ʾ��Ϣ
			p = p->next;
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << std::left << setw(16) << sersport[i] << endl;
	}
	return 0;
}

Status weeklist(LinkList L)//һ�����а�ͨ��ѡ���Ա�չʾ
{
	string id[1000], toid;
	int weeksport[1000], i = 0, j=0, lin,allweek=0;
	LinkList p = L->next;
	cout << "1.���� 2.Ů��";
	cout << "��ѡ��鿴�������а��Ů�����а�";
	cin >> lin;
	switch (lin)
	{
		case 1:
		{
			while (p)
			{
				if (p->data.sex == 'm')
				{
					id[i] = p->data.id;//id¼������
					for (j = 0; j < 8; j++)//ͳ�Ƶ����û�һ���ܲ���
					{
						allweek = allweek + p->data.sport.base[j];
					}
					weeksport[i] = allweek / 7;//������û���ƽ������
					i++;
				}
			}
			break;
		}
		case 2:
		{
			while (p)
			{
				if (p->data.sex == 'f')
				{
					id[i] = p->data.id;//id¼������
					for (j = 0; j < 8; j++)//ͳ�Ƶ����û�һ���ܲ���
					{
						allweek = allweek + p->data.sport.base[j];
					}
					weeksport[i] = allweek / 7;//������û���ƽ������
					i++;
				}
			}
			break;
		}
	}
	for (i = 0; i < 1000 - 1; i++)//���˶��������ð�����򣬶����˶����������λ��ʱ˳�㽫id��˳��ı�
	{
		for (j = 0; j < 1000 - 1 - i; j++)
		{
			if (weeksport[j] > weeksport[j + 1])
			{
				lin = weeksport[j + 1];
				toid = id[j + 1];
				weeksport[j + 1] = weeksport[j];
				id[j + 1] = id[j];
				weeksport[j] = lin;
				id[j] = toid;
			}
		}
	}
	cout << "�����˶����а�\n";
	cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << std::left << setw(16) << "�����˶�����\n";
	for (i = 0; i < 1000; i++)
	{
		p = L->next;//ÿ��forѭ����ʼָ��ȥ
		while (p && p->data.id != id[i])//�ҵ�id����ʾ��Ϣ
			p = p->next;
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << std::left << setw(16) << weeksport[i] << endl;
	}
	return 0;
}