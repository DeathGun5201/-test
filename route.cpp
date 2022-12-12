#include<fstream>
#include<iostream>
#include"route.h"
#include<iomanip>
#define INFINITY 65535
#define V 20

//�ⲽ����ֻ�Ƕ�ȡ�����ı��ļ�֮�е���Ϣ��û�����
Status drawroute(Graph &G)//location�����distance�ڽӾ������о��������5.2
{
    int i;
    G.arcnum = G.locationnum = 0;//��ʼ�������ڼ���ͬʱ������ ������Ƕ���������ͱߵ�����
    string loca1, loca2;//�ݴ���������
    double dis;//�ݴ����
    int lloca1, lloca2;//��¼loca1��loca2�ڶ�����е�λ�ã�Ȼ�󽫾�������ڽӾ��󣬼���50��
    ifstream infile("LocatInfo.txt", ios::in); 	//�Զ��ķ�ʽ���ļ�������ļ������ھʹ򲻿�
    if (!infile)   				//�����Ƿ�ɹ���
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile >> G.location[G.locationnum];//���ļ��Ķ������붥���
        G.locationnum++;//ѭ��������˳��ͳ�ƽڵ���
    }
    //��Ȩֵ�ĳ�ʼ��
    for (int i = 0; i < G.locationnum; i++)
    {
        for (int j = 0; j < G.locationnum; j++)
        {
            G.distance[i][j] = INFINITY;
        }
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
        //cout << G.distance[lloca1][lloca2] << endl;
    }
    infile.close();
    cout << "����" << G.locationnum << "������"<<endl;
    cout << "����" << G.arcnum << "����" << endl;
    system("pause");
	return 0;
}


Status chooseroute(Graph &G)
{
    int n;
    cout << left << setw(16) << "0.������У��" << setw(16) << "1.������У��" << setw(16) << "2.�ֶ��곬��" << setw(16) << "3.�ȷ�����" << endl;
    cout << left << setw(16) << "4.�ȷ��и���Ժ" << setw(16) << "5.�°�ȼ��" << setw(16) << "6.��չ����" << setw(16) << "7.���������ٿ�" << endl;
    cout << left << setw(16) << "8.������ѧ��" << setw(16) << "9.���ũ��԰" << setw(16) << "10.�ȷ���������" << setw(16) << "11.�Ļ���������" << endl;
    cout << left << setw(16) << "12.�ƶ�����" << setw(16) << "13.����԰����" << setw(16) << "14.��Ȼ��԰" << setw(16) << "15.���㳡" << endl;
    cout << left << setw(16) << "16.�����" << setw(16) << "17.�ȷ�ʦ��ѧԺ" << setw(16) << "18.�ȷ�����վ" << setw(16) << "19.���̹㳡" << endl;
    cout << "��ѡ���˶�������:";
    cin >> n;
    if (n < 0 || n>19)
        cout << "�밴��ͼʾ������ţ�" << endl;
    
    else
    {

        //��ʵ���ջ����������������p[]������
        int P[V] = { 555 };   // ��¼�õ㵽�����������̵�·��
        double D[V] = { 0 };   // ��¼�õ㵽�����������Ȩֵ,,,,,,һֱ������ΪʲôcopyҲ�ܳ����ŷ���Ӧ�øĳ�double������

        Dijkstra_minTree(G, n, P, D);

        printf("���·��Ϊ��\n");
        for (int i = 0; i < G.locationnum; i++)
        {
            cout << G.location[i] << "��" << G.location[n] << "�����·��Ϊ";
            //printf("%d - %d�����·���еĶ����У�", i, n);
            cout << right << setw(16) << G.location[i]<<"-";
            int j = i;
            //����ÿһ�����·���϶���¼�ž����Ķ��㣬���Բ���Ƕ�׵ķ�ʽ������ɵõ��������·���ϵ����ж���



            //���������


            while (P[j] != 555)
            {                
                cout << G.location[int(P[j])] << "-";
                j = P[j];
            }





            cout << G.location[n];
            //printf("%d", n);
            cout<< "  ���·���ĳ���Ϊ:" << D[i] << "ǧ��" << endl;
        }
        /*printf("�õ㵽����������·������Ϊ:\n");
        for (int i = 1; i < G.locationnum; i++) {
            cout << G.location[n] << "-" << G.location[i] << ":" << D[i] << endl;
            //printf("%s - %s : %s \n", G.location[n], G.location[i], D[i]);
        }*/
        system("pause");

    }
    return 0;
}



