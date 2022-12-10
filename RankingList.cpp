#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include"LinkList.h"
using namespace std;

Status todaylist(LinkList L)//�����˶����а�
{
	string id[1000], toid;
	int todaysport[1000] = { 0 }, count = 0, j, lin, k, i;
	LinkList p = L->next;
	while (p)
	{
		id[count] = p->data.id;//������������id¼�뵽�ַ���������
		if (0 < p->data.sport.rear <= 7)//if,else¼�뵱���˶�����
			todaysport[count] = p->data.sport.base[p->data.sport.rear - 1];
		else
		{
			todaysport[count] = p->data.sport.base[7];
		}
		count++;//count-1��¼���ж�����
		p = p->next;
	}
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
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
	cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << setw(16) << "����" << "�����˶�����\n";
	for (i = count - 1; i >= 0; i--)
	{
		p = L->next;//ÿ��forѭ����ʼָ��ȥ
		while (p && p->data.id != id[i])//�ҵ�id����ʾ��Ϣ
			p = p->next;
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age<<todaysport[i]<<endl;
	}
	system("pause");
	return 0;
}

Status serlist(LinkList L)//�����˶����а�
{
	int sersport[1000], i = 0, j = 0, num = 0;//sersport�洢ÿ���û���������˶�����
	int sport[7], day[7], count = 0, daycount = 0, lin;//sport�����洢���û��˶����ݣ�day�����洢�����˶�����
	string id[1000], toid;//id����洢�û�id
	LinkList p = L->next;
	while (p)
	{
		j = 0;//��ͷ��ʼ�������ڴ洢�û��˶�����
		for (i = 0; i < 7; i++)//day�����ʼ��
		{
			day[i] = 0;
		}
		i = p->data.sport.head;
		while (i != p->data.sport.rear)
		{
			sport[j] = p->data.sport.base[i];
			j++;//Ϊsport����洢�ṩ֧��
			i = (i + 1) % 8;
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
		for (i = 0; i < 7 - 1; i++)//ð�������day����������򣬽����ķŵ���ͷ�����������⣬���⿪ʼ��
		{
			for (j = 0; j < 7 - 1 - i; j++)
			{
				if (day[j] > day[j + 1])
				{
					lin = day[j + 1];
					day[j + 1] = day[j];
					day[j] = lin;
				}
			}
		}
		id[num] = p->data.id;
		sersport[num] = day[6];
		num++;
		p = p->next;
	}
	for (i = 0; i < num - 1; i++)//�������˶��������ð�����򣬶������˶����������λ��ʱ˳�㽫id��˳��ı�
	{
		for (j = 0; j < num - 1 - i; j++)
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
	cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << setw(16) << "����" << "�����˶�����\n";
	for (i = num - 1; i >= 0; i--)
	{
		p = L->next;//ÿ��forѭ����ʼָ��ȥ
		while (p && p->data.id != id[i])//�ҵ�id����ʾ��Ϣ
			p = p->next;
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age << sersport[i] << endl;
	}
	system("pause");
	return 0;
}

Status weeklist(LinkList L)//һ�����а�ͨ��ѡ���Ա�չʾ
{
	string id[1000], toid;
	int weeksport[1000], num = 0, j = 0, lin, allweek = 0;//numͳ��������Ů��һ���ж��ٸ�
	int i = 0;
	LinkList p = L->next;
	cout << "1.���� 2.Ů��\n";
	cout << "��ѡ��鿴�������а��Ů�����а�";
	cin >> lin;
	switch (lin)
	{
		case 1:
		{
			num = 0;
			while (p)
			{
				allweek = 0;
				if (p->data.sex == 'm')
				{
					id[num] = p->data.id;//id¼������
					j = p->data.sport.head;
					while (j != p->data.sport.rear)//���˶�����¼��
					{
						allweek = allweek + p->data.sport.base[j];
						j = (j + 1) % 8;
					}
					weeksport[num] = allweek;//���˶�������������
					num++;
				}
				p = p->next;
			}
			break;
		}
		case 2:
		{
			num = 0;
			while (p)
			{
				allweek = 0;
				if (p->data.sex == 'f')
				{
					id[num] = p->data.id;//id¼������
					j = p->data.sport.head;
					while (j != p->data.sport.rear)//���˶�����¼��
					{
						allweek = allweek + p->data.sport.base[j];
						j = (j + 1) % 8;
					}
					weeksport[num] = allweek;//���˶�������������
					num++;
				}
				p = p->next;
			}
			break;
		}
	}
	for (i = 0; i < num - 1; i++)//���˶��������ð�����򣬶����˶����������λ��ʱ˳�㽫id��˳��ı�
	{
		for (j = 0; j < num - i - 1; j++)
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
	cout << std::left << setw(16) << "�û���" << setw(16) << "�ǳ�" << setw(16) << "�Ա�" << setw(16) << "����" << "�����˶�����\n";
	for (i = num - 1; i >= 0; i--)
	{
		p = L->next;//ÿ��forѭ����ʼָ��ȥ
		while (p && p->data.id != id[i])//�ҵ�id����ʾ��Ϣ
			p = p->next;
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age << weeksport[i] << endl;
	}
	system("pause");
	return 0;
}