#pragma once
#include<iostream>
using namespace std;//c++ͷ�ļ���������ΪC����û���ַ����������������ͷ�ļ������ַ��������Ķ���

typedef struct//���ж���
{
	int* base;
	int head;
	int rear;
}SqQueue;


struct User
{
	string id;//�����û������ֻ��ţ�
	string name;//�����ǳ�
	char sex;//�����Ա�
	int age;//��������
	SqQueue sport;//����һ������sport�Ķ���
};