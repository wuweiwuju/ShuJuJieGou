#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//typedef struct ListNode ListNode;
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//	if (headA == NULL || headB == NULL)
//		return NULL;
//	ListNode* cur = headA;
//	ListNode* prev = headB;
//	int count = 0;
//	int num = 0;
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		count++;
//	}
//	while (prev != NULL)
//	{
//		prev = prev->next;
//		num++;
//	}
//	ListNode* longL = headA;
//	ListNode* shortL = headB;
//	if (num > count)
//	{
//		longL = headB;
//		shortL = headA;
//	}
//	int gap = abs(count - num);
//	while (gap--)
//	{
//		longL = longL->next;
//	}
//	while (longL != shortL)
//	{
//		longL = longL->next;
//		shortL = shortL->next;
//	}
//	return longL;
//
//}