//����йض��еĺ���
#include<stdlib.h>
#include"LinkList.h"

Status CreatQ(SqQueue& Q)
{
	Q.base = new int[8];//��һ���ռ䷽���ж��Ƿ�������
	if (!Q.base)
	{
		cout << "�����ʼ�����󼴽��˳�";
		system("pause");
		exit(OVERFLOW);
	}
	Q.head = Q.rear = 0;
	return OK;
}