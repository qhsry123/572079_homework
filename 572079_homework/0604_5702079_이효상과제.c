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
		printf("\n다음과 같은 메뉴로 동작하는 프로그램입니다\n");
		printf("1. 숫자입력받아서 리스트 처음에 추가\n");
		printf("2. 숫자입력받아서 리스트 마지막에 추가\n");
		printf("3. 리스트 처음 노드 삭제\n");
		printf("4. 리스트 마지막 노드 삭제\n");
		printf("5.리스트 프린트\n");
		printf("6.프로그램 종료\n");

		int choice;
		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: {
			int num;
			printf("추가할 숫자를 입력하세요: ");
			scanf_s("%d", &num);
			dinsert(head, num);
			break;
		}
		case 2: {
			int num;
			printf("추가할 숫자를 입력하세요: ");
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
			printf("잘못된 선택입니다\n");
			break;
		}
	}
}