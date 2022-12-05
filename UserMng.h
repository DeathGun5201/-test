#pragma once
//这是用户信息管理的头文件


#include"LinkList.h"

void AddUser(LinkList& L);//添加用户
int IsValid_UserId(string Id);//判断用户号（手机号）是否合法
