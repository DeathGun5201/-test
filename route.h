
#pragma once
#include"LinkList.h"
#define V 20
typedef struct
{
	string location[20];
	double distance[20][20];
	int locationnum, arcnum;
}Graph;
Status drawroute(Graph &G);//�����˶�·��             //���䣺������Ҫ&,��Ϊ�ڶ�ȡ�ļ���ʱ��G��������ݶ�����
Status chooseroute(Graph &G);//ѡ���˶�·��

void Dijkstra_minTree(Graph G, int v0, int p[V], double D[V]);

