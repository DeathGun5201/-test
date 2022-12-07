#pragma once
#include"LinkList.h"
//存放有关队列的函数头声明
Status CreatQ(SqQueue& Q);//构造空队列
Status QueueLength(SqQueue Q);//计算队列长度
Status EnQueue(SqQueue& Q, int e);//向队尾插入新元素
Status DeQueue(SqQueue& Q);//删除队头元素