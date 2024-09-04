#include "SqList.h"

void Test_List()
{
	SL List;
	int locate;
	SeqListInit(&List);

	SeqListPushBack(&List,1);
	SeqListPushBack(&List,2);
	SeqListPushBack(&List,3);
	SeqListPushBack(&List,4);
	SeqListPushBack(&List,5);
	SeqListInsert(&List, 2, 11);

	SeqListErase(&List,2);

	locate = SeqListFind(&List, 11);

	SeqListPrint(&List);

	printf("Locate:%d \n", locate);

	SeqListDistory(&List);
}

int main()
{
	Test_List();
	printf("%c", 110);
	return 0;
}