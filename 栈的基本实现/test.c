#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	TestStack(&ps);
	int ret = StackSize(&ps);
	printf("%4d\n", ret);
	int num = StackTop(&ps);
	printf("%4d\n", num);
	int count = StackEmpty(&ps);
	printf("%4d\n", count);
	StackDestroy(&ps);
	TestStack(&ps);
	system("pause");
	return 0;
}