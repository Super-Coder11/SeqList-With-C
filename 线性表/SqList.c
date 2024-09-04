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
		//若空间不足则扩容二倍，若没有空间，则开辟新空间
		int newcapacity = (Ps->capacity == 0 ? 4 : Ps->capacity * 2);
		//使用realloc开辟或者扩容内存空间
		SLDaTy* Tem = (SLDaTy*)realloc(Ps->a, newcapacity * sizeof(SLDaTy));
		//如若开辟内存空间失败，则退出程序
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
	//挪动数据
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
	//检测插入操作是否造成了数据存储的物理位置不连续
	if (pos <= Ps->size)
	{
		//检测内存空间是否足够，若不够则扩容
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
	int begin = pos;//定义开始位置为pos位
	if (Ps->size > 0)
	{
		for (begin = pos; begin < Ps->size - 1; begin++)
		{
			Ps->a[begin] = Ps->a[begin + 1];
		}

		Ps->size--;
	}
}


