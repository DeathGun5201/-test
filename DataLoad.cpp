#include"DataLoad.h"
#include"LinkList.h"
#include <iostream>
#include <fstream>
using namespace std;

void ReadFile(LinkList& L)
{
    cout << "������" << endl;
    int i = 0; int num = 0;
    ifstream infile("User.txt", ios::in); 	//�Զ��ķ�ʽ���ļ�������ļ������ھʹ򲻿�
    if (!infile)   				//�����Ƿ�ɹ���
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