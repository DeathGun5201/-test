#pragma once
#include"LinkList.h"
//����йض��еĺ���ͷ����
Status CreatQ(SqQueue& Q);//����ն���
Status QueueLength(SqQueue Q);//������г���
Status EnQueue(SqQueue& Q, int e);//���β������Ԫ��
Status DeQueue(SqQueue& Q);//ɾ����ͷԪ��