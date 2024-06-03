#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {

	element data;
	struct listNode* link;
}ListNode;



ListNode* insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}

ListNode* insert_last(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = node;
	}
	else {
		node->link = tail->link;
		tail->link = node;
		tail = node;
	}
	return tail;
}


ListNode* delete_first(ListNode* tail) {

	if (tail == NULL) return tail;
	else if (tail->link == tail) {
		tail = NULL;
		tail->link = NULL;
		return tail;
	}
	ListNode* remove = tail->link;
	tail->link = remove->link;
	free(remove);
	return tail;

}

ListNode* delete_last(ListNode* tail) {

	if (tail == NULL) return tail;
	else if (tail->link == tail) {
		tail = NULL;
		tail->link = NULL;
		free(tail);
		return tail;
	}
	ListNode* pre = tail;
	ListNode* remove = tail;
	do {
		pre = pre->link;
	} while (pre->link != remove);
	pre->link = tail->link;
	tail = pre;
	free(remove);
	return tail;

}













void print_list(ListNode* tail) {
	ListNode* p;
	if (tail == NULL)return;
	p = tail->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != tail);
	printf("%d (head) \n", p->data);
}

main() {

	ListNode* tail = NULL;




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
			tail = insert_first(tail, num);
			break;
		}
		case 2: {
			int num;
			printf("추가할 숫자를 입력하세요: ");
			scanf_s("%d", &num);
			tail = insert_last(tail, num);
			break;
		}
		case 3: {


			tail = delete_first(tail);
			break;
		}
		case 4:
		{
			tail = delete_last(tail);
			break;
		}
		case 5:
		{
			print_list(tail);
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