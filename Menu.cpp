#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include"Menu.h"
#include"SportsMng.h"
#include"DataLoad.h"
#include"route.h"
#include"RankingList.h"
using namespace std;

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
				/*
			case 0:
				cout << "�������Ϊ�ַ��������ݳ�����int�����ݵķ�Χ��������ԭ����������������˳�" << endl;
				break;*/
			default:
				cout << "�����������������������ѡ���˳�\n";
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
				if (L->next == NULL)
				{
					cout << "����������û�����ļ�����" << endl;
					system("pause");
				}
				else
				{
					DeleteUser(L);
				}
				break;
			case 3:
				if (L->next == NULL)
				{
					cout << "����������û�����ļ�����" << endl;
					system("pause");
				}
				else
				{
					SearchUser(L);
				}
				break;
			case 4:
				if (L->next == NULL)
				{
					cout << "����������û�����ļ�����" << endl;
					system("pause");
				}
				else
				{
					ReviseUser(L);
				}
				break;
			case 5:
				ShowUser(L);
				break;
			case 6:
				return 0;
			default:
				cout << "�����������������������ѡ���˳�\n";
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
			if (L->next == NULL)
			{
				cout << "����������û�����ļ�����" << endl;
			}
			else
			{
				ReviseSport(L);
			}
			break;
		case 3:
			if (L->next == NULL)
			{
				cout << "����������û�����ļ�����" << endl;
			}
			else
			{
				ShowSport(L);
			}
			break;
		case 4:
			return 0;
		default:
			cout << "�����������������������ѡ���˳�\n";
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
				if (L->next == NULL)
				{
					cout << "����������û�����ļ�����" << endl;
					system("pause");
				}
				else
				{
					todaylist(L);
				}
				break;
			case 2:
				if (L->next == NULL)
				{
					cout << "����������û�����ļ�����" << endl;
					system("pause");
				}
				else
				{
					serlist(L);
				}
				break;
			case 3:
				if (L->next == NULL)
				{
					cout << "����������û�����ļ�����" << endl;
					system("pause");
				}
				else
				{
					weeklist(L);
				}
				break;
			case 4:
				return 0;
			default:
				cout << "�����������������������ѡ���˳�\n";
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
	Graph G;
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
				drawroute(G);
				break;
			case 2:
				chooseroute(G);
				break;
			case 3:
				return 0;
			default:
				cout << "�����������������������ѡ���˳�\n";
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
		cout << "1.���ݼ��� 2.���ݱ��� 3.�˳�\n";//����Ŀǰ��ֻ�ܶ�User.txt���б���Ͷ�ȡ����û��д�����������ı��Ķ�ȡ�ͱ���
		cout << "��ѡ���ܣ�";
		cin >> lin;
		switch (lin)
		{
		case 1:
			ReadFile(L);
			break;
		case 2:
			WriteFile(L);
			break;
		case 3:
			return 0;
		default:
			cout << "�����������������������ѡ���˳�\n";
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}