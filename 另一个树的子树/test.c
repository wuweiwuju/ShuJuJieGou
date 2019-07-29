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
bool isSameTree(Node* t1, Node* t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	if (t1->val != t2->val)
		return false;
	return isSameTree(t1->left, t2->left) &&
		isSameTree(t1->right, t2->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;

	//遍历整棵树中的每个子树
	if (s->val == t->val)
	{
		if (isSameTree(s, t) == true)
			return true;
	}

	if (isSubtree(s->left, t) == true)
		return true;
	if (isSubtree(s->right, t) == true)
		return true;

	return false;
}

