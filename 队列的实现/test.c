#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
int main()
{
	QueueNode pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	TestQueue(&pq);
	QUDataType ret = QueueFront(&pq);
	printf("%d\n", ret);
	QUDataType count = QueueBack(&pq);
	printf("%d\n", count);
	int l = QueueEmpty(&pq);
	printf("%d\n", l);
	int sum = QueueSize(&pq);
	printf("%d\n", sum);
	QueuePop(&pq);
	TestQueue(&pq);
	QueueDestory(&pq);
	TestQueue(&pq);

	system("pause");
	return 0;
}