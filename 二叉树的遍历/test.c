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

Node* CreateNode()//创建新节点，返回结点指针
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

void InOrder(Node* T)//中序遍历
{
	if (T == NULL)
		return NULL;
	InOrder(T->lchild);
	printf("%c ", T->c);
	InOrder(T->rchild);
}

void Del(Node* T)//删除树
{
	if (T->lchild != NULL)//删除左子树
	{
		Del(T->lchild);
		T->lchild = NULL;
	}
	if (T->rchild != NULL)//删除右子树
	{
		Del(T->rchild);
		T->rchild = NULL;
	}
	free(T);//删除根节点
}

unsigned pos;//标记字符串处理到哪了
BTNodeType str[N];//读取的字符串

Node* BuildTree()//根据字符串创立二叉树，并返回根节点指针
{
	if (pos >= strlen(str)) return NULL;//字符串处理完了就歇着吧
	if (str[pos] == '#')//创建空树，即返回空指针
	{
		pos++;//准备处理下一个字符
		return NULL;
	}
	Node* p = CreateNode();//创建一个空节点
	p->c = str[pos++];//先序，先获取根节点的字符信息
	p->lchild = BuildTree();//创建左子树
	p->rchild = BuildTree();//创建右子树
	return p;//完事，返回根节点指针
}

int main()
{
	while (gets(str))
	{
		pos = 0;//标记字符串处理到哪了
		Node* T = BuildTree();//根据字符串构建整棵树
		InOrder(T);//中序遍历并输出
		printf("\n");
		Del(T);//贴心的删除树，释放内存空间
	}
}