#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"
ListNode* BuyDListNode(LTDataType x)
{
	ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
	if (pNewNode == NULL)
	{
		printf("malloc perror");
		exit(0);
	}
	pNewNode->_data = x;
	pNewNode->_next = NULL;
	pNewNode->_prev = NULL;
	return pNewNode;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		printf("malloc perror");
		exit(0);
	}
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
}
void ListDestroy(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head;
	ListNode* head = plist->_head;
	ListNode* next = cur->_next;
	while (cur != head)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}
//尾插
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	//ListNode* newnode = BuyDListNode(x);
	//ListNode* head = plist->_head;
	//head->_prev->_next = newnode;
	//newnode->_prev = head->_prev;
	//head->_prev = newnode;
	//newnode->_next = head;
	ListInsert(plist->_head, x);
}
void ListPushFront(List* plist, LTDataType x)//头插
{
	assert(plist);
	//ListNode* newnode = BuyDListNode(x);
	//ListNode* head = plist->_head;
	////这个只有一个头结点的话，下面也包含了。
	///*if (head->_next == NULL)
	//{
	//	head->_next = newnode;
	//	newnode->_prev = head;
	//	head->_prev = newnode;
	//	newnode->_next = head;
	//}*/
	//newnode->_next = head->_next;
	//head->_next = newnode;
	//newnode->_prev = newnode->_next->_prev;
	//newnode->_next->_prev = newnode;
	ListInsert(plist->_head->_next, x);
}
//头删
void ListPopFront(List* plist)
{
	assert(plist);
	/*ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	if (head->_next == NULL)
	{
		return NULL;
	}
	if (cur->_next == NULL)
	{
		head->_next = head;
		head->_prev = head;
		free(cur);
		return;
	}
	head->_next = cur->_next;
	cur->_next->_prev = head;
	free(cur);
	cur = NULL;*/
	ListErase(plist->_head->_next);
}
//尾删
void ListPopBack(List* plist)
{
	assert(plist);
	//ListNode* head = plist->_head;
	//ListNode* tail = head->_prev;
	//if (head->_next == NULL)
	//{
	//	return NULL;
	//}
	//tail->_prev->_next = head;
	//head->_prev = tail->_prev;
	//free(tail);
	ListErase(plist->_head->_prev);
}
//查找
ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	if (head->_next == NULL)
	{
		return head;
	}
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return head;

}
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyDListNode(x);
	newnode->_prev = pos->_prev;
	pos->_prev->_next = newnode;
	pos->_prev = newnode;
	newnode->_next = pos;

}
// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
//消除x
void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* prev = plist->_head;
	if (cur == NULL)
	{
		return NULL;
	}
	while (cur != head)
	{
		if (cur->_data == x)
		{
			prev = cur->_next;
			//cur->_prev->_next = cur->_next;
			//cur->_next->_prev = cur->_prev;
			//free(cur);
			ListErase(cur);
			cur = prev;
		}
		else
		{
			cur = cur->_next;
		}
	}
}
void ListPrint(List* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		printf("NULL\n");
		return;
	}
	ListNode* cur = plist->_head->_next;
	ListNode* head = plist->_head;
	while(cur != head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
