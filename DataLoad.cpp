#include"DataLoad.h"
#include"LinkList.h"
#include <iostream>
#include <fstream>
using namespace std;
#include"Queue.h"
#include<string>//我想用getline但是考虑到不会用，因为他读取空格
#include<sstream>
#include<iomanip>



void ReadFile(LinkList& L)
{
    string a[8];//getline参数是字符串，所以后面报的错是没有找到参数
    int i = 0; int num = 0; int j = 0;
    int b[7];
    string str;
    ifstream infile("User.txt", ios::in); 	//以输入的方式打开文件，如果文件不存在就打不开，还有说是读的方式，我搞不懂了
    if (!infile)   				//测试是否成功打开
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        LNode* p = new LNode;
        CreatQ(p->data.sport);
        cout << "1";//这个验证了我的猜想，就是txt文件最后不能空一行！！！！
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
            cout << "ok";//这里设置以读取行结束
            //从这里我可以推出infile是跟随着不断向前移动着的
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
        cout << "原来的文本文件中的信息已经全部导入，请不要重复操作！" << endl;
    }*/
}


void WriteFile(LinkList& L)//把输入的信息写入文件
{
    string str; int m;
    ofstream outfile;    //定义输出流对象
    string filePath = "User.txt";
    outfile.open(filePath);    //打开文件
    if (!outfile)
    {
        cout << "打开文件失败" << endl;
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
    /*cout << "请按照以下格式向文本文件中写入数据(注意：以空格作为间隔！)" << endl;
    //向文件中写入数据
    cout << std::left << setw(16) << "用户号" << std::left << setw(16) << "昵称" << std::left << setw(16) << "性别" << std::left << setw(16) << "年龄" << std::left << setw(16) << "运动数据" << "\n";
    LNode* p = new LNode;
    cin >> p->data.id >> p->data.name >> p->data.sex >> p->data.age;
    getline(cin,str);
    outfile << p->data.id <<" " << p->data.name << " " << p->data.sex <<" " << p->data.age <<" " << str;
    p->next = L->next;
    L->next = p;
    cout << "到这里" << endl;*/
    cout << "信息保存成功!" << endl;
    outfile.close();    //关闭文件;
}