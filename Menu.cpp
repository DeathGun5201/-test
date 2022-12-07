#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include"Menu.h"
#include"SportsMng.h"
using namespace std;
#include"SportsMng.h"
#include"DataLoad.h"

int MainMenu(LinkList& L)
{
	int lin;
	while (1)
	{
		cout << "运动信息管理系统\n";
		cout << "1.用户信息管理 2.运动信息管理 3.运动排行榜 4.定制运动路线 5.数据文件操作 6.退出\n";
		cout << "请选择功能：";
		cin >> lin;
		switch (lin)
		{
			case 1:
				UserMeun(L);
				break;
			case 2:
				SportMeun(L);
				break;
			case 3:
				SportlistMeun(L);
				break;
			case 4:
				RouteMeun(L);
				break;
			case 5:
				DataMeun(L);
				break;
			case 6:
				return 0;
			default:
				cout << "输入字符有误请重新输入或选择退出\n";
				system("pause");
				break;
		}
		system("cls");
	}
}

int UserMeun(LinkList& L)//有关用户操作的菜单
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "用户信息管理\n";
		cout << "1.添加用户  2.删除用户  3.查询用户  4.修改用户  5.显示用户  6.退出\n";
		cout << "请选择功能：";
		cin >> lin;
		switch (lin)
		{
			case 1:
				AddUser(L);
				break;
			case 2:
				DeleteUser(L);
				break;
			case 3:
				SearchUser(L);
				break;
			case 4:
				ReviseUser(L);
				break;
			case 5:
				ShowUser(L);
				break;
			case 6:
				return 0;
			default:
				cout << "输入字符有误请重新输入或选择退出\n";
				system("pause");
				break;
		}
		system("cls");
	}
	return 0;
}


int SportMeun(LinkList& L)//有关运动信息操作的菜单
{
	int lin;//关于运动信息管理的这个模块，在我看来操作目前只能是主菜单的1.的操作之后，即初始化用户信息以及队列的操作后，目前还有局限性
	while (1)
	{
		system("cls");
		cout << "运动信息管理\n";
		cout << "1.添加运动信息 2.修改运动信息 3.显示所有用户运动信息 4.退出\n";
		cout << "请选择功能：";
		cin >> lin;
		switch (lin)
		{
		case 1:
			addsport(L);
				break;
		case 2:
			ReviseSport(L);
				break;
		case 3:
			ShowSport(L);
			break;
		case 4:
			return 0;
		default:
			cout << "输入字符有误请重新输入或选择退出\n";
			system("pause");
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}


int SportlistMeun(LinkList& L)//有关运动排行操作的菜单
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "运动排行榜\n";
		cout << "1.当天排行榜 2.连续运动排行榜 3.一周排行榜 4.退出\n";
		cout << "请选择功能：";
		cin >> lin;
		switch (lin)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				return 0;
			default:
				cout << "输入字符有误请重新输入或选择退出\n";
				system("pause");
				break;
		}
		system("cls");
	}
	return 0;
}


int RouteMeun(LinkList& L)//路线定制菜单
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "定制运动路线\n";
		cout << "1.绘制运动路线 2.选择运动路线 3.退出\n";
		cout << "请选择功能：";
		cin >> lin;
		switch (lin)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				return 0;
			default:
				cout << "输入字符有误请重新输入或选择退出\n";
				system("pause");
				break;
		}
		system("cls");
	}
	return 0;
}


int DataMeun(LinkList& L)//数据操作菜单
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "数据文件操作\n";
		cout << "1.数据加载 2.数据保存 3.退出\n";
		cout << "请选择功能：";
		cin >> lin;
		switch (lin)
		{
		case 1:ReadFile(L);
				break;
		case 2:WriteFile(L);
				break;
			case 3:
				return 0;
			default:
				cout << "输入字符有误请重新输入或选择退出\n";
				system("pause");
				break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}









/*while (1)
	{
		int n;
		cout << "用户信息管理系统" << endl;
		cout << "1.添加用户  2.删除用户  3.查询用户  4.修改用户  5.显示用户  0.退出" << endl;
		cout << "请输入你的选项" << endl;
		cin >> n;
		while (1)
		{
			switch (n)
			{
			case 1:
				AddUser(L);
				break;
			case 2:
				DeleteUser(L);
				break;
			case 3:SearchUser(L);
				break;

			case 4:ReviseUser(L);
				break;

			case 5:ShowUser(L);
				break;

			case 0:
				cout << "感谢使用本程序！" << endl;
				break;

			default:
				break;
			}
			break;
		}
		system("pause");
		system("cls");
		break;
	}
	
}
	}*/