#define _CRT_SECURE_NO_WARNINGS 1
///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};*/
//class PalindromeList {
//public:
//	bool chkPalindrome(ListNode* A) {
//		// write code here
//		if (A == NULL && A->next == NULL)
//			return true;
//		ListNode* fast = A;
//		ListNode* slow = A;
//		//���м���
//		while (fast)
//		{
//			slow = slow->next;
//			fast = slow->next;
//		}
//		ListNode* cur = slow->next;
//		ListNode* head = slow;
//		//��ת����ڵ�
//		while (cur)
//		{
//			ListNode* prev = cur->next;
//			cur->next = head;
//			head->next = NULL;
//			head = cur;
//			cur = prev;
//		}
//		//�Ƚ�
//		while (head)
//		{
//			if (head->val != A->val)
//			{
//				return false;
//			}
//			head = head->next;
//			A = A->next;
//
//		}
//		return true;
//	}
//};