#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"
int main()
{
	List  plist ;
	ListInit(&plist);
	ListPushFront(&plist, 5);
	ListPushFront(&plist, 6);
	ListPushBack(&plist, 3);
	ListPushBack(&plist, 3);
	ListPushBack(&plist, 7);
	ListPushBack(&plist, 3);
	ListInsert(ListFind(&plist, 7), 8);
	ListErase(ListFind(&plist, 6));
	ListRemove(&plist, 3);
	//ListPopFront(&plist);
	//ListPopBack(&plist);
	ListPrint(&plist);
	/*ListDestroy(&plist);
	ListPrint(&plist);*/
	system("pause");
	return 0;
}