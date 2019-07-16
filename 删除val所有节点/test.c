#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//typedef struct ListNode Node;
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//
//	Node* cur = head;
//	Node* prev = NULL;
//	Node* next = NULL;
//	while (cur)
//	{
//		if (cur->val != val)
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//		else if (cur->val == val)
//		{
//			if (prev == NULL)
//			{
//				next = cur->next;
//				head = next;
//				free(cur);
//				cur = NULL;
//				cur = next;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = NULL;
//				cur = prev->next;
//			}
//		}
//	}
//	return head;
//};
