//存放有关队列的函数
#include<stdlib.h>
#include"LinkList.h"
#include "Queue.h"

Status CreatQ(SqQueue& Q)
{
	int i;
	Q.base = new int[8];//留一个空间方便判断是否是满的
	if (!Q.base)
	{
		cout << "程序初始化错误即将退出";
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

Status QueueLength(SqQueue Q)//计算队列长度
{
	return (Q.rear - Q.head + 8) % 8;
}

Status EnQueue(SqQueue &Q, int e)//向队尾插入新元素
{
	if ((Q.rear + 1) % 8 == Q.head)
		return ERROR;
	Q.base[Q.rear] = e;//经过验证，中断出现在这里,如果冲突，那么只能是Q.base[Q.rear]被占用？？
	Q.rear = (Q.rear + 1) % 8;
	return OK;
}

Status DeQueue(SqQueue& Q)//删除队头元素
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
		cout << "该用户运动数据尚未录入" << endl;
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

Status ChangeQueueRear(SqQueue& Q, int steps)//改动队尾元素
{
	if (0 < Q.rear <= 7)//if,else录入当日运动数据
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