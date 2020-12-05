#include "SeqList.h"
//���ݽṹ��ÿһ�����Ͷ���һ�ַ�ʽ---˳���---��̬������һ�����飬ʵ������ͷ��ͷɾ��β��βɾ
//��ʼ��
void SeqListInit(SeqList* ps)
{
	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;

	ps->a= (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);//ֱ�ӽ���������
	}
	ps->size = 0;				
	ps->capacity = 4;
}
//�ͷ�ָ��
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;//������Ұָ��ĳ���
	ps->size = ps->capacity = 0;
}
//��ӡ
void SeqListPrint(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//�������
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	//����
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);//�ܱ�����һ��������ǲ����������ġ�
		}
	}
}
//β��
//void SeqListPushBack(SeqList* ps, SLDateType x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	ps->a[ps->size] = x; //��Ϊps->size �Ǵ�0��ʼ��ʼ����  β�壺�Ǵ����һ����Чλ�ĺ��������ֵ
//	ps->size++;
//}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	SeqListInsert(ps, ps->size, x);
}




//βɾ
//void SeqListPopBack(SeqList* ps)
//{
//	assert(ps);
//	//ps->a[ps->size - 1] = 0; // 
//	ps->size--;
//}
//βɾ���Ե���SeqListErase��ʵ��
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}

//ͷ��
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





//ͷɾ
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




//����λ�õĲ���
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

//������λ��ɾ����ֱ���ҵ��Ǹ�λ�ã�Ȼ���ú����������ǰ���ǣ�
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
//˳���
//1.�ɶ�̬����������
//2.�����������д洢�Ǳ�����������

//ȱ��
//1.�м����ͷ���Ĳ���ɾ����������ҪŲ�����ݡ�ʱ�临�Ӷ���O(N)
//2.�ռ䲻��ʱ�����ݻ���һ�����ĺͿռ��˷ѣ���Ϊ��ÿ��capacity��ֱ�ӱ�Ϊԭ����2����

//�ŵ�
//1.�������
//2.���������ʱȽϸ�(ÿ�μ���һ�����ݣ�����һ��һ���ļ���)Ԥ������һ��������