#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a; //ָ��̬���ٵ�����
	int size;  // ��Ч���ݵĸ���
	int capacity;//�����ռ�Ĵ�С
}SeqList;
//��ʼ���ṹ��
void SeqListInit(SeqList* ps);

//ֻҪ��ʼ����ʹ����malloc���Ǿ�Ҫ���ͷ�ָ��
void SeqListDestory(SeqList* ps);

//��ӡ
void SeqListPrint(SeqList* ps);

//�������
void SeqListCheckCapacity(SeqList* ps);

//β��βɾ   ͷ��ͷɾ
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
//����λ�ò���
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
//����λ��ɾ��
void SeqListErase(SeqList* ps, int pos);
//˳������
int SeqListFind(SeqList* ps, SLDateType x);



//����ʵ�ʵ�OJ��ϰ��Ŀ
//��ʧ������
//��Ŀ������nums������0��n��������������������ȱ����һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
//ʵ����[3,0,1]
//�����2