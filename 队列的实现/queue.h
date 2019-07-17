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

void QueueInit(Queue* pq); //��ʼ��
void QueueDestory(Queue* pq); //����
QueueNode* BuyQueueNode(QUDataType x); //������
void QueuePush(Queue* pq, QUDataType x); //β�壨��ӣ�
void QueuePop(Queue* pq);//ͷɾ�����ӣ�
QUDataType QueueFront(Queue* pq);//��ȡ��ͷԪ��
QUDataType QueueBack(Queue* pq);//��ȡ��βԪ��
int QueueEmpty(Queue* pq); //���
int QueueSize(Queue* pq); //��Ч���ݵĸ���
void TestQueue(Queue* pq); //����