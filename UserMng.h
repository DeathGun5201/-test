#pragma once//�����Ƿ�ֹͷ�ļ��ظ�����
//�����û���Ϣ�����ͷ�ļ�


#include"LinkList.h"

void AddUser(LinkList& L);//����û�
bool IsValid_UserId(string Id,int n,LinkList &L);//�ж��û��ţ��ֻ��ţ��Ƿ�Ϸ�
void DeleteUser(LinkList& L);//ɾ���û�
void SearchUser(LinkList& L);//�����û�
void ReviseUser(LinkList& L);//�޸��û�
void ShowUser(LinkList& L);//��ʾ�û���Ϣ

