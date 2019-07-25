#include"stack.h"
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
		int newcapacity  = ps->_capacity == 0 ? 5 : ps->_capacity * 2;
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
		return;
	}
	return ps->_a[ps->_top-1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	while (ps->_top != 0)
	{
		StackPop(&ps);
	}
}
void StackPrint(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	while (ps->_top != 0)
	{
		printf("%d--->", ps->_a[ps->_top-1]);
		ps->_top--;
	}
	printf("NULL\n");
}