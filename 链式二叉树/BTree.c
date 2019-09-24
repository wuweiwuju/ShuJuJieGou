#include"BTree.h"
BTNode* BuyTreeNode(BTDataType data)
{
	BTNode* pNode = (BTNode*)malloc(sizeof(BTNode));
	if (pNode == NULL)
		assert(0);
	pNode->_left = NULL;
	pNode->_right = NULL;
	pNode->_data = data;
	return pNode;
}
BTNode* _BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	BTNode* pNode = NULL;

	if ((*pi) < n && a[*pi] != '#')
	{
		pNode = BuyTreeNode(a[*pi]);
		(*pi)++;

		pNode->_left = _BinaryTreeCreate(a, n, pi);

		(*pi)++;
		pNode->_right = _BinaryTreeCreate(a, n, pi);
	}
	return pNode;
}
//提供给外部用户
BTNode* BinaryTreeCreate(BTDataType* a, int n)
{
	assert(a);
	int pi = 0;
	return _BinaryTreeCreate(a, n, &pi);
}
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL &&
		root->_right == NULL)
		return 1;

	return BinaryTreeSize(root->_left)
		+ BinaryTreeSize(root->_right)+1;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL &&
		root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k-1)
		+ BinaryTreeLevelKSize(root->_right, k-1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* lret = BinaryTreeFind(root->_left,x);
	if (lret != NULL)
		return lret;

	BTNode* rret = BinaryTreeFind(root->_right, x);
	if (rret != NULL)
		return rret;

	return NULL;

}
// 递归遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}
// 层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root != NULL)
//		QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//
//		printf("%d ", front->_data);
//		if (front->_left)
//		{
//			QueuePush(&q, front->_left);
//		}
//		if (front->_right)
//		{
//			QueuePush(&q, front->_right);
//		}
//	}
//  printf("\n");
//}
// 判断二叉树是否是完全二叉树
//int BinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root != NULL)
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front != NULL)
//		{
//			QueuePush(&q, front->_left);
//			QueuePush(&q, front->_right);
//		}
//		else
//		{
//			break;
//		}
//	}
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front != NULL)
//		{
//			QueueDestroy(&q);
//			return false;
//		}
//	}
//	return true;
//}
void TestBinaryTree()
{
	char* pStr = "ABD##E#H##CF##G##";
	BTNode* pRoot = BinaryTreeCreate(pStr, strlen(pStr));
	BinaryTreePrevOrder(pRoot);
	printf("\n");
	BinaryTreeInOrder(pRoot);
	printf("\n");
	BinaryTreePostOrder(pRoot);
	printf("\n");
	printf("%d\n", BinaryTreeSize(pRoot));
	printf("%d\n", BinaryTreeLeafSize(pRoot));
	printf("%d\n", BinaryTreeLevelKSize(pRoot, 4));
}