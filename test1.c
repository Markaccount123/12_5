#include"SList.h"

int main()
{
	//SListNode* pList = NULL;  // ����ͱ�ʾ������
	SListNode* phead = NULL;//ֻ����һ��ͷָ��
	SListPushBack(phead, 1);
	SListPushBack(phead, 2);
	SListPushBack(phead, 3);
	SListPushBack(phead, 4);
	SListPrint(phead);
	return 0;
}


