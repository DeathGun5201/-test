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
		id[i] = p->data.id;//将链表中现有id录入到字符串数组中
		if (0 < p->data.sport.rear <= 7)//if,else录入当日运动数据
			todaysport[i] = p->data.sport.base[p->data.sport.rear - 1];
		else
		{
			todaysport[i] = p->data.sport.base[7];
		}
		i++;
	}
	for (i = 0; i < 1000 - 1; i++)//当日运动情况排序，冒泡排序，对今日运动排序排序调位置时顺便将id的顺序改变
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
		p = L->next;//每次for循环开始指回去
		while (p && p->data.id != id[i])//找到id后显示信息
			p = p->next;
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << std::left << setw(16) << todaysport[i]<<endl;
	}
	return 0;
}

Status serlist(LinkList L)//连续运动排行榜
{
	int sersport[1000], i = 0, j=0, k=0;//sersport存储每个用户最大连续运动天数
	int sport[7],day[7],count=0,daycount=0,lin;//sport用来存储该用户运动数据，day用来存储连续运动天数
	string id[1000], toid;//id数组存储用户id
	LinkList p = L->next;
	while (p)
	{
		j = 0;//开头初始化，便于存储用户运动数据
		day[7] = { 0 };//开头初始化，防止上个用户的数据被用到这个用户身上
		for (i = L->data.sport.head; i < L->data.sport.rear - 1; (L->data.sport.head + 1) % 8)//将该用户所有运动数据从头读到尾
		{
			sport[j] = L->data.sport.base[i];
			j++;
		}
		for (j = 0; j < 7; j++)//从这到87行统计连续运动天数，比如说0,1,0,4,7,8,0，那么day数组中就会存储1和3
		{
			if (sport[j] == 0)
				continue;
			else
			{
				if (sport[j + 1] == 0)
				{
					count++;//计算连续的天数
					day[daycount] = count;//将连续天数存储到天数记录数组中
					daycount++;//天数记录数组指针后移
					count = 0;//连续天数清零
				}
				else
					count++;
			}
		}
		if (j == 7 && count != 0)
		{
			day[daycount] = count;
			daycount++;//天数记录数组指针后移
			count = 0;//连续天数清零
		}
		for (i = 0; i < 7; i++)//冒泡排序对day数组进行排序，将最大的放到开头
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
	for (i = 0; i < 1000 - 1; i++)//对连续运动情况排序，冒泡排序，对连续运动排序排序调位置时顺便将id的顺序改变
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
	cout << "连续运动排行榜\n";
	cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << std::left << setw(16) << "连续运动天数" "\n";
	for (i = 0; i < 1000; i++)
	{
		p = L->next;//每次for循环开始指回去
		while (p && p->data.id != id[i])//找到id后显示信息
			p = p->next;
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << std::left << setw(16) << sersport[i] << endl;
	}
	return 0;
}

Status weeklist(LinkList L)//一周排行榜，通过选择性别展示
{
	string id[1000], toid;
	int weeksport[1000], i = 0, j=0, lin,allweek=0;
	LinkList p = L->next;
	cout << "1.男生 2.女生";
	cout << "请选择查看男生排行榜或女生排行榜：";
	cin >> lin;
	switch (lin)
	{
		case 1:
		{
			while (p)
			{
				if (p->data.sex == 'm')
				{
					id[i] = p->data.id;//id录入数组
					for (j = 0; j < 8; j++)//统计单个用户一周总步数
					{
						allweek = allweek + p->data.sport.base[j];
					}
					weeksport[i] = allweek / 7;//计算该用户周平均步数
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
					id[i] = p->data.id;//id录入数组
					for (j = 0; j < 8; j++)//统计单个用户一周总步数
					{
						allweek = allweek + p->data.sport.base[j];
					}
					weeksport[i] = allweek / 7;//计算该用户周平均步数
					i++;
				}
			}
			break;
		}
	}
	for (i = 0; i < 1000 - 1; i++)//周运动情况排序，冒泡排序，对周运动排序排序调位置时顺便将id的顺序改变
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
	cout << "本周运动排行榜\n";
	cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << std::left << setw(16) << "本周运动步数\n";
	for (i = 0; i < 1000; i++)
	{
		p = L->next;//每次for循环开始指回去
		while (p && p->data.id != id[i])//找到id后显示信息
			p = p->next;
		cout << std::left << setw(16) << p->data.id << std::left << setw(16) << p->data.name << std::left << setw(16) << p->data.sex << std::left << setw(16) << p->data.age << std::left << setw(16) << weeksport[i] << endl;
	}
	return 0;
}