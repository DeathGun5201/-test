#pragma once
//用于进行函数原型声明
/*
文件名：Menu.h
功能：菜单管理
*/


#include"LinkList.h"//这里不要了，改为下面的，但是放着也没事
#include"UserMng.h"//在我看来这就是嵌套声明
int MainMenu(LinkList& L);//主菜单
int UserMeun(LinkList& L);//有关用户操作的菜单
int SportMeun(LinkList& L);//有关运动信息操作的菜单
int SportlistMeun(LinkList& L);//有关运动排行操作的菜单
int RouteMeun(LinkList& L);//路线定制菜单
int DataMeun(LinkList& L);//数据操作菜单