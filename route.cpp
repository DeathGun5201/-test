#include<fstream>
#include<iostream>
#include"route.h"
#include<iomanip>
#define INFINITY 65535
#define V 20

//这步操作只是读取两个文本文件之中的信息，没别的了
Status drawroute(Graph &G)//location顶点表，distance邻接矩阵，所有距离最大是5.2
{
    int i;
    G.arcnum = G.locationnum = 0;//初始化，用于计数同时保存结果 保存的是顶点的数量和边的数量
    string loca1, loca2;//暂存两个顶点
    double dis;//暂存距离
    int lloca1, lloca2;//记录loca1和loca2在定点表中的位置，然后将距离存入邻接矩阵，见第50行
    ifstream infile("LocatInfo.txt", ios::in); 	//以读的方式打开文件，如果文件不存在就打不开
    if (!infile)   				//测试是否成功打开
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile >> G.location[G.locationnum];//将文件的顶点载入顶点表
        G.locationnum++;//循环计数，顺便统计节点数
    }
    //对权值的初始化
    for (int i = 0; i < G.locationnum; i++)
    {
        for (int j = 0; j < G.locationnum; j++)
        {
            G.distance[i][j] = INFINITY;
        }
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
        //cout << G.distance[lloca1][lloca2] << endl;
    }
    infile.close();
    cout << "共有" << G.locationnum << "个顶点"<<endl;
    cout << "共有" << G.arcnum << "条边" << endl;
    system("pause");
	return 0;
}


