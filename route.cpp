#include<fstream>
#include<iostream>
#include"route.h"
using namespace std;
Status drawroute(Graph G)//location�����distance�ڽӾ������о��������5.2
{
    int i;
    G.arcnum = G.locationnum = 0;//��ʼ�������ڼ���ͬʱ������
    string loca1, loca2;//�ݴ���������
    double dis;//�ݴ����
    int lloca1, lloca2;//��¼loca1��loca2�ڶ�����е�λ�ã�Ȼ�󽫾�������ڽӾ���
    ifstream infile("LocatInfo.txt", ios::in); 	//�Զ��ķ�ʽ���ļ�������ļ������ھʹ򲻿�
    if (!infile)   				//�����Ƿ�ɹ���
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile >> G.location[G.locationnum];
        G.locationnum++;//ѭ��������˳��ͳ�ƽڵ���
    }
    infile.close();

    ifstream infile1("RouteInfo.txt", ios::in); 	//�Զ��ķ�ʽ���ļ�������ļ������ھʹ򲻿�
    if (!infile1)   				//�����Ƿ�ɹ���
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile1.eof())
    {
        infile1 >> loca1 >> loca2 >> dis;//���ܶ�ȡ����
        for (i = 0; i < 20; i++)//Ѱ��loca1�ڶ�����е�λ��
        {
            if (loca1 == G.location[i])
            {
                lloca1 = i;
                break;
            }
        }
        for (i = 0; i < 20; i++)//Ѱ��loca2�ڶ�����е�λ��
        {
            if (loca2 == G.location[i])
            {
                lloca2 = i;
                break;
            }
        }
        G.distance[lloca1][lloca2] = G.distance[lloca2][lloca1] = dis;//�������
        G.arcnum++;
    }
    infile.close();
    cout << "����" << G.locationnum << "������"<<endl;
    cout << "����" << G.arcnum << "����" << endl;
    system("pause");
	return 0;
}
Status chooseroute(Graph G)
{
    
    return 0;
}