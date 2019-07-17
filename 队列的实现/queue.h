#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QUDataType data;
}QueueNode;
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

void QueueInit(Queue* pq); //初始化
void QueueDestory(Queue* pq); //销毁
QueueNode* BuyQueueNode(QUDataType x); //构造结点
void QueuePush(Queue* pq, QUDataType x); //尾插（入队）
void QueuePop(Queue* pq);//头删（出队）
QUDataType QueueFront(Queue* pq);//获取队头元素
QUDataType QueueBack(Queue* pq);//获取队尾元素
int QueueEmpty(Queue* pq); //清空
int QueueSize(Queue* pq); //有效数据的个数
void TestQueue(Queue* pq); //测试