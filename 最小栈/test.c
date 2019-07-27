#define _CRT_SECURE_NO_WARNINGS 1
typedef int STDataType;

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
	assert(ps);
	if (ps->_top == 0)
	{
		return 0;
	}
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
	Stack q1;
	Stack q2;

} MinStack;

/** initialize your data structure here. */


/*void minStackPush(MinStack* obj, int x) {
  StackPush(&obj->q1,x);
	if(StackEmpty(&obj->q2) == 0)
	{
		 StackPush(&obj->q2,x);
	}
	else
	{
		if(StackTop(&obj->q2) >= x)
		{
			 StackPush(&obj->q2,x);
		}
	}
}*/

void minStackPush(MinStack* obj, int x) {
	StackPush(&obj->q1, x);
	if (!StackEmpty(&obj->q2))
	{
		StackPush(&obj->q2, x);
	}
	else
	{
		if (x <= StackTop(&obj->q2))
		{
			StackPush(&obj->q2, x);
		}
	}
}

MinStack* minStackCreate() {
	MinStack* st = (MinStack*)malloc(sizeof(MinStack));
	StackInit(&st->q1);
	StackInit(&st->q2);
	return st;
}



void minStackPop(MinStack* obj) {

	if (StackTop(&obj->q1) == StackTop(&obj->q2))
	{
		StackPop(&obj->q1);
		StackPop(&obj->q2);
	}
	else
	{
		StackPop(&obj->q1);
	}

}

int minStackTop(MinStack* obj) {
	return StackTop(&obj->q1);
}

int minStackGetMin(MinStack* obj) {
	return StackTop(&obj->q2);
}

void minStackFree(MinStack* obj) {
	StackDestroy(&obj->q1);
	StackDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/