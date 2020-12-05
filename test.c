#include "SeqList.h"
//测试头尾插入删除
void TestSeqList1()
{
	SeqList s;  // 如果不初始化这个结构体，里面都是随机值
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 6);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s,2,5);
	SeqListPrint(&s);

	SeqListErase(&s,2);
	SeqListPrint(&s);

	

	int pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	SeqListPrint(&s);

	SeqListDestory(&s);

}

int main()
{
	TestSeqList1();
	return 0;
}
//顺序表的缺陷---一定程度的浪费空间
//为了能更好的解决这个问题引入了链表这个概念

