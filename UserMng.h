#pragma once//�����Ƿ�ֹͷ�ļ��ظ�����
//�����û���Ϣ�����ͷ�ļ�
#include"LinkList.h"

void AddUser(LinkList &L);//����û�
bool IsValid_UserId(string Id,int n,LinkList &L);//�ж��û��ţ��ֻ��ţ��Ƿ�Ϸ�
int DeleteUser(LinkList &L);//ɾ���û�
int SearchUser(LinkList L);//�����û�
int ReviseUser(LinkList L);//�޸��û�
void ShowUser(LinkList L);//��ʾ�û���Ϣ
int LengthUser(LinkList& L);//������ĳ���