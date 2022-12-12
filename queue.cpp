//����йض��еĺ���
#include<stdlib.h>
#include"LinkList.h"
#include "Queue.h"

Status CreatQ(SqQueue& Q)
{
	int i;
	Q.base = new int[8];//��һ���ռ䷽���ж��Ƿ�������
	if (!Q.base)
	{
		cout << "�����ʼ�����󼴽��˳�";
		system("pause");
		exit(OVERFLOW);
	}
	Q.head = Q.rear = 0;
	for (i = 0; i < 8; i++)
	{
		Q.base[i] = 0;
	}
	return OK;
}

Status QueueLength(SqQueue Q)//������г���
{
	return (Q.rear - Q.head + 8) % 8;
}

Status EnQueue(SqQueue &Q, int e)//���β������Ԫ��
{
	if ((Q.rear + 1) % 8 == Q.head)
		return ERROR;
	Q.base[Q.rear] = e;//������֤���жϳ���������,�����ͻ����ôֻ����Q.base[Q.rear]��ռ�ã���
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

Status ShowQueue(SqQueue Q)
{
	int i;
	if (Q.head == Q.rear)
	{
		cout << "���û��˶�������δ¼��" << endl;
	}
	else
	{
		i = Q.head;
		while (i != Q.rear)
		{
			cout << Q.base[i]<<" ";
			i = (i + 1) % 8;
		}
	}
	return OK;
}

Status ChangeQueueRear(SqQueue& Q, int steps)//�Ķ���βԪ��
{
	if (0 < Q.rear <= 7)//if,else¼�뵱���˶�����
		Q.base[Q.rear - 1] = steps;
	else
	{
		Q.base[7] = steps;
	}
	return 0;
}

Status AverageQueue(SqQueue Q)
{
	int n,sum=0;
	n = QueueLength(Q);
	double ave;
	for (int i = 0; i < n; i++)
	{
		sum = sum + Q.base[i];
	}
	cout << "\t" << sum;
	ave = (double)sum / 7;
	cout << "\t\t\t\t"<<ave;
	return 0;
}