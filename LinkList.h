#pragma once

#include"User.h"//�������ͷ�ļ�����������typedef User ElemType;�õ�����������
#include<iostream>
using namespace std;//c++ͷ�ļ�������ʹ���ܹ�ʹ��string�������ַ��������Ķ���
#include<string>//���ﲻ��.h��д��.hҲû��
#include<stdio.h>
typedef User ElemType;
typedef int Status;
typedef struct LNode
{
	ElemType data;//����һ��ElemType���͵ı�������ΪUser���͵ı���
	struct LNode* next;//��һ��Ԫ�صĵ�ַ
}LNode,*LinkList;

typedef struct//���ж���
{
	int* base;
	int head;
	int rear;
}SqQueue;


Status InitList(LinkList& L);//��ʼ�����������ж��Ƿ��ʼ���ɹ�

#define OVERFLOW -2
#define OK 1
#define ERROR -1