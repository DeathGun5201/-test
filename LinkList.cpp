/*文件名：LinkList.cpp
功能：链表的基本操作  
*/

//可以把对python类的理解带入到结构体之中

#include"LinkList.h"//包含这个头文件才能实现对应的操作

Status InitList(LinkList& L)//初始化链表，并且判断是否初始化成功
{
	L = new LNode;
	if (!L)
		exit(OVERFLOW);
	L->next = NULL;
	return OK;//L指向了头结点
}