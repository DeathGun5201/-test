#include"DataLoad.h"
#include"LinkList.h"
#include <iostream>
#include <fstream>
using namespace std;
#include"Queue.h"
#include<string>//������getline���ǿ��ǵ������ã���Ϊ����ȡ�ո�
#include<sstream>
#include<iomanip>



void ReadFile(LinkList& L)
{
    string a[8];//getline�������ַ��������Ժ��汨�Ĵ���û���ҵ�����
    int i = 0; int num = 0; int j = 0;
    int b[7];
    string str;
    ifstream infile("User.txt", ios::in); 	//������ķ�ʽ���ļ�������ļ������ھʹ򲻿�������˵�Ƕ��ķ�ʽ���Ҹ㲻����
    if (!infile)   				//�����Ƿ�ɹ���
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        LNode* p = new LNode;
        CreatQ(p->data.sport);
        cout << "1";//�����֤���ҵĲ��룬����txt�ļ�����ܿ�һ�У�������
        infile >> p->data.id >> p->data.name >> p->data.sex >> p->data.age;
        getline(infile, str);
        istringstream string_to_num(str);
        for (i = 0; i < 7; i++)
        {
            string_to_num >> b[i];
            if (b[i] != -858993460)
                EnQueue(p->data.sport, b[i]);
        }
        p->next = L->next;
        L->next = p;
        /*while (getline(infile, a[i]))
        {
            cout << "ok";//���������Զ�ȡ�н���
            //�������ҿ����Ƴ�infile�Ǹ����Ų�����ǰ�ƶ��ŵ�
        }

        while (j % 2 == 0)
        {
            b[num] = Number(a[j]);
        }*/
        //cout << b[i];
        i++;
    }
    infile.close();
    
    /*else
    {
        cout << "ԭ�����ı��ļ��е���Ϣ�Ѿ�ȫ�����룬�벻Ҫ�ظ�������" << endl;
    }*/
}


void WriteFile(LinkList& L)//���������Ϣд���ļ�
{
    string str; int m;
    ofstream outfile;    //�������������
    string filePath = "User.txt";
    outfile.open(filePath);    //���ļ�
    if (!outfile)
    {
        cout << "���ļ�ʧ��" << endl;
        exit(1);
    }
    LNode* p = L->next;
    m = QueueLength(p->data.sport);
    while (p)
    {
        outfile << p->data.id << " " << p->data.name << " " << p->data.sex << " " << p->data.age;
        for (int i = 0; i < m; i++)
        {
            outfile << p->data.sport.base[i];
        }
        p->next = L->next;
        L->next = p;
    }
    /*cout << "�밴�����¸�ʽ���ı��ļ���д������(ע�⣺�Կո���Ϊ�����)" << endl;
    //���ļ���д������
    cout << std::left << setw(16) << "�û���" << std::left << setw(16) << "�ǳ�" << std::left << setw(16) << "�Ա�" << std::left << setw(16) << "����" << std::left << setw(16) << "�˶�����" << "\n";
    LNode* p = new LNode;
    cin >> p->data.id >> p->data.name >> p->data.sex >> p->data.age;
    getline(cin,str);
    outfile << p->data.id <<" " << p->data.name << " " << p->data.sex <<" " << p->data.age <<" " << str;
    p->next = L->next;
    L->next = p;
    cout << "������" << endl;*/
    cout << "��Ϣ����ɹ�!" << endl;
    outfile.close();    //�ر��ļ�;
}