#pragma once
#include"LinkList.h"
typedef struct
{
	string location[20];
	double distance[20][20];
	int locationnum, arcnum;
}Graph;
Status drawroute(Graph G);//绘制运动路线
Status chooseroute(Graph G);//选择运动路线