void Dijkstra_minTree(Graph G, int v0, int p[V], double D[V])
{
    int final[V] = { 0 };//Ϊ������������һ�����ֵ������ȷ�ϸö����Ƿ��Ѿ��ҵ����·��
    //�Ը�������г�ʼ��
    for (int v = 0; v < G.locationnum; v++) {
        final[v] = 0;
        D[v] = G.distance[v0][v];
        p[v] = 555;

    }


    //������v0λ�±�Ķ���Ϊ��ʼ�㣬���Բ������ж�
    D[v0] = 0;
    final[v0] = 1;
    int k = 0;


    for (int i = 0; i < G.locationnum; i++)
    {
        double min = INFINITY;
        //ѡ�񵽸�����Ȩֵ��С�Ķ��㣬��Ϊ������ȷ�����·���Ķ���
        for (int w = 0; w < G.locationnum; w++)
        {
            if (!final[w])
            {
                if (D[w] < min) 
                {
                    k = w;
                    min = D[w];
                }
            }
        }


        //���øö���ı�־λΪ1�������´��ظ��ж�
        final[k] = 1;
        //��v0���������Ȩֵ���и���


        for (int w = 0; w < G.locationnum; w++) 
        {
            if (!final[w] && (min + G.distance[k][w] < D[w])) 
            {
                D[w] = min + G.distance[k][w];
                p[w] = k;//��¼�������·���ϴ��ڵĶ���

                //test
                //cout << p[w] << "  ";
                //test
            }
        }
    }
}


/*
printf("���·��Ϊ��\n");
for (int i = 1; i < G.locationnum; i++)
{
    printf("%d - %d�����·���еĶ����У�", i, n);
    printf(" %d-", i);
    int j = i;
    //����ÿһ�����·���϶���¼�ž����Ķ��㣬���Բ���Ƕ�׵ķ�ʽ������ɵõ��������·���ϵ����ж���
    while (P[j] != 0)
    {
        printf("%d-", P[j]);
        j = P[j];
    }
    cout << n << endl;
    //printf("0\n");
}
printf("�õ㵽����������·������Ϊ:\n");
for (int i = 1; i < G.locationnum; i++)
{
    cout << G.location[n] << "-" << G.location[i] << ":" << fixed << setprecision(2) << D[i] << endl;
}
system("pause");
/*if (n == 1)
{
    Dijkstra_minTree(G, 0, P, D);
    printf("���·��Ϊ��\n");
    for (int i = 1; i < G.locationnum; i++)
    {
            printf("%d - %d�����·���еĶ����У�", i, 0);
            printf(" %d-", i);
            int j = i;
            //����ÿһ�����·���϶���¼�ž����Ķ��㣬���Բ���Ƕ�׵ķ�ʽ������ɵõ��������·���ϵ����ж���
            while (P[j] != 0)
            {
                printf("%d-", P[j]);
                j = P[j];
            }
            cout << n << endl;
            //printf("0\n")
    }
    printf("�õ㵽����������·������Ϊ:\n");
    for (int i = 1; i < G.locationnum; i++)
    {
        cout << G.location[0] << "-" << G.location[i] << ":" << D[i] << endl;
        //printf("%d - %d : %d \n", G.location[0], G.location[i], D[i]);
    }
    system("pause");
}
else
{
    Dijkstra_minTree(G, n - 1, P, D);
    printf("���·��Ϊ��\n");
    for (int i = 1; i < G.locationnum; i++)
    {
        if (i != n)
        {
            printf("%d - %d�����·���еĶ����У�", i, n);
            printf(" %d-", i);
            int j = i;
            //����ÿһ�����·���϶���¼�ž����Ķ��㣬���Բ���Ƕ�׵ķ�ʽ������ɵõ��������·���ϵ����ж���
            while (P[j] != 0)
            {
                printf("%d-", P[j]);
                j = P[j];
            }
            cout << n << endl;
            //printf("0\n");
        }
    }
    printf("�õ㵽����������·������Ϊ:\n");
    for (int i = 1; i < G.locationnum; i++)
    {
        if (i != n - 1)
            cout << G.location[n - 1] << "-" << G.location[i] << ":" << D[i] << endl;
        //printf("%d - %d : %d \n", G.location[0], G.location[i], D[i]);
    }
    system("pause");
}*/


















