#pragma once//作用是防止头文件重复编译
//这是用户信息管理的头文件
#include"LinkList.h"

void AddUser(LinkList &L);//添加用户
bool IsValid_UserId(string Id,int n,LinkList &L);//判断用户号（手机号）是否合法
int DeleteUser(LinkList &L);//删除用户
int SearchUser(LinkList L);//查找用户
int ReviseUser(LinkList L);//修改用户
void ShowUser(LinkList L);//显示用户信息
int LengthUser(LinkList& L);//求链表的长度