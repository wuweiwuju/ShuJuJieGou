#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void ListInit(List* plt)//��ʼ��
{
	assert(plt);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head = plt->_head;
	head->_next = head;
	head->_prev = head;
}
void BuyListNode(List* plt)//���Ĵ���
{
	assert(plt);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_next = plt->_head;
	plt->_head->_prev  = newnode;
}
void ListDestroy(List* plt)//����
{

}
void ListPushBack(List* plt, LTDataType x)//β��
{

}
void ListPopBack(List* plt)//βɾ
{

}
void ListPushFront(List* plt, LTDataType x)//ͷ��
{

}
void ListPopFront(List* plt)//ͷɾ
{

}
void ListFind(List* plt, LTDataType x)//����
{

}
void ListInsert(ListNode* pos, LTDataType x)//ָ������
{

}
void ListErase(ListNode* pos)//ָ��ɾ��pos���
{

}
void ListRemove(List* plt, LTDataType x)//ɾ��x���
{
	
}
void Print(List* plt)//��ӡ
{

}
