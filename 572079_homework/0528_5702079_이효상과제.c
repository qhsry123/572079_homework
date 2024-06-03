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
			tail = insert_first(tail, num);
			break;
		}
		case 2: {
			int num;
			printf("�߰��� ���ڸ� �Է��ϼ���: ");
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
			printf("�߸��� �����Դϴ�\n");
			break;
		}
	}
}