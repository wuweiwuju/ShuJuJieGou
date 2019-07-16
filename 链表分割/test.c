#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x) {
//		// write code here
//		ListNode* lesshead = NULL;
//		ListNode* lesstail = NULL;
//		ListNode* greathead = NULL;
//		ListNode* greattail = NULL;
//		lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
//		greathead = greattail = (ListNode*)malloc(sizeof(ListNode));
//		ListNode* cur = pHead;
//		while (cur)
//		{
//			if (cur->val < x)
//			{
//				lesstail->next = cur;
//				lesstail = cur;
//			}
//			else
//			{
//				greattail->next = cur;
//				greattail = cur;
//			}
//			cur = cur->next;
//		}
//		greattail->next = NULL;
//		lesstail->next = greathead->next;
//		ListNode* list = lesshead->next;
//		free(lesshead);
//		free(greathead);
//		return list;
//
//	}
//
//};
