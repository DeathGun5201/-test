/*�ļ�����LinkList.cpp
���ܣ�����Ļ�������  
*/

//���԰Ѷ�python��������뵽�ṹ��֮��

#include"LinkList.h"//�������ͷ�ļ�����ʵ�ֶ�Ӧ�Ĳ���
#define OVERFLOW -2
#define OK 1
#define ERROR -1


Status InitList(LinkList& L)//��ʼ�����������ж��Ƿ��ʼ���ɹ�
{
	L = new LNode;
	if (!L)
		exit(OVERFLOW);
	L->next = NULL;
	return OK;//Lָ����ͷ���
}