#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc error");
		exit(0);
	}
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		pq->_front = pq->_rear = BuyQueueNode(x);
	}
	else
	{
		pq->_rear->_next = BuyQueueNode(x);
		pq->_rear = pq->_rear->_next;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq && pq->_front);
	QueueNode* next = pq->_front->_next;
	if (pq->_front == pq->_rear)
	{
		pq->_rear = next;
	}
	free(pq->_front);
	pq->_front = next;

}
QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_front);
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 0 : 1;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	size_t count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 5);
	QueuePush(&q, 8);
	QueuePop(&q);
	printf("%d\n", QueueEmpty(&q));
	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	while (q._front)
	{
		printf("%d-->", q._front->_data);
		q._front = q._front->_next;
	}
	printf("NULL\n");
	QueueDestory(&q);
}