#pragma once
#include<stdio.h>

typedef int SLDateType;
//结点
//里面存储的方式应该是数据和指针，通过指针来将他们链接在一起
//(此时头插不再需要挪动数据，我可以直接申请一个空间，再用一个指针和那个链接)
typedef struct SListNode
{
	SLDateType date;
	struct SListNode* nest; //(其实这个结构体指针里面存的是下一个需要访问的地址)
}SListNode; 

//单链表的尾插
void SListPushBack(SListNode* phead, SLDateType x);
////尾删
//void SListPopBack(SListNode* phead);
////头插
//void SListPushFront(SListNode* phead, SLDateType x);
////头删
//void SListPushFront(SListNode* phead);
//
////打印
//void SListPrint(SListNode* phead);

