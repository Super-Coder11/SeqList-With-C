#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

void SeqListPrint(SL* Ps)
{
	for (int i = 0; i < Ps->size; i++)
	{
		printf("%d ", Ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* Ps)
{
	if (Ps->size == Ps->capacity)
	{
		//���ռ䲻�������ݶ�������û�пռ䣬�򿪱��¿ռ�
		int newcapacity = (Ps->capacity == 0 ? 4 : Ps->capacity * 2);
		//ʹ��realloc���ٻ��������ڴ�ռ�
		SLDaTy* Tem = (SLDaTy*)realloc(Ps->a, newcapacity * sizeof(SLDaTy));
		//���������ڴ�ռ�ʧ�ܣ����˳�����
		if (Tem == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		Ps->a = Tem;
		Ps->capacity = newcapacity;
	}
}

void SeqListDistory(SL* Ps)
{
	free(Ps->a);
	Ps->a = NULL;
	Ps->capacity = Ps->size = 0;
}

void SeqListInit(SL* Ps)
{
	Ps->a = NULL;
	Ps->size = Ps->capacity = 0;
}

void SeqListPushBack(SL* Ps, SLDaTy x)
{
	SeqListCheckCapacity(Ps);

	Ps->a[Ps->size] = x;
	Ps->size++;
}

void SeqListPopBack(SL* Ps)
{
	if (Ps->size > 0)
		Ps->size--;
	else
		Ps->size = 0;
}

void SeqListPushFront(SL* Ps, SLDaTy x)
{
	//Ų������
	int end = Ps->size - 1;
	SeqListCheckCapacity(Ps);
	for(int i = end; i >= 0; i--)
	{
		Ps->a[i + 1] = Ps->a[i];
	}
	Ps->a[0] = x;
	Ps->size++;
}

void SeqListPopFront(SL* Ps)
{
	int begin = 0;
	if (Ps->size > 0)
	{
		for (begin = 0; begin < (Ps->size - 1); begin++)
		{
			Ps->a[begin] = Ps->a[begin + 1];
		}
		Ps->size--;
	}
}

int SeqListFind(SL* Ps, SLDaTy x)
{
	int find = 0;
	for (find = 0; find < (Ps->size); find++)
	{
		if (Ps->a[find] == x)
		{
			return find;
		}
	}
	return -1;
}

void SeqListInsert(SL* Ps, int pos, SLDaTy x)
{	
	//����������Ƿ���������ݴ洢������λ�ò�����
	if (pos <= Ps->size)
	{
		//����ڴ�ռ��Ƿ��㹻��������������
		SeqListCheckCapacity(Ps);
		int end = Ps->size - 1;
		for (end = Ps->size - 1; end >= pos; end--)
		{
			Ps->a[end + 1] = Ps->a[end];
		}
		Ps->a[pos] = x;
		Ps->size++;
	}
	else
	{ 
		printf("error insert\n");
		exit(-1);
	}
}

void SeqListErase(SL* Ps, int pos)
{
	int begin = pos;//���忪ʼλ��Ϊposλ
	if (Ps->size > 0)
	{
		for (begin = pos; begin < Ps->size - 1; begin++)
		{
			Ps->a[begin] = Ps->a[begin + 1];
		}

		Ps->size--;
	}
}


