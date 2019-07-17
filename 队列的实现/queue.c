#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
void QueueInit(Queue* pq)//��ʼ��
{
	assert(pq);
	pq->front = pq->rear = NULL;
}
void QueueDestory(Queue* pq) //����
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
QueueNode* BuyQueueNode(QUDataType x) //������
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
void QueuePush(Queue* pq, QUDataType x) //β�壨��ӣ�
{
	assert(pq);
	QueueNode* pNewNode = BuyQueueNode(x);
	if (pq->rear == NULL)//�ն���
	{
		pq->front = pq->rear = pNewNode;
	}
	else
	{
		pq->rear->next = pNewNode;
		pq->rear = pNewNode;
	}
}
void QueuePop(Queue* pq)//ͷɾ�����ӣ�
{
	assert(pq);
	if (NULL == pq->front)//û�н��
	{
		return NULL;
	}
	else if (pq->front == pq->rear)//һ�����
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	else//������
	{
		QueueNode* sql = pq->front->next;
		free(pq->front);
		pq->front = NULL;
		pq->front = sql;
	}
}
QUDataType QueueFront(Queue* pq)//��ȡ��ͷԪ��
{
	assert(pq);
	return pq->front->data;
}
QUDataType QueueBack(Queue* pq)//��ȡ��βԪ��
{
	assert(pq);
	return pq->rear->data;
}
int QueueEmpty(Queue* pq) //���
{
	assert(pq);
	return NULL == pq->front;
}
int QueueSize(Queue* pq) //��Ч���ݵĸ���
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
void TestQueue(Queue* pq) //����
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