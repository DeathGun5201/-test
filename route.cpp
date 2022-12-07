#include<fstream>
#include<iostream>
#include"route.h"
using namespace std;
Status drawroute(Graph G)//location顶点表，distance邻接矩阵，所有距离最大是5.2
{
    int i;
    G.arcnum = G.locationnum = 0;//初始化，用于计数同时保存结果
    string loca1, loca2;//暂存两个顶点
    double dis;//暂存距离
    int lloca1, lloca2;//记录loca1和loca2在定点表中的位置，然后将距离存入邻接矩阵
    ifstream infile("LocatInfo.txt", ios::in); 	//以读的方式打开文件，如果文件不存在就打不开
    if (!infile)   				//测试是否成功打开
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile >> G.location[G.locationnum];
        G.locationnum++;//循环计数，顺便统计节点数
    }
    infile.close();

    ifstream infile1("RouteInfo.txt", ios::in); 	//以读的方式打开文件，如果文件不存在就打不开
    if (!infile1)   				//测试是否成功打开
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile1.eof())
    {
        infile1 >> loca1 >> loca2 >> dis;//不能读取距离
        for (i = 0; i < 20; i++)//寻找loca1在顶点表中的位置
        {
            if (loca1 == G.location[i])
            {
                lloca1 = i;
                break;
            }
        }
        for (i = 0; i < 20; i++)//寻找loca2在顶点表中的位置
        {
            if (loca2 == G.location[i])
            {
                lloca2 = i;
                break;
            }
        }
        G.distance[lloca1][lloca2] = G.distance[lloca2][lloca1] = dis;//存入距离
        G.arcnum++;
    }
    infile.close();
    cout << "共有" << G.locationnum << "个顶点"<<endl;
    cout << "共有" << G.arcnum << "条边" << endl;
    system("pause");
	return 0;
}
Status chooseroute(Graph G)
{
    
    return 0;
}