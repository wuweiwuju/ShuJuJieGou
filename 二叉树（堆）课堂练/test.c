#define _CRT_SECURE_NO_WARNINGS 1

// 树
//typedef TreeNode* SLDataType;
//struct TreeNode
//{
//	data;
//	SeqList _subs;
//	//vector<TreeNode*> _subs;
//};
//孩子兄弟表示法
//typedef int DataType;
//struct Node
//{
//	struct Node* _firstChild1;
//	struct Node* _pNextBrother;
//	DataType _data;
//};
//树的应用： 文件系统 目录树

//二叉树
//顺序存储
//堆
//堆可以用来排序
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(hp->_a, a, sizeof(HPDataType) * n);
	hp->_capacity = hp->_size = n;
	for (int i = (hp->_size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找左右孩子小的
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[parent] < a[child])
		{
			HPDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapDestory(Heap* hp)
{

}
void AdjustUp(HPDataType* a, int size, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	//while(parent >= 0)//最好不要用这个
	{
		if (a[child] > a[parent])
		{
			HPDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, hp->_capacity*sizeof(HPDataType));
		assert(hp->_a);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;

	//调堆
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);


}
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->_size == 0 ? 0 : 1;
}
int main()
{
	int a[] = { 1,2,5,8,9,4,6,0,15,38};
	Heap HP;
	HeapInit(&HP, a, sizeof(a)/sizeof(int));
	system("pause");
	return 0;
}

//堆是用来top k问题
