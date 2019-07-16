#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//typedef struct ListNode Node;
//Node* Cycle(struct ListNode* head) {
//	Node* slow = head;
//	Node* fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//			return slow;
//	}
//	return NULL;
//
//}
//struct ListNode* detectCycle(struct ListNode* head) {
//	Node* meet = Cycle(head);
//	if (meet == NULL)
//	{
//		return NULL;
//	}
//	while (meet != head)
//	{
//		meet = meet->next;
//		head = head->next;
//	}
//	return meet;
//
//}
