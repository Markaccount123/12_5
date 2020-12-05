#include"SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d", cur->date);
		//一定要牢记，你的cur一定不敢写cur++，因为你加的只是一个指针的大小，但是你怎么敢保证他的下一个地址刚好为一个指针的大小，大小时不确定的
		cur = cur->nest;
	}
}
//尾插
void SListPushBack(SListNode* phead, SLDateType x)
{
	SListNode* tail = phead;
	//while (tail->nest != NULL)//
	//{
	//	tail = tail->nest;//这里如果这样写，你就会发现在跳出来的时候他已经指向NULL了，然而你还去解引用它，程序就会崩溃
	//}
	while (tail->nest != NULL)//
	{
		tail = tail->nest;//这里要是想不通可以看课件上面的那个图
	}
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	newNode->date = x;
	newNode->nest = NULL;
	tail->nest = newNode;
}

//尾删
//void SListPopBack(SListNode* phead)
//{
//
//}