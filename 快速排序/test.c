#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (StackEmpty(&st) != 0) {
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
			int div = PartSort1(a, begin, end);
		if (begin < div - 1) {
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}
		if (div + 1 < end) {
			StackPush(&st, div + 1);
			StackPush(&st, end);
		}
	}
}