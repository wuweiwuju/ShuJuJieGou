#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

//单向 不带头 不循环

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
//删除pos位置的结点
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);
void TestSList();