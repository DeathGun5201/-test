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
		cout << "�˶���Ϣ����ϵͳ\n";
		cout << "1.�û���Ϣ���� 2.�˶���Ϣ���� 3.�˶����а� 4.�����˶�·�� 5.�����ļ����� 6.�˳�\n";
		cout << "��ѡ���ܣ�";
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
				cout << "�����ַ����������������ѡ���˳�\n";
				system("pause");
				break;
		}
		system("cls");
	}
}

int UserMeun(LinkList& L)//�й��û������Ĳ˵�
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "�û���Ϣ����\n";
		cout << "1.����û�  2.ɾ���û�  3.��ѯ�û�  4.�޸��û�  5.��ʾ�û�  6.�˳�\n";
		cout << "��ѡ���ܣ�";
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
				cout << "�����ַ����������������ѡ���˳�\n";
				system("pause");
				break;
		}
		system("cls");
	}
	return 0;
}


int SportMeun(LinkList& L)//�й��˶���Ϣ�����Ĳ˵�
{
	int lin;//�����˶���Ϣ��������ģ�飬���ҿ�������Ŀǰֻ�������˵���1.�Ĳ���֮�󣬼���ʼ���û���Ϣ�Լ����еĲ�����Ŀǰ���о�����
	while (1)
	{
		system("cls");
		cout << "�˶���Ϣ����\n";
		cout << "1.����˶���Ϣ 2.�޸��˶���Ϣ 3.��ʾ�����û��˶���Ϣ 4.�˳�\n";
		cout << "��ѡ���ܣ�";
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
			cout << "�����ַ����������������ѡ���˳�\n";
			system("pause");
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}


int SportlistMeun(LinkList& L)//�й��˶����в����Ĳ˵�
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "�˶����а�\n";
		cout << "1.�������а� 2.�����˶����а� 3.һ�����а� 4.�˳�\n";
		cout << "��ѡ���ܣ�";
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
				cout << "�����ַ����������������ѡ���˳�\n";
				system("pause");
				break;
		}
		system("cls");
	}
	return 0;
}


int RouteMeun(LinkList& L)//·�߶��Ʋ˵�
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "�����˶�·��\n";
		cout << "1.�����˶�·�� 2.ѡ���˶�·�� 3.�˳�\n";
		cout << "��ѡ���ܣ�";
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
				cout << "�����ַ����������������ѡ���˳�\n";
				system("pause");
				break;
		}
		system("cls");
	}
	return 0;
}


int DataMeun(LinkList& L)//���ݲ����˵�
{
	int lin;
	while (1)
	{
		system("cls");
		cout << "�����ļ�����\n";
		cout << "1.���ݼ��� 2.���ݱ��� 3.�˳�\n";
		cout << "��ѡ���ܣ�";
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
				cout << "�����ַ����������������ѡ���˳�\n";
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
			case 3:SearchUser(L);
				break;

			case 4:ReviseUser(L);
				break;

			case 5:ShowUser(L);
				break;

			case 0:
				cout << "��лʹ�ñ�����" << endl;
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