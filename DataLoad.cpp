#include"DataLoad.h"
#include"LinkList.h"
#include <iostream>
#include <fstream>
using namespace std;
#include"Queue.h"
#include<string>//我想用getline但是考虑到不会用，因为他读取空格
#include<sstream>
#include<iomanip>

int ReadFile(LinkList& L)
{
    string a[8];//getline参数是字符串，所以后面报的错是没有找到参数
    int i = 0; int num = 0; int j = 0;
    int count = 0;
    int b[7];
    int m,n;
    string str;//infile被称为文件指针
    ifstream infile("User.txt", ios::in); 	//以输入的方式打开文件，如果文件不存在就打不开，还有说是读的方式，我搞不懂了
    if (!infile)   				//测试是否成功打开
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (!infile.eof())
    {
        num = 0;
        LNode* p = new LNode;
        CreatQ(p->data.sport);
        //cout << "1";//这个验证了我的猜想，就是txt文件最后不能空一行！！！！
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
            cout << "ok";//这里设置以读取行结束
            //从这里我可以推出infile是跟随着不断向前移动着的
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
        cout << "载入文件成功\n";
    infile.close();
    /*else
    {
        cout << "原来的文本文件中的信息已经全部导入，请不要重复操作！" << endl;
    }*/
    return 0;
}

//每次运行这里的代码都会导致vs崩溃
int WriteFile(LinkList& L)//把输入的信息写入文件
{
    int i = 0;
    string str; int m;
    ofstream outfile("User.txt",ios::in);    //定义输出流对象
    if (!outfile)
    {
        cout << "打开文件失败" << endl;
        exit(1);
    }
    LNode* p=L->next;
    //cout << m;//这是运动数据的个数
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
   
    
    cout << "信息保存成功!" << endl;
    outfile.close();    //关闭文件;
    return 0;
}


//写入文件就是吧L之后的节点都给写进去


//以下为一些失败代码，具有参考价值

//while (p)
   //{

       //cout << p->data.sport.base[i];
       /*for (int i = 0; i < m; i++)
       {
           cout << "到这里了" << endl;
           cout << p->data.sport.base[i];
           p->next = L->next;
           L->next = p;
       }*/
       //i++;
      // p = p->next;
  // }


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