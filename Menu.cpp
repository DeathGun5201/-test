#include"Menu.h"
#include<stdlib.h>

void Menu(LinkList& L)
{
	while (1)
	{
		int n;
		cout << "�û���Ϣ����ϵͳ" << endl;
		cout << "1.����û�  2.ɾ���û�  3.��ѯ�û�  4.�޸��û�  5.��ʾ�û�  0.�˳�" << endl;
		cout << "���������ѡ��" << endl;
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