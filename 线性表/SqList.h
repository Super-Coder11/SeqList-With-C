#pragma once
#include "Stdio.h"
#include "stdlib.h"

typedef int SLDaTy;//�ض���Ϊ���Ա���������


typedef struct SeqList//���徲̬˳���ṹ��
{
	SLDaTy* a;
	int size;    //��ʾ�����˶�������
	int capacity;//��ʾʵ�ʿռ������ж��
}SL;

//��ӡ���Ա��е�����Ԫ��
void SeqListPrint(SL* Ps);
//��������Ƿ������������������
void SeqListCheckCapacity(SL* Ps);
//˳����ʼ��
void SeqListInit(SL* Ps);
//��˳���β������һ������
void SeqListPushBack(SL* Ps, SLDaTy x);
//˳�������
void SeqListDistory(SL* Ps);
//��β��ɾ��һ������
void SeqListPopBack(SL* Ps);
//��ͷ������һ������
void SeqListPushFront(SL* Ps, SLDaTy x);
//��ͷ��ɾ��һ������
void SeqListPopFront(SL* Ps);
//����һ�����ݣ������ظ����������Ա��е�λ��
int SeqListFind(SL* Ps, SLDaTy x);
//��˳�����������λ�ò���һ������
void SeqListInsert(SL* Ps, int pos, SLDaTy x);
//��˳��������һ��λ�ò���һ������
void SeqListErase(SL* Ps, int pos);

