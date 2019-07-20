#include"SList.h"


void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
//构造结点
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pNewNode == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	pNewNode->_data = x;
	pNewNode->_next = NULL;
	return pNewNode;
}
//头插
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* pNewNode = NULL;
	pNewNode = BuySListNode(x);
	pNewNode->_next = plist->_head;
	plist->_head = pNewNode;
}
//头删
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return NULL;
	}
	SListNode* pHead = plist->_head->_next;
	free(plist->_head);
	plist->_head = NULL;
	plist->_head = pHead;
}
//尾插
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = NULL;
	SListNode* head = plist->_head;
	cur = BuySListNode(x);
	if (plist->_head == NULL)
	{
		plist->_head = cur;
	}
	else
	{
		while (head->_next)
		{
			head = head->_next;
		}
		head->_next = cur;
	}

}
//尾删
void SListPopBack(SList* plist)
{
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL)
	{
		free(plist->_head);
		return NULL;
	}
	SListNode* cur = plist->_head;
	SListNode* prev = plist->_head->_next;
	while (prev->_next)
	{
		cur = cur->_next;
		prev = prev->_next;
	}
	free(prev);
	prev = NULL;
	cur->_next = NULL;
}
//查找
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return cur;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* pNew = BuySListNode(x);
	pNew->_next = pos->_next;
	pos->_next = pNew;
}
// 删除pos位置的结点
void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->_next);
	SListNode* cur = NULL;
	cur = pos->_next->_next;
	free(pos->_next);
	pos->_next = cur;
}
//移除
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* pNew = NULL;
	SListNode* prev = cur;
	while (cur)
	{
		if (cur->_data != x)
		{
			pNew = cur;
			cur = cur->_next;
		}
		else
		{
			if (cur == prev)
			{
				prev = prev->_next;
				free(cur);
				plist->_head = prev;
				cur = prev;
			}
			else
			{
				pNew->_next = cur->_next;
				free(cur);
				cur = pNew->_next;
			}
		}
	}
}
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d--->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
void TestSList()
{
	SList plist;
	SListInit(&plist);
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 5);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 5);
	SListInsertAfter(SListFind(&plist,8),7);
	SListEraseAfter(SListFind(&plist, 8));
	SListRemove(&plist, 5);
	SListPrint(&plist);
	SListDestory(&plist);
	SListPrint(&plist);
}
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		plist->_head = cur->_next;
		free(cur);
		cur = NULL;
		cur = plist->_head;
	}
}


















