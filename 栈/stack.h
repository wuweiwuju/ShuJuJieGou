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
	STDataType* _a;//��̬ʵ��
	int _top;//��Ч�����ݣ�ջ��
	int _capacity;//�����Ĵ�С
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack* ps, STDataType x);//ѹջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
bool isValid(char* s);
