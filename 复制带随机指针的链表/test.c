#define _CRT_SECURE_NO_WARNINGS 1
//LeetCode
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/
//Node* BuyNode(int val)
//{
//	Node* newnode = (Node*)malloc(sizeof(Node));
//	if (newnode == NULL)
//	{
//		return NULL;
//	}
//	newnode->val = val;
//	newnode->next = NULL;
//	newnode->random = NULL;
//	return newnode;
//}
//class Solution {
//public:
//	Node* copyRandomList(Node* head) {
//		//��������
//		Node* cur = head;
//		while (cur)
//		{
//			//��¼cur����һ�����
//			Node* next = cur->next;
//			//������ͬ���
//			Node* cpnode = BuyNode(cur->val);
//			//�����½��
//			cur->next = cpnode;
//			cpnode->next = next;
//			//����������
//			cur = next;
//		}
//
//		//��random
//		cur = head;
//		while (cur)
//		{
//			Node* next = cur->next->next;
//			Node* cpnode = cur->next;
//
//			if (cur->random != NULL)
//				cpnode->random = cur->random->next;
//
//			if (cur->random == NULL)
//				cpnode->random = NULL;
//
//			cur = next;
//		}
//
//		//���-����
//		Node* pHead = BuyNode(0);
//		Node* tail = pHead;
//		cur = head;
//		while (cur)
//		{
//			Node* cpnode = cur->next;
//			cur->next = cpnode->next;
//			cur = cpnode->next;
//			cpnode->next = NULL;
//
//			tail->next = cpnode;
//			tail = cpnode;
//
//		}
//		Node* phead = pHead->next;
//		free(pHead);
//		return phead;
//	}
//};