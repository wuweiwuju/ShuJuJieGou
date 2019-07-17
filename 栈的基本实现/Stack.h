#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;//指向动态开辟的数组
	int top;//标记栈顶，相当于顺序表中的size
	int capacity;//容量
}Stack;

void StackInit(Stack* ps);//初始化
void StackDestroy(Stack* ps);//销毁
void StackPush(Stack* ps, STDataType x);//压栈
void StackPop(Stack* ps);//出栈
STDataType StackTop(Stack* ps);//获取栈顶元素
int StackEmpty(Stack* ps);//清空
int StackSize(Stack* ps);//获取栈内有效元素个数
void TestStack(Stack* ps);//测试