/*
        double m;
        int P[20] = { 0 };   // ��¼���� 0 �������������̵�·��
        int D[20] = { 0 };   // ��¼���� 0 �������������Ȩֵ
        Dijkstra_minTree(G, n - 1, P, D);
        printf("���·��Ϊ��\n");
        for (int i = 1; i < G.locationnum; i++)
        {
            //cout << G.location[i - 1] << "-" << G.location[n - 1] << "�����·���еĶ�����";
            printf("%d - %d�����·���еĶ����У�", i, n);
            //cout << G.location[i - 1] << "-";
            printf(" %d-", i);
            int j = i;
            m = G.distance[n - 1][i-1];
            cout <<"   " << m << " ";
            //����ÿһ�����·���϶���¼�ž����Ķ��㣬���Բ���Ƕ�׵ķ�ʽ������ɵõ��������·���ϵ����ж���
            while (P[j] != 0)
            {
                printf("%d-", P[j]);
                j = P[j];
                m = m + G.distance[i-1][j-1];
            }
            G.distance[i-1][j-1] = m;
            cout << n << "   " <<m<< endl;
        }
        printf("�õ㵽����������·������Ϊ:\n");
        for (int i = 1; i < G.locationnum; i++)
        {
            cout << "����" << endl;
            if (i != n - 1)
            {
                cout << G.location[n - 1] << "-" << G.location[i] << ":" << G.distance[n - 1][i] << endl;
            }
            //printf("%d - %d : %d \n", G.location[n-1], G.location[i], D[i]);
        }
        system("pause");
        */




/*
//�������ͼ�ĳ�ʼ���������޷�����ıߵ����ݣ���Ϊ����

//�Ͻ�˹�����㷨��v0��ʾ����������ʼ�����������е��±�
void Dijkstra_minTree(Graph G, int v0, int p[20], int D[20])
{
    int final[20];//Ϊ������������һ�����ֵ������ȷ�ϸö����Ƿ��Ѿ��ҵ����·��
    //�Ը�������г�ʼ��
    for (int v = 0; v < G.locationnum; v++) 
    {
        final[v] = 0;
        D[v] = G.distance[v0][v];//����һЩv0��������ľ�����Ҫ�Լ��������д�뵽G.distamce[v0][v]
        p[v] = 0;
    }
    //������v0λ�±�Ķ���Ϊ��ʼ�㣬���Բ������ж�
    D[v0] = 0;
    final[v0] = 1;
    int k = 0;
    for (int i = 0; i < G.locationnum; i++)
    {
        int min = INFINITY;
        //ѡ�񵽸�����Ȩֵ��С�Ķ��㣬��Ϊ������ȷ�����·���Ķ���
        for (int w = 0; w < G.locationnum; w++) {
            if (!final[w]) {
                if (D[w] < min) {
                    k = w;
                    min = D[w];
                }
            }
        }
        //���øö���ı�־λΪ1�������´��ظ��ж�
        final[k] = 1;
        //��v0���������Ȩֵ���и���
        for (int w = 0; w < G.locationnum; w++) {
            if (!final[w] && (min + G.distance[k][w] < D[w])) {
                D[w] = min + G.distance[k][w];
                p[w] = k;//��¼�������·���ϴ��ڵĶ���
            }
        }
    }
}
*/