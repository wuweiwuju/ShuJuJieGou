#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include <stdbool.h>

typedef char STDataType;

typedef struct Stack
{
	STDataType* _a;//动态实现
	int _top;//有效的数据，栈顶
	int _capacity;//容量的大小
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack* ps, STDataType x);//压栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
bool isValid(char* s);
