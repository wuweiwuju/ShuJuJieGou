#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#pragma once
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;
void ListInit(List* plt);
void ListDestroy(List* plt);
void BuyListNode(List* plt);
void ListPushBack(List* plt, LTDataType x);
void ListPopBack(List* plt);
void ListPushFront(List* plt, LTDataType x);
void ListPopFront(List* plt);
void ListFind(List* plt, LTDataType x);
void ListInsert(ListNode* pos,LTDataType x);
void ListErase(ListNode* pos);
void ListRemove(List* plt,LTDataType x);
void Print(List* plt);
