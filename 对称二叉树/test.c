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
bool _isSymmetric(Node* r1, Node* r2)
{
	if (r1 == NULL && r2 == NULL)
		return true;
	if (r1 == NULL || r2 == NULL)
		return false;
	return r1->val == r2->val && _isSymmetric(r1->left, r2->right) &&
		_isSymmetric(r1->right, r2->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}

