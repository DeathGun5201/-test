#pragma once

#include"User.h"//包含这个头文件可以在下面typedef User ElemType;用到，算是声明
#include<iostream>
using namespace std;//c++头文件声明，使得能够使用string来进行字符串变量的定义
#include<string>//这里不用.h，写上.h也没事
#include<stdio.h>
typedef User ElemType;
typedef int Status;
typedef struct LNode
{
	ElemType data;//这是一个ElemType类型的变量，即为User类型的变量
	struct LNode* next;//下一个元素的地址
}LNode,*LinkList;

typedef struct//队列定义
{
	int* base;
	int head;
	int rear;
}SqQueue;


Status InitList(LinkList& L);//初始化链表，并且判断是否初始化成功

#define OVERFLOW -2
#define OK 1
#define ERROR -1