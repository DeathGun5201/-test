#include"Menu.h"
#include<stdlib.h>

void Menu(LinkList& L)
{
	while (1)
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
			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			case 0:
				break;

			default:
				break;
			}
			break;
		}
		system("pause");
		system("cls");
	}
	
}