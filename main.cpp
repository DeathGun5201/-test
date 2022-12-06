#include<iostream>
using namespace std;
#include "Menu.h"//使用这个声明就会少了个UserMng的声明，因此只需要在Menu.h头文件里面使用UserMng的声明
#include"LinkList.h"
int main()
{
	LinkList L;
	InitList( L);//初始化链表，并且判断是否初始化成功
	Menu(L);
	return 0;
}