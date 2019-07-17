#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
void QueueInit(Queue* pq)//初始化
{
	assert(pq);
	pq->front = pq->rear = NULL;
}
void QueueDestory(Queue* pq) //销毁
{
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur)
	{
		pq->front = cur->next;
		free(cur);
		cur = pq->front;
	}
}
QueueNode* BuyQueueNode(QUDataType x) //构造结点
{
	QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewNode == NULL)
	{
		return NULL;
	}
	pNewNode->data = x;
	pNewNode->next = NULL;
	return pNewNode;
}
void QueuePush(Queue* pq, QUDataType x) //尾插（入队）
{
	assert(pq);
	QueueNode* pNewNode = BuyQueueNode(x);
	if (pq->rear == NULL)//空队列
	{
		pq->front = pq->rear = pNewNode;
	}
	else
	{
		pq->rear->next = pNewNode;
		pq->rear = pNewNode;
	}
}
void QueuePop(Queue* pq)//头删（出队）
{
	assert(pq);
	if (NULL == pq->front)//没有结点
	{
		return NULL;
	}
	else if (pq->front == pq->rear)//一个结点
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	else//多个结点
	{
		QueueNode* sql = pq->front->next;
		free(pq->front);
		pq->front = NULL;
		pq->front = sql;
	}
}
QUDataType QueueFront(Queue* pq)//获取队头元素
{
	assert(pq);
	return pq->front->data;
}
QUDataType QueueBack(Queue* pq)//获取队尾元素
{
	assert(pq);
	return pq->rear->data;
}
int QueueEmpty(Queue* pq) //清空
{
	assert(pq);
	return NULL == pq->front;
}
int QueueSize(Queue* pq) //有效数据的个数
{
	assert(pq);
	QueueNode* cur = pq->front;
	int count = 0;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}
void TestQueue(Queue* pq) //测试
{
	assert(pq);
	QueueNode* cur = NULL;
	cur = pq->front;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}