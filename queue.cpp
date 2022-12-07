//����йض��еĺ���
#include<stdlib.h>
#include"LinkList.h"

Status CreatQ(SqQueue& Q)
{
	Q.base = new int[8] ;//��һ���ռ䷽���ж��Ƿ�������
	if (!Q.base)
	{
		cout << "�����ʼ�����󼴽��˳�";
		system("pause");
		exit(OVERFLOW);
	}
	Q.head = Q.rear = 0;
	return OK;
}

Status QueueLength(SqQueue Q)//������г���
{
	return (Q.rear - Q.head + 8) % 8;
}

Status EnQueue(SqQueue& Q, int e)//���β������Ԫ��
{
	if ((Q.rear + 1) % 8 == Q.head)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % 8;
	return OK;
}

Status DeQueue(SqQueue& Q)//ɾ����ͷԪ��
{
	if (Q.head == Q.rear)
		return ERROR;
	Q.head = (Q.head + 1) % 8;
	return OK;
}