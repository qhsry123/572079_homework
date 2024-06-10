#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink, * rlink;
}DListNode;


void init(DListNode* phead) {
	phead->llink = phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;

}

void print_dlist(DListNode* head) {
	DListNode* p = head;
	for (p = head->rlink; p != head; p = p->rlink) {
		printf("%d->", p->data);
	}
	printf("(head)\n");
}

element ddelete(DListNode* head, DListNode* removed) {
	element r;
	if (removed == head)return;
	r = removed->data;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	return r;
}

main()
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	element deleted;

	while (1) {
		printf("\n������ ���� �޴��� �����ϴ� ���α׷��Դϴ�\n");
		printf("1. �����Է¹޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2. �����Է¹޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3. ����Ʈ ó�� ��� ����\n");
		printf("4. ����Ʈ ������ ��� ����\n");
		printf("5.����Ʈ ����Ʈ\n");
		printf("6.���α׷� ����\n");

		int choice;
		printf("�޴��� �����ϼ���: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: {
			int num;
			printf("�߰��� ���ڸ� �Է��ϼ���: ");
			scanf_s("%d", &num);
			dinsert(head, num);
			break;
		}
		case 2: {
			int num;
			printf("�߰��� ���ڸ� �Է��ϼ���: ");
			scanf_s("%d", &num);
			dinsert(head->llink, num);
			break;
		}
		case 3: {

			deleted = ddelete(head, head->rlink);

			break;
		}
		case 4:
		{
			deleted = ddelete(head, head->llink);
			break;
		}
		case 5:
		{
			print_dlist(head);
			break;
		}
		case 6:
			exit(0);
			break;
		default:
			printf("�߸��� �����Դϴ�\n");
			break;
		}
	}
}