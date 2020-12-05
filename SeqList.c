#include "SeqList.h"
//数据结构的每一种类型都是一种方式---顺序表---动态开辟了一个数组，实现他的头插头删，尾插尾删
//初始化
void SeqListInit(SeqList* ps)
{
	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;

	ps->a= (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);//直接结束掉程序
	}
	ps->size = 0;				
	ps->capacity = 4;
}
//释放指针
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;//避免了野指针的出现
	ps->size = ps->capacity = 0;
}
//打印
void SeqListPrint(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//检查容量
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	//增容
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);//很暴力，一般情况下是不建议这样的。
		}
	}
}
//尾插
//void SeqListPushBack(SeqList* ps, SLDateType x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	ps->a[ps->size] = x; //因为ps->size 是从0开始初始化的  尾插：是从最后一个有效位的后面插入数值
//	ps->size++;
//}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	SeqListInsert(ps, ps->size, x);
}




//尾删
//void SeqListPopBack(SeqList* ps)
//{
//	assert(ps);
//	//ps->a[ps->size - 1] = 0; // 
//	ps->size--;
//}
//尾删可以调用SeqListErase来实现
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}

//头插
//void SeqListPushFront(SeqList* ps, SLDateType x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	int end = ps->size - 1;
//	while (end >= 0)
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	SeqListInsert(ps, 0, x);
}





//头删
//void SeqListPopFront(SeqList* ps)
//{
//	assert(ps);
//	int start = 0;
//	while (start < ps->size - 1)
//	{
//		ps->a[start] = ps->a[start + 1];
//		start++;
//	}
//	ps->size--;
//}
//
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, 0);
}




//任意位置的插入
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size && pos >= 0);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//在任意位置删除（直接找到那个位置，然后让后面的数据往前覆盖）
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}


int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}
//顺序表
//1.可动态增长的数组
//2.数据在数组中存储是必须是连续的

//缺点
//1.中间或者头部的插入删除很慢，需要挪动数据。时间复杂度是O(N)
//2.空间不够时，增容会有一定消耗和空间浪费（因为你每次capacity都直接变为原来的2倍）

//优点
//1.随机访问
//2.缓存利用率比较高(每次加载一段数据，不是一个一个的加载)预加载有一定的优势