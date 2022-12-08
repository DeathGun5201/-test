//存放有关队列的函数
#include<stdlib.h>
#include"LinkList.h"

Status CreatQ(SqQueue& Q)
{
	Q.base = new int[8] ;//留一个空间方便判断是否是满的
	if (!Q.base)
	{
		cout << "程序初始化错误即将退出";
		system("pause");
		exit(OVERFLOW);
	}
	Q.head = Q.rear = 0;
	//Q.base = { 0 };
	cout << "初始化成功！" << endl;
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
	//if(Q.rear==0)
		//cout << "到了这里" << endl;
	//cout << e;
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


Status IsValidQueue(SqQueue Q)
{
	if (Q.head == Q.rear)
		return ERROR;//判定为空
	else
	{
		return OK;//判定不为空
	}
}