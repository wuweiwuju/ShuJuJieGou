#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;
int GetSize(Node* root)
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;
}
void _preorderTraversal(Node* root, int* a, int* pi)
{
	if (root == NULL)
		return;
	a[*pi] = root->val;
	(*pi)++;

	_preorderTraversal(root->left, a, pi);
	_preorderTraversal(root->right, a, pi);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetSize(root);//先知道这个树有多大才能开辟数组
	int* a = (int*)malloc(*returnSize * sizeof(int));//开辟空间
	int i = 0;
	_preorderTraversal(root, a, &i);
	return a;
}

