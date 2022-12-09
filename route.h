
#pragma once
#include"LinkList.h"
#define V 20
typedef struct
{
	string location[20];
	double distance[20][20];
	int locationnum, arcnum;
}Graph;
Status drawroute(Graph &G);//绘制运动路线             //补充：这里需要&,因为在读取文件的时候G里面的数据都变了
Status chooseroute(Graph &G);//选择运动路线

void Dijkstra_minTree(Graph G, int v0, int p[V], double D[V]);

