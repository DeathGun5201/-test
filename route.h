#pragma once
#include"LinkList.h"
typedef struct
{
	string location[20];
	double distance[20][20];
	int locationnum, arcnum;
}Graph;
Status drawroute(Graph G);//�����˶�·��
Status chooseroute(Graph G);//ѡ���˶�·��