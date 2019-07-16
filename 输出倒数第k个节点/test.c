#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		ListNode* fast = pListHead;
//		ListNode* slow = pListHead;
//		ListNode* ctl = pListHead;
//		int count = 0;
//		if (pListHead == NULL)
//			return NULL;
//		while (ctl != NULL)
//		{
//			ctl = ctl->next;
//			count++;
//		}
//		if (count < k)
//			return NULL;
//		while (k--)
//		{
//			fast = fast->next;
//		}
//		while (fast != NULL)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//};
