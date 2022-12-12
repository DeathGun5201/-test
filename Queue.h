#pragma once
#include"LinkList.h"
//存放有关队列的函数头声明
Status CreatQ(SqQueue& Q);//构造空队列
Status QueueLength(SqQueue Q);//计算队列长度
Status EnQueue(SqQueue& Q, int e);//向队尾插入新元素
Status DeQueue(SqQueue& Q);//删除队头元素
Status ShowQueue(SqQueue Q);//遍历队列，显示运动数据
Status ChangeQueueRear(SqQueue& Q, int steps);//改动队尾元素
Status AverageQueue(SqQueue Q);//求运动步数的平均数