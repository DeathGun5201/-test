#include"DataLoad.h"
#include"LinkList.h"
#include <iostream>
#include <fstream>
using namespace std;
#include"Queue.h"
#include<string>//������getline���ǿ��ǵ������ã���Ϊ����ȡ�ո�
#include<sstream>
#include<iomanip>

int ReadFile(LinkList& L)
{
    string a[8];//getline�������ַ��������Ժ��汨�Ĵ���û���ҵ�����
    int i = 0; int num = 0; int j = 0;
    int count = 0;
    int b[7];
    int m,n;
    string str;//infile����Ϊ�ļ�ָ��
    ifstream infile("User.txt", ios::in); 	//������ķ�ʽ���ļ�������ļ������ھʹ򲻿�������˵�Ƕ��ķ�ʽ���Ҹ㲻����
    if (!infile)   				//�����Ƿ�ɹ���
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        num = 0;
        LNode* p = new LNode;
        CreatQ(p->data.sport);
        //cout << "1";//�����֤���ҵĲ��룬����txt�ļ�����ܿ�һ�У�������
        infile >> p->data.id >> p->data.name >> p->data.sex >> p->data.age;
        getline(infile, str);
        istringstream string_to_num(str);

        while (string_to_num >> b[i])
        {
            EnQueue(p->data.sport, b[i]);
            num++;
        }
        /*while (string_to_num >> n)
        {
            string_to_num >> b[i];
            EnQueue(p->data.sport, b[i]);
            num++;
        }*/
        /*for (i = 0; i < num; i++)
        {
            
            //if (b[i] != -858993460)
        }*/
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
        count++;
    }
    if (count != 0)
        cout << "�����ļ��ɹ�\n";
    infile.close();
    /*else
    {
        cout << "ԭ�����ı��ļ��е���Ϣ�Ѿ�ȫ�����룬�벻Ҫ�ظ�������" << endl;
    }*/
    return 0;
}

//ÿ����������Ĵ��붼�ᵼ��vs����
int WriteFile(LinkList& L)//���������Ϣд���ļ�
{
    int i = 0;
    string str; int m;
    ofstream outfile("User.txt",ios::in);    //�������������
    if (!outfile)
    {
        cout << "���ļ�ʧ��" << endl;
        exit(1);
    }
    LNode* p=L->next;
    //cout << m;//�����˶����ݵĸ���
    while (p)
    {
        outfile << p->data.id << " " << p->data.name << " " << p->data.sex << " " << p->data.age<<" ";
        m = QueueLength(p->data.sport);
        for (int i = 0; i < m; i++)
        {
            outfile << p->data.sport.base[i]<<" ";
        }
        if (p->next != NULL)
        {
            outfile << "\n";
        }
        p = p->next;
    }
   
    
    cout << "��Ϣ����ɹ�!" << endl;
    outfile.close();    //�ر��ļ�;
    return 0;
}


//д���ļ����ǰ�L֮��Ľڵ㶼��д��ȥ


//����ΪһЩʧ�ܴ��룬���вο���ֵ

//while (p)
   //{

       //cout << p->data.sport.base[i];
       /*for (int i = 0; i < m; i++)
       {
           cout << "��������" << endl;
           cout << p->data.sport.base[i];
           p->next = L->next;
           L->next = p;
       }*/
       //i++;
      // p = p->next;
  // }


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

    /*while (p)
        {
            outfile << p->data.id << " " << p->data.name << " " << p->data.sex << " " << p->data.age;
            for (int i = 0; i < m; i++)
            {
                outfile << p->data.sport.base[i];
            }
            p->next = L->next;
            L->next = p;
        }
        */