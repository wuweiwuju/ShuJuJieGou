#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void ListInit(List* plt)//初始化
{
	assert(plt);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head = plt->_head;
	head->_next = head;
	head->_prev = head;
}
void BuyListNode(List* plt)//结点的创建
{
	assert(plt);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_next = plt->_head;
	plt->_head->_prev  = newnode;
}
void ListDestroy(List* plt)//销毁
{

}
void ListPushBack(List* plt, LTDataType x)//尾插
{

}
void ListPopBack(List* plt)//尾删
{

}
void ListPushFront(List* plt, LTDataType x)//头插
{

}
void ListPopFront(List* plt)//头删
{

}
void ListFind(List* plt, LTDataType x)//查找
{

}
void ListInsert(ListNode* pos, LTDataType x)//指定插入
{

}
void ListErase(ListNode* pos)//指定删除pos结点
{

}
void ListRemove(List* plt, LTDataType x)//删除x结点
{
	
}
void Print(List* plt)//打印
{

}
