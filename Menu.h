#pragma once
//���ڽ��к���ԭ������
/*
�ļ�����Menu.h
���ܣ��˵�����
*/


#include"LinkList.h"//���ﲻҪ�ˣ���Ϊ����ģ����Ƿ���Ҳû��
#include"UserMng.h"//���ҿ��������Ƕ������
int MainMenu(LinkList& L);//���˵�
int UserMeun(LinkList& L);//�й��û������Ĳ˵�
int SportMeun(LinkList& L);//�й��˶���Ϣ�����Ĳ˵�
int SportlistMeun(LinkList& L);//�й��˶����в����Ĳ˵�
int RouteMeun(LinkList& L);//·�߶��Ʋ˵�
int DataMeun(LinkList& L);//���ݲ����˵