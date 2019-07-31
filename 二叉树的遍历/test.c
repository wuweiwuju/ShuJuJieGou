#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define N 101

typedef char BTNodeType;
typedef struct Node 
{
	struct Node* lchild;
	struct Node* rchild;
	BTNodeType c;
}Node;

Node* CreateNode()//�����½ڵ㣬���ؽ��ָ��
{
	Node* ret = (Node*)malloc(sizeof(Node));
	if (ret == NULL)
	{
		printf("malloc error");
		exit(0);
	}
	ret->lchild = NULL;
	ret->rchild = NULL;
	return ret;
}

void InOrder(Node* T)//�������
{
	if (T == NULL)
		return NULL;
	InOrder(T->lchild);
	printf("%c ", T->c);
	InOrder(T->rchild);
}

void Del(Node* T)//ɾ����
{
	if (T->lchild != NULL)//ɾ��������
	{
		Del(T->lchild);
		T->lchild = NULL;
	}
	if (T->rchild != NULL)//ɾ��������
	{
		Del(T->rchild);
		T->rchild = NULL;
	}
	free(T);//ɾ�����ڵ�
}

unsigned pos;//����ַ�����������
BTNodeType str[N];//��ȡ���ַ���

Node* BuildTree()//�����ַ��������������������ظ��ڵ�ָ��
{
	if (pos >= strlen(str)) return NULL;//�ַ����������˾�Ъ�Ű�
	if (str[pos] == '#')//���������������ؿ�ָ��
	{
		pos++;//׼��������һ���ַ�
		return NULL;
	}
	Node* p = CreateNode();//����һ���սڵ�
	p->c = str[pos++];//�����Ȼ�ȡ���ڵ���ַ���Ϣ
	p->lchild = BuildTree();//����������
	p->rchild = BuildTree();//����������
	return p;//���£����ظ��ڵ�ָ��
}

int main()
{
	while (gets(str))
	{
		pos = 0;//����ַ�����������
		Node* T = BuildTree();//�����ַ�������������
		InOrder(T);//������������
		printf("\n");
		Del(T);//���ĵ�ɾ�������ͷ��ڴ�ռ�
	}
}