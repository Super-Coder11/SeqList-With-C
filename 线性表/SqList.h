#pragma once
#include "Stdio.h"
#include "stdlib.h"

typedef int SLDaTy;//重定义为线性表数据类型


typedef struct SeqList//定义静态顺序表结构体
{
	SLDaTy* a;
	int size;    //表示存入了多少数据
	int capacity;//表示实际空间容量有多大
}SL;

//打印线性表中的所有元素
void SeqListPrint(SL* Ps);
//检查容量是否堆满，若堆满则扩容
void SeqListCheckCapacity(SL* Ps);
//顺序表初始化
void SeqListInit(SL* Ps);
//在顺序表尾部插入一个数据
void SeqListPushBack(SL* Ps, SLDaTy x);
//顺序表销毁
void SeqListDistory(SL* Ps);
//从尾部删除一个数据
void SeqListPopBack(SL* Ps);
//从头部插入一个数据
void SeqListPushFront(SL* Ps, SLDaTy x);
//从头部删除一个数据
void SeqListPopFront(SL* Ps);
//查找一个数据，并返回该数据在线性表中的位置
int SeqListFind(SL* Ps, SLDaTy x);
//在顺序变量给定的位置插入一个数据
void SeqListInsert(SL* Ps, int pos, SLDaTy x);
//从顺序表的任意一个位置擦除一个数据
void SeqListErase(SL* Ps, int pos);

