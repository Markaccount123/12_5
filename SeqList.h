#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a; //指向动态开辟的数组
	int size;  // 有效数据的个数
	int capacity;//容量空间的大小
}SeqList;
//初始化结构体
void SeqListInit(SeqList* ps);

//只要初始化就使用了malloc，那就要有释放指针
void SeqListDestory(SeqList* ps);

//打印
void SeqListPrint(SeqList* ps);

//检查容量
void SeqListCheckCapacity(SeqList* ps);

//尾插尾删   头插头删
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
//任意位置插入
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
//任意位置删除
void SeqListErase(SeqList* ps, int pos);
//顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);



//这里实际到OJ练习题目
//消失的数字
//题目：数组nums包含从0到n的所有整数，但是其中缺少了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//实例：[3,0,1]
//输出：2