#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayLIstType;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
}
init(ArrayLIstType* L) {
	L->size = 0;
}

int move_count = 0;

int is_full(ArrayLIstType* L) {
	//if (L->size >= MAX_LIST_SIZE) return 1;
	//else return 0;
	return (L->size == MAX_LIST_SIZE);
}

void insert(ArrayLIstType* L, int pos, element item) {

	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = L->size - 1; i >= pos; i = i - 1) {
			L->array[i + 1] = L->array[i];
			move_count++;
		}
		L->array[pos] = item;;
		L->size = L->size + 1;
	}
}


void insert_last(ArrayLIstType* L, element item) {
	if (L->size == MAX_LIST_SIZE) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}


void insert_first(ArrayLIstType* L, element item) {
	insert(L, 0, item);

}

void clear(ArrayLIstType* L) {
	init(L);
}

element get_entry(ArrayLIstType* L, int pos) {
	if (pos > 0 && pos < L->size)
		return L->array[pos];
	else
		error("��ġ����");

}

int get_length(ArrayLIstType* L) {
	return L->size;
}

int is_empty(ArrayLIstType* L) {
	return (L->size == 0);
}


void print_list(ArrayLIstType* L) {

	for (int i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("NULL\n");
}

element delete(ArrayLIstType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("��ġ����");
	else {
		element item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++) {
			L->array[i] = L->array[i + 1];
			move_count++;
		}
		L->size = L->size - 1;
		return item;

	}
}

int main() {

	ArrayLIstType list;
	init(&list);
	while (1) {
		printf("\n������ ���� �޴��� �����ϴ� ���α׷��Դϴ�\n");
		printf("1. ����Ʈ�� �߰�\n");
		printf("2. ����Ʈ���� ����\n");
		printf("3. ����Ʈ���\n");
		printf("4. ���α׷� ����\n");

		int choice;
		scanf_s("%d", &choice);


		switch (choice) {
		case 1: {
			int item, pos;
			move_count = 0;
			printf("����:1");
			printf("\n���ڸ� �Է��ϼ���:");
			scanf_s("%d", &item);
			printf("�߰��� ��ġ�� �Է��ϼ���");
			scanf_s("%d", &pos);
			insert(&list, pos, item);
			printf("���ԿϷ�, ������ �̵�Ƚ��:%d\n", move_count);
			break;
		}
		case 2: {
			move_count = 0;
			int pos;
			printf("����:2");
			printf("\n���� ��ġ�� �Է��ϼ���");
			scanf_s("%d", &pos);
			delete(&list, pos);
			printf("���ԿϷ�, ������ �̵�Ƚ��:%d\n", move_count);
			break;
		}
		case 3: {

			print_list(&list);
			break;
		}
		case 4:
			exit(0);
			break;

		default:
			printf("�߸��� �����Դϴ�\n");
			break;
		}
	}
}