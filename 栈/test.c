#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

int main()
{
	Stack ps;
	StackInit(&ps);
	char* s = "{[]}";
	StackPush(&ps, '{' );
	StackPush(&ps, '[');
	StackPush(&ps, ']');
	StackPush(&ps, '}');
	printf("%d\n",isValid(s));
	/*StackPush(&ps, 2);
	StackPush(&ps, 5);
	StackPush(&ps, 8);
	StackPush(&ps, 6);
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	printf("%d\n", StackSize(&ps));
	printf("%d\n", StackEmpty(&ps));
	StackPrint(&ps);
	StackDestroy(&ps);*/
	system("pause");
	return 0;
}