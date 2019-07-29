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
void _postorderTraversal(Node* root, int* a, int* pi)
{
	if (root == NULL)
		return;

	_postorderTraversal(root->left, a, pi);

	_postorderTraversal(root->right, a, pi);

	a[*pi] = root->val;
	(*pi)++;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetSize(root);//��֪��������ж����ܿ�������
	int* a = (int*)malloc(*returnSize * sizeof(int));//���ٿռ�
	int i = 0;
	_postorderTraversal(root, a, &i);
	return a;
}