Status chooseroute(Graph &G)
{
    int n;
    cout << left << setw(16) << "0.华航东校区" << setw(16) << "1.华航西校区" << setw(16) << "2.沃尔玛超市" << setw(16) << "3.廊坊六中" << endl;
    cout << left << setw(16) << "4.廊坊市福利院" << setw(16) << "5.新奥燃气" << setw(16) << "6.会展中心" << setw(16) << "7.开发区高速口" << endl;
    cout << left << setw(16) << "8.东方大学城" << setw(16) << "9.金丰农科园" << setw(16) << "10.廊坊市体育馆" << setw(16) << "11.文化艺术中心" << endl;
    cout << left << setw(16) << "12.移动大厦" << setw(16) << "13.人民公园东门" << setw(16) << "14.自然公园" << setw(16) << "15.万达广场" << endl;
    cout << left << setw(16) << "16.万向城" << setw(16) << "17.廊坊师范学院" << setw(16) << "18.廊坊高铁站" << setw(16) << "19.浙商广场" << endl;
    cout << "请选择运动起点序号:";
    cin >> n;
    if (n < 0 || n>19)
        cout << "请按照图示输入序号！" << endl;
    
    else
    {

        //其实最终还是这里跟函数里面p[]的问题
        int P[V] = { 555 };   // 记录该点到各个顶点的最短的路径
        double D[V] = { 0 };   // 记录该点到各个顶点的总权值,,,,,,一直不明白为什么copy也能出错，才发现应该改成double型数据

        Dijkstra_minTree(G, n, P, D);

        printf("最短路径为：\n");
        for (int i = 0; i < G.locationnum; i++)
        {
            cout << G.location[i] << "到" << G.location[n] << "的最短路径为";
            //printf("%d - %d的最短路径中的顶点有：", i, n);
            cout << right << setw(16) << G.location[i]<<"-";
            int j = i;
            //由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点



            //这里的问题


            while (P[j] != 555)
            {                
                cout << G.location[int(P[j])] << "-";
                j = P[j];
            }





            cout << G.location[n];
            //printf("%d", n);
            cout<< "  最短路径的长度为:" << D[i] << "千米" << endl;
        }
        /*printf("该点到各顶点的最短路径长度为:\n");
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
    int final[V] = { 0 };//为各个顶点配置一个标记值，用于确认该顶点是否已经找到最短路径
    //对各数组进行初始化
    for (int v = 0; v < G.locationnum; v++) {
        final[v] = 0;
        D[v] = G.distance[v0][v];
        p[v] = 555;

    }


    //由于以v0位下标的顶点为起始点，所以不用再判断
    D[v0] = 0;
    final[v0] = 1;
    int k = 0;


    for (int i = 0; i < G.locationnum; i++)
    {
        double min = INFINITY;
        //选择到各顶点权值最小的顶点，即为本次能确定最短路径的顶点
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


        //设置该顶点的标志位为1，避免下次重复判断
        final[k] = 1;
        //对v0到各顶点的权值进行更新


        for (int w = 0; w < G.locationnum; w++) 
        {
            if (!final[w] && (min + G.distance[k][w] < D[w])) 
            {
                D[w] = min + G.distance[k][w];
                p[w] = k;//记录各个最短路径上存在的顶点

                //test
                //cout << p[w] << "  ";
                //test
            }
        }
    }
}


/*
printf("最短路径为：\n");
for (int i = 1; i < G.locationnum; i++)
{
    printf("%d - %d的最短路径中的顶点有：", i, n);
    printf(" %d-", i);
    int j = i;
    //由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点
    while (P[j] != 0)
    {
        printf("%d-", P[j]);
        j = P[j];
    }
    cout << n << endl;
    //printf("0\n");
}
printf("该点到各顶点的最短路径长度为:\n");
for (int i = 1; i < G.locationnum; i++)
{
    cout << G.location[n] << "-" << G.location[i] << ":" << fixed << setprecision(2) << D[i] << endl;
}
system("pause");
/*if (n == 1)
{
    Dijkstra_minTree(G, 0, P, D);
    printf("最短路径为：\n");
    for (int i = 1; i < G.locationnum; i++)
    {
            printf("%d - %d的最短路径中的顶点有：", i, 0);
            printf(" %d-", i);
            int j = i;
            //由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点
            while (P[j] != 0)
            {
                printf("%d-", P[j]);
                j = P[j];
            }
            cout << n << endl;
            //printf("0\n")
    }
    printf("该点到各顶点的最短路径长度为:\n");
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
    printf("最短路径为：\n");
    for (int i = 1; i < G.locationnum; i++)
    {
        if (i != n)
        {
            printf("%d - %d的最短路径中的顶点有：", i, n);
            printf(" %d-", i);
            int j = i;
            //由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点
            while (P[j] != 0)
            {
                printf("%d-", P[j]);
                j = P[j];
            }
            cout << n << endl;
            //printf("0\n");
        }
    }
    printf("该点到各顶点的最短路径长度为:\n");
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
        int P[20] = { 0 };   // 记录顶点 0 到各个顶点的最短的路径
        int D[20] = { 0 };   // 记录顶点 0 到各个顶点的总权值
        Dijkstra_minTree(G, n - 1, P, D);
        printf("最短路径为：\n");
        for (int i = 1; i < G.locationnum; i++)
        {
            //cout << G.location[i - 1] << "-" << G.location[n - 1] << "的最短路径中的顶点有";
            printf("%d - %d的最短路径中的顶点有：", i, n);
            //cout << G.location[i - 1] << "-";
            printf(" %d-", i);
            int j = i;
            m = G.distance[n - 1][i-1];
            cout <<"   " << m << " ";
            //由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点
            while (P[j] != 0)
            {
                printf("%d-", P[j]);
                j = P[j];
                m = m + G.distance[i-1][j-1];
            }
            G.distance[i-1][j-1] = m;
            cout << n << "   " <<m<< endl;
        }
        printf("该点到各顶点的最短路径长度为:\n");
        for (int i = 1; i < G.locationnum; i++)
        {
            cout << "这里" << endl;
            if (i != n - 1)
            {
                cout << G.location[n - 1] << "-" << G.location[i] << ":" << G.distance[n - 1][i] << endl;
            }
            //printf("%d - %d : %d \n", G.location[n-1], G.location[i], D[i]);
        }
        system("pause");
        */




/*
//上面对于图的初始化还少了无法到达的边的数据，即为无穷

//迪杰斯特拉算法，v0表示有向网中起始点所在数组中的下标
void Dijkstra_minTree(Graph G, int v0, int p[20], int D[20])
{
    int final[20];//为各个顶点配置一个标记值，用于确认该顶点是否已经找到最短路径
    //对各数组进行初始化
    for (int v = 0; v < G.locationnum; v++) 
    {
        final[v] = 0;
        D[v] = G.distance[v0][v];//还有一些v0到其它点的距离需要自己求出来并写入到G.distamce[v0][v]
        p[v] = 0;
    }
    //由于以v0位下标的顶点为起始点，所以不用再判断
    D[v0] = 0;
    final[v0] = 1;
    int k = 0;
    for (int i = 0; i < G.locationnum; i++)
    {
        int min = INFINITY;
        //选择到各顶点权值最小的顶点，即为本次能确定最短路径的顶点
        for (int w = 0; w < G.locationnum; w++) {
            if (!final[w]) {
                if (D[w] < min) {
                    k = w;
                    min = D[w];
                }
            }
        }
        //设置该顶点的标志位为1，避免下次重复判断
        final[k] = 1;
        //对v0到各顶点的权值进行更新
        for (int w = 0; w < G.locationnum; w++) {
            if (!final[w] && (min + G.distance[k][w] < D[w])) {
                D[w] = min + G.distance[k][w];
                p[w] = k;//记录各个最短路径上存在的顶点
            }
        }
    }
}
*/