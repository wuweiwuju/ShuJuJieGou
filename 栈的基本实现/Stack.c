#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (NULL == ps->arr)
	{
		assert(0);
		return;
	}
	ps->capacity = 4;
	ps->top = 0;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->top = 0;
		ps->capacity = 0;
	}
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		size_t Newcapacity = (ps->capacity)=0 ? 4: (ps->capacity)* 2;
		STDataType* tmp = (STDataType*)realloc(ps->arr,Newcapacity);
		if (NULL == tmp)
		{
			return NULL;
		}
		ps->arr = tmp;
		ps->capacity = Newcapacity;
	}
	ps->arr[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (0 == ps->top)
		return NULL;
	ps->top--;
}
STDataType StackTop(Stack* ps) 
{
	assert(ps);
	return ps->arr[ps->top - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->top;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
void TestStack(Stack* ps)
{
	int i = 0;
	for (i = ps->top - 1; i >= 0; i--)
	{
		printf("%4d", ps->arr[i]);
	}
	printf("\n");
}