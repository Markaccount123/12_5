#include"SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d", cur->date);
		//һ��Ҫ�μǣ����curһ������дcur++����Ϊ��ӵ�ֻ��һ��ָ��Ĵ�С����������ô�ұ�֤������һ����ַ�պ�Ϊһ��ָ��Ĵ�С����Сʱ��ȷ����
		cur = cur->nest;
	}
}
//β��
void SListPushBack(SListNode* phead, SLDateType x)
{
	SListNode* tail = phead;
	//while (tail->nest != NULL)//
	//{
	//	tail = tail->nest;//�����������д����ͻᷢ������������ʱ�����Ѿ�ָ��NULL�ˣ�Ȼ���㻹ȥ��������������ͻ����
	//}
	while (tail->nest != NULL)//
	{
		tail = tail->nest;//����Ҫ���벻ͨ���Կ��μ�������Ǹ�ͼ
	}
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newNode->date = x;
	newNode->nest = NULL;
	tail->nest = newNode;
}

//βɾ
//void SListPopBack(SListNode* phead)
//{
//
//}