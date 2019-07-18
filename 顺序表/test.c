#include"Seqlist.h"
void menu()
{
	printf("****************************************************\n");
	printf("*****1. β��       *********2.   βɾ        *******\n");
	printf("*****3. ͷ��       *********4.   ͷɾ        *******\n");
	printf("*****5. ����       *********6.   ����        *******\n");
	printf("*****7. ɾ��       *********8.   �Ƴ�        *******\n");
	printf("*****9. �滻       *********10.  �ͷ�        *******\n");
	printf("*****11.ð������   *********12.  ���ֲ���    *******\n");
	printf("*****13.�Ƴ���ͬ   ********* 0.   exit       *******\n");
	printf("****************************************************\n");

}
void test()
{
	int input = 0;
	size_t ret = 0;
	size_t pos = 0;
	SLDataType x = 0;
	Seqlist psl;
	SeqlistInit(&psl);
	Seqlistprint(&psl);
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			{
				printf("��ѡ��Ҫ�������:> ");
				scanf_s("%d", &x);
				SeqlistPushBack(&psl, x);
				Seqlistprint(&psl);
				break;
			}
		case 2:
			{
				SeqlistPopBack(&psl);
				Seqlistprint(&psl);
				break;
			}
		case 3:
			{
				printf("��ѡ��Ҫ�������:> ");
				scanf_s("%d", &x);
				SeqlistPushFront(&psl, x);
				Seqlistprint(&psl);
				break;
			}
		case 4:
			{
				SeqlistPopFront(&psl);
				Seqlistprint(&psl);
				break;
			}
		case 5:
			{
				printf("������Ҫ���ҵ���:>");
				scanf_s("%d", &x);
				ret = SeqlistFind(&psl,x);
				printf("%d\n", ret);
				break;
			}
		case 6:
			{
				printf("����������λ�úͲ������:>");
				scanf_s("%d %d", &pos, &x);
				SeqlistInsert(&psl, pos, x);
				Seqlistprint(&psl);
				break;
			}
		case 7:
			{
				printf("������ɾ����λ��:>");
				scanf_s("%d", &pos);
				SeqlistErase(&psl, pos);
				Seqlistprint(&psl);
				break;
			}
		case 8:
			{
				printf("������Ҫ�Ƴ�����:>");
				scanf_s("%d", &x);
				SeqlistRemove(&psl, x);
				Seqlistprint(&psl);
				break;
			}
		case 9:
			{
				printf("��������ĵ�λ�ú͸��ĵ���:>");
				scanf_s("%d %d", &pos, &x);
				SeqlistModify(&psl, pos, x);
				Seqlistprint(&psl);
				break;
			}
		case 10:
			{
				SeqlistDestory(&psl);
				Seqlistprint(&psl);
				break;
			}
		case 11:
		{
			Seqlistprint(&psl);
			SeqlistBubbleSort(&psl);
			Seqlistprint(&psl);
			break;
		}
		case 12:
		{
			printf("������Ҫ���ҵ���:>");
			scanf_s("%d", &x);
			ret = SeqlistBinaryFind(&psl,x);
			printf("%d\n", ret);
			break;
		}
		case 13:
		{
			printf("������Ҫ�Ƴ�����:>");
			scanf_s("%d", &x);
			SeqlistRemoveAll(&psl, x);
			Seqlistprint(&psl);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			printf("ѡ������������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}