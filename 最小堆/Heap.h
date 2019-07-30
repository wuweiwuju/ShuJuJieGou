#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int size;
	int capacity;
}Heap;
void HeapInit(Heap* hp, HPDataType* array,int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
// ∂—≈≈–Ú
void HeapSort(int* a, int n);
void TestHeap();
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int root);
void Swap(int* pa, int* pb);