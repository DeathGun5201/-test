//存放有关队列的函数
#include<stdlib.h>
#include"LinkList.h"

Status CreatQ(SqQueue& Q)
{
	Q.base = new int[8];//留一个空间方便判断是否是满的
	if (!Q.base)
	{
		cout << "程序初始化错误即将退出";
		system("pause");
		exit(OVERFLOW);
	}
	Q.head = Q.rear = 0;
	return OK;
}

Status EnQueue(SqQueue& Q)
{

}

Status ReviseQueue(SqQueue& Q)//修改当天的运动数据
{
	cout << "你确定要修改今天的运动数据吗？" << endl;
	
}