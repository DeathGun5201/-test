#pragma once
#include<iostream>
using namespace std;//c++头文件声明，因为C语言没有字符串变量，但是这个头文件包含字符串变量的定义

struct User
{
	string id;//定义用户名（手机号）
	string name;//定义昵称
	char sex;//定义性别
	int age;//定义年龄
	SqQueue sport;
};