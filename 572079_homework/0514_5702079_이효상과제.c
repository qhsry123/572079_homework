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
		error("리스트 오버플로우");
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
		error("위치오류");

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
		error("위치오류");
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
		printf("\n다음과 같은 메뉴로 동작하는 프로그램입니다\n");
		printf("1. 리스트에 추가\n");
		printf("2. 리스트에서 삭제\n");
		printf("3. 리스트출력\n");
		printf("4. 프로그램 종료\n");

		int choice;
		scanf_s("%d", &choice);


		switch (choice) {
		case 1: {
			int item, pos;
			move_count = 0;
			printf("선택:1");
			printf("\n숫자를 입력하세요:");
			scanf_s("%d", &item);
			printf("추가할 위치를 입력하세요");
			scanf_s("%d", &pos);
			insert(&list, pos, item);
			printf("삽입완료, 데이터 이동횟수:%d\n", move_count);
			break;
		}
		case 2: {
			move_count = 0;
			int pos;
			printf("선택:2");
			printf("\n삭제 위치를 입력하세요");
			scanf_s("%d", &pos);
			delete(&list, pos);
			printf("삽입완료, 데이터 이동횟수:%d\n", move_count);
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
			printf("잘못된 선택입니다\n");
			break;
		}
	}
}