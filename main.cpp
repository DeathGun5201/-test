#include<iostream>
using namespace std;
#include "Menu.h"//ʹ����������ͻ����˸�UserMng�����������ֻ��Ҫ��Menu.hͷ�ļ�����ʹ��UserMng������
#include"LinkList.h"
int main()
{
	LinkList L;
	InitList( L);//��ʼ�����������ж��Ƿ��ʼ���ɹ�
	Menu(L);
	return 0;
}