#pragma once
#include"LinkList.h"
Status addsport(LinkList L);//添加运动信息
Status ReviseSport(LinkList L);//修改运动信息
Status ReviseSport2(SqQueue& Q,int n);
Status ShowSport(LinkList L);//显示用户的运动信息
Status ShowQueue(SqQueue& Q);//遍历队列，显示运动数据
Status IsValidQueue(SqQueue Q);//判断队列是否为空
