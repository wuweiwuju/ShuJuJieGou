#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>
#include<malloc.h>
//˳���ľ�̬�洢
//#define N 100
typedef int SLDataType;
//
//typedef struct Seqlist
//{
//	SLDataType array[N];//��������
//	size_t size;  //��Ч���ݵĸ���
//}Seqlist;
//˳���Ķ�̬�洢


typedef struct Seqlist
{
	SLDataType* array;//ָ��̬���ٵ�����
	size_t size;//��Ч���ݵĸ���
	size_t capicity;//�����ռ�Ĵ�С
}Seqlist;

void SeqlistInit(Seqlist* psl);
void SeqlistDestory(Seqlist* psl);
void CheckCapicity(Seqlist* psl);
void SeqlistPushBack(Seqlist* psl, SLDataType x);
void SeqlistPopBack(Seqlist* psl);
void SeqlistPushFront(Seqlist* psl, SLDataType x);
void SeqlistPopFront(Seqlist* psl);
int SeqlistFind(Seqlist* psl, SLDataType x);
void SeqlistInsert(Seqlist* psl, size_t pos, SLDataType x);
void SeqlistErase(Seqlist* psl, size_t pos);
void SeqlistRemove(Seqlist* psl, SLDataType x);
void SeqlistModify(Seqlist* psl, size_t pos, SLDataType x);
void Seqlistprint(Seqlist* psl);
void SeqlistBubbleSort(Seqlist* psl);
int SeqlistBinaryFind(Seqlist* psl, SLDataType x);
void SeqlistRemoveAll(Seqlist* psl, SLDataType x);