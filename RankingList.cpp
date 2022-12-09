#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include"LinkList.h"
using namespace std;

Status todaylist(LinkList L)//当天运动排行榜
{
	string id[1000], toid;
	int todaysport[1000] = { 0 }, count = 0, j, lin, k, i;
	LinkList p = L->next;
	while (p)
	{
		id[count] = p->data.id;//将链表中现有id录入到字符串数组中
		if (0 < p->data.sport.rear <= 7)//if,else录入当日运动数据
			todaysport[count] = p->data.sport.base[p->data.sport.rear - 1];
		else
		{
			todaysport[count] = p->data.sport.base[7];
		}
		count++;//count-1记录着有多少人
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
	cout << "今日运动排行榜\n";
	cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << setw(16) << "年龄" << "今日运动步数\n";
	for (i = count - 1; i >= 0; i--)
	{
		p = L->next;//每次for循环开始指回去
		while (p && p->data.id != id[i])//找到id后显示信息
			p = p->next;
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age<<todaysport[i]<<endl;
	}
	system("pause");
	return 0;
}

Status serlist(LinkList L)//连续运动排行榜
{
	int sersport[1000], i = 0, j = 0, num = 0;//sersport存储每个用户最大连续运动天数
	int sport[7], day[7], count = 0, daycount = 0, lin;//sport用来存储该用户运动数据，day用来存储连续运动天数
	string id[1000], toid;//id数组存储用户id
	LinkList p = L->next;
	while (p)
	{
		j = 0;//开头初始化，便于存储用户运动数据
		for (i = 0; i < 7; i++)//day数组初始化
		{
			day[i] = 0;
		}
		i = p->data.sport.head;
		while (i != p->data.sport.rear)
		{
			sport[j] = p->data.sport.base[i];
			j++;//为sport数组存储提供支持
			i = (i + 1) % 8;
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
		for (i = 0; i < 7 - 1; i++)//冒泡排序对day数组进行排序，将最大的放到开头，可能有问题，从这开始改
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
	for (i = 0; i < num - 1; i++)//对连续运动情况排序，冒泡排序，对连续运动排序排序调位置时顺便将id的顺序改变
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
	cout << "连续运动排行榜\n";
	cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << setw(16) << "年龄" << "连续运动天数\n";
	for (i = num - 1; i >= 0; i--)
	{
		p = L->next;//每次for循环开始指回去
		while (p && p->data.id != id[i])//找到id后显示信息
			p = p->next;
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age << sersport[i] << endl;
	}
	system("pause");
	return 0;
}

Status weeklist(LinkList L)//一周排行榜，通过选择性别展示
{
	string id[1000], toid;
	int weeksport[1000], num = 0, j = 0, lin, allweek = 0;//num统计男生或女生一共有多少个
	int i = 0;
	LinkList p = L->next;
	cout << "1.男生 2.女生\n";
	cout << "请选择查看男生排行榜或女生排行榜：";
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
					id[num] = p->data.id;//id录入数组
					j = p->data.sport.head;
					while (j != p->data.sport.rear)//周运动步数录入
					{
						allweek = allweek + p->data.sport.base[j];
						j = (j + 1) % 8;
					}
					weeksport[num] = allweek;//周运动步数进入数组
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
					id[num] = p->data.id;//id录入数组
					j = p->data.sport.head;
					while (j != p->data.sport.rear)//周运动步数录入
					{
						allweek = allweek + p->data.sport.base[j];
						j = (j + 1) % 8;
					}
					weeksport[num] = allweek;//周运动步数进入数组
					num++;
				}
				p = p->next;
			}
			break;
		}
	}
	for (i = 0; i < num - 1; i++)//周运动情况排序，冒泡排序，对周运动排序排序调位置时顺便将id的顺序改变
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
	cout << "本周运动排行榜\n";
	cout << std::left << setw(16) << "用户号" << setw(16) << "昵称" << setw(16) << "性别" << setw(16) << "年龄" << "本周运动步数\n";
	for (i = num - 1; i >= 0; i--)
	{
		p = L->next;//每次for循环开始指回去
		while (p && p->data.id != id[i])//找到id后显示信息
			p = p->next;
		cout << std::left << setw(16) << p->data.id << setw(16) << p->data.name << setw(16) << p->data.sex << setw(16) << p->data.age << weeksport[i] << endl;
	}
	system("pause");
	return 0;
}