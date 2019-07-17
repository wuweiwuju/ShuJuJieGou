#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;//ָ��̬���ٵ�����
	int top;//���ջ�����൱��˳����е�size
	int capacity;//����
}Stack;

void StackInit(Stack* ps);//��ʼ��
void StackDestroy(Stack* ps);//����
void StackPush(Stack* ps, STDataType x);//ѹջ
void StackPop(Stack* ps);//��ջ
STDataType StackTop(Stack* ps);//��ȡջ��Ԫ��
int StackEmpty(Stack* ps);//���
int StackSize(Stack* ps);//��ȡջ����ЧԪ�ظ���
void TestStack(Stack* ps);//����