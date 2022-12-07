#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include"LinkList.h"
using namespace std;

Status todaylist(LinkList L)//当天运动排行榜
{
	string id[1000],toid;
	int todaysport[1000],i=0,j,lin;
	LinkList p=L->next;
	while (p)
	{
		id[i] = p->data.id;
		if (0 < p->data.sport.rear <= 7)
			todaysport[i] = p->data.sport.base[p->data.sport.rear - 1];
		else
		{
			todaysport[i] = p->data.sport.base[7];
		}
		i++;
	}
	for (i = 0; i < 1000 - 1; i++)
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
	cout << "今日运动排行榜\n";
	cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << std::left << setw(16) << "今日运动步数" "\n";
	for (i = 0; i < 1000; i++)
	{
		while (p && p->data.id != id[i])
			p = p->next;
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << std::left << setw(16) << todaysport[i]<<endl;
	}
	return 0;
}
Status serlist(LinkList L)//连续运动排行榜
{
	int sersport[1000], i = 0, j, k=0;
	string id[1000], toid;
	LinkList p = L->next;
	while (p)
	{
		id[i] = p->data.id;
		for (j = 0; j < 7; j++)
		{
			if (p->data.sport.base[j] == 0)
				continue;
			else
			{
				if (p->data.sport.base[j + 1] == 0)
				{
					if (k <= 1)
						k = 0;
					else if (k > 1 && p->data.sport.base[j + 1] == 0)
						sersport[i] = k;
					else
						sersport[i] = k++;
				}
			}
		}
		i++;
	}
	return 0;
}
Status weeklist(LinkList L)//一周排行榜(指定用户，暂时不写)
{
	string id[1000], toid;
	int weeksport[1000], i = 0, j, lin,allweek=0;
	LinkList p = L->next;
	while (p)
	{
		for (j = 0; j < 7; j++)
		{
			allweek = allweek + p->data.sport.base[j];
		}
		i++;
	}
	return 0;
}