#include<iostream>
#include "Menu.h"//ʹ����������ͻ����˸�UserMng�����������ֻ��Ҫ��Menu.hͷ�ļ�����ʹ��UserMng������
#include"LinkList.h"
using namespace std;

int main()
{
	LinkList L;
	InitList(L);//��ʼ�����������ж��Ƿ��ʼ���ɹ�
	MainMenu(L);
	return 0;
}