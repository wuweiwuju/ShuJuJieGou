#include"Heap.h"
void AdjustDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;

	}
}
void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 2) / 2;
	while(child > 0)
	{
		if (a[child] > a[parent])
			return;
		else
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 2) / 2;
		}
	}


}
void HeapInit(Heap* hp, HPDataType* array, int n)
{
	assert(hp && array);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, array, sizeof(HPDataType) * n);
	hp->size = n;
	hp->capacity = n;

	//构建小堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->size, i);
	}
}
void HeapPush(Heap* hp, HPDataType x)//尾插要考虑增容
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 10 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)malloc(newcapacity * sizeof(HPDataType));//一定要有接收返回值，因为不一定原地增容
		assert(tmp);
		hp->_a = tmp;
		hp->capacity = newcapacity;
		free(tmp);
	}
	hp->_a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->_a, hp->size - 1);
}
void HeapPop(Heap* hp)//删除堆顶元素
{
	assert(hp);
	if (hp->_a == NULL)
		return;
	Swap(&hp->_a[0], &hp->_a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->_a, hp->size , 0);
}
// 堆排序
void HeapSort(int* a, int n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	while (n > 0)
	{
		Swap(&a[0], &a[n - 1]);
		AdjustDown(a, n-1, 0);
		n--;
	}
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size = 0 ? 0 : 1;
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->capacity = hp->size = 0;
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	int array[] = { 1,2,5,8,9,4,6,0,15,38 };
	Heap hp;
	HeapInit(&hp,array,sizeof(array)/sizeof(int));
	//HeapPush(&hp, 3);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d\n",HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapEmpty(&hp));
	HeapSort(array, sizeof(array) / sizeof(int));
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	HeapDestory(&hp);

}
