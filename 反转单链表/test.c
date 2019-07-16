#define _CRT_SECURE_NO_WARNINGS 1
//LeetCode
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//µİ¹é
//typedef struct ListNode Node;
//
//struct ListNode* reverseList(struct ListNode* head) {
//	if (head == NULL || head->next == NULL)
//		return head;
//	Node* p = head;
//	head = reverseList(p->next);
//	p->next->next = p;
//	p->next = NULL;
//	return head;
//
//
//}
//µü´ú
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//typedef struct ListNode Node;
//
//struct ListNode* reverseList(struct ListNode* head) {
//	if (head == NULL || head->next == NULL)
//		return head;
//	Node* n1 = head;
//	Node* n2 = n1->next;
//	Node* n3 = n2->next;
//	head->next = NULL;
//	while (n2 != NULL)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3 != NULL)
//			n3 = n3->next;
//	}
//	head = n1;
//	return head;
//
//}


