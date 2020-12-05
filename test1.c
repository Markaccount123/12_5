#include"SList.h"

int main()
{
	//SListNode* pList = NULL;  // 这个就表示单链表
	SListNode* phead = NULL;//只给了一个头指针
	SListPushBack(phead, 1);
	SListPushBack(phead, 2);
	SListPushBack(phead, 3);
	SListPushBack(phead, 4);
	SListPrint(phead);
	return 0;
}


