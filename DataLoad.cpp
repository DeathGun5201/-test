#include"DataLoad.h"
#include"LinkList.h"
#include <iostream>
#include <fstream>
using namespace std;

void ReadFile(LinkList& L)
{
    cout << "到这里" << endl;
    int i = 0; int num = 0;
    ifstream infile("User.txt", ios::in); 	//以读的方式打开文件，如果文件不存在就打不开
    if (!infile)   				//测试是否成功打开
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        LNode* p = new LNode;
        infile >> p->data.id >> p->data.name >> p->data.sex >> p->data.age;
        p->next = L->next;
        L->next = p;
    }
    infile.close();
}


void WriteFile(LinkList& L)
{

}