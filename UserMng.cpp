#include"LinkList.h"
#include<iostream>
using namespace std;
#include<string.h>
#include"UserMng.h"

void AddUser(LinkList &L)
{
	int n,i;
	cout << "�������û��ĸ���" << endl;
	cin >> n;
	L = new LNode;
	L->next = NULL;//LΪͷ���
	for (i = 0; i < n; i++)
	{
		LNode* p = new LNode;
		while (1)
		{
			cout << "�������" << i+1 << "���û����ֻ���" << endl;
			cin >> p->data.id;//p->data�����õ���ָ�����ͣ����Ǻ������ڽṹ��Ƕ�ײ�����ָ�룬��"."���ɣ�
			//cout << p->data.id << endl;
			//cout << sizeof(p->data.id) << endl;
			//cout << size(p->data.id);
			//IsValid_UserId(p->data.id,n);

			if (IsValid_UserId(p->data.id,n,L) == false)
				printf("�����ʽ�������������룡�������ǵ�һ�����ֲ���1���߳��ȴ���11λ��\n");
			else
				break;
		}
		cout << "�������" << i+1 << "���û����ǳ�" << endl;
		cin >> p->data.name;
		cout << "�������" << i+1 << "���û����Ա�" << endl;
		cin >> p->data.sex;
		cout << "�������" << i+1 << "���û�������" << endl;
		cin >> p->data.age;
		p->next = L->next;
		p = L->next;
	}
}

bool IsValid_UserId(string Id,int n,LinkList &L)
{
	int num = size(Id);
	//cout << num << endl;
	//cout << Id[0] << endl;��Щ�����ҵĵ��Դ���Ĵ��룬��Ҫ��Ϊ�˵���
	if ((num == 11) && (Id[0] == '1'))
	{
		LNode* t = new LNode;
		t = L->next;
		//for (int i = 0; i < n; i++)
		//{
			//cout << "ִ�е���" << endl;
			//cout << t->data.id << endl;
			//t = t->next;
			/*if (t->data.id == Id)//����ʹ�����ֹ�ϵ��������Ƚ��ַ����Ƿ����
			{
				printf("�����ֻ�����ͬ��������������¼�飡");
				break;
			}
			else
				t = t->next;*/
			//����������ԭ���ˣ������һ�û�����������ݣ������ܽ��бȽϣ�ֻ����������֮���ٽ��л��ܱȽϣ��������ﶼ�����ù�
		//}
		return true;
	}	
	else
		return false;
	return 0;
}


void DeleteUser(LinkList& L)
{

}
