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
	//Q.base = { 0 };
	cout << "��ʼ���ɹ���" << endl;
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
	//if(Q.rear==0)
		//cout << "��������" << endl;
	//cout << e;
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


Status IsValidQueue(SqQueue Q)
{
	if (Q.head == Q.rear)
		return ERROR;//�ж�Ϊ��
	else
	{
		return OK;//�ж���Ϊ��
	}
}