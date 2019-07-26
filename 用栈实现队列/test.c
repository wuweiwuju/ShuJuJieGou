#define _CRT_SECURE_NO_WARNINGS 1

//支持动态增长的栈
typedef char STDataType;

typedef struct Stack
{
	STDataType* _a;//动态实现
	int _top;//有效的数据，栈顶
	int _capacity;//容量的大小
}Stack;

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 5 : ps->_capacity * 2;
		STDataType* newstack = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		if (NULL == newstack)
		{
			printf("realloc error!");
			exit(0);
		}
		ps->_capacity = newcapacity;
		ps->_a = newstack;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top);
	return ps->_a[ps->_top - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_a != NULL)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
}


typedef struct {
	Stack _in;
	Stack _out;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&queue->_in);
	StackInit(&queue->_out);
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->_in, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (!StackEmpty(&obj->_out))
	{
		while (StackEmpty(&obj->_in) != 0)
		{
			StackPush(&obj->_out, StackTop(&obj->_in));
			StackPop(&obj->_in);
		}
	}
	int top = StackTop(&obj->_out);
	StackPop(&obj->_out);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(&obj->_out))
	{
		while (StackEmpty(&obj->_in) != 0)
		{
			StackPush(&obj->_out, StackTop(&obj->_in));
			StackPop(&obj->_in);
		}
	}
	return StackTop(&obj->_out);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->_in) + StackEmpty(&obj->_out) == 0 ? true : false;
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->_in);
	StackDestroy(&obj->_out);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/