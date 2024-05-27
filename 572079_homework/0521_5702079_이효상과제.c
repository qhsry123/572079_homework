#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

// 문자열을 안전하게 복사하는 함수
void safe_strcpy(char* dest, size_t dest_size, const char* src) {
    strncpy_s(dest, dest_size, src, _TRUNCATE);
}

ListNode* insert_first(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    size_t len = strlen(value) + 1;
    p->data = (char*)malloc(len); // 문자열에 필요한 메모리를 할당
    safe_strcpy(p->data, len, value); // 문자열 복사
    p->link = h;
    h = p;
    return h;
}

ListNode* insert_last(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    size_t len = strlen(value) + 1;
    p->data = (char*)malloc(len); // 문자열에 필요한 메모리를 할당
    safe_strcpy(p->data, len, value); // 문자열 복사
    p->link = NULL;

    if (h == NULL) {
        return p;
    }

    ListNode* temp = h;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = p;
    return h;
}

ListNode* delete_first(ListNode* h) {
    if (h == NULL) return NULL;
    ListNode* remove = h;
    h = remove->link;
    free(remove->data); // 할당된 문자열 메모리 해제
    free(remove);
    return h;
}

ListNode* delete(ListNode* h, element value, ListNode** deleted_head) {
    ListNode* p = h;
    ListNode* prev = NULL;

    while (p != NULL && strcmp(p->data, value) != 0) {
        prev = p;
        p = p->link;
    }

    if (p == NULL) {
        printf("해당과일이 없습니다.\n");
        return h;
    }

    if (prev == NULL) {
        h = p->link;
    }
    else {
        prev->link = p->link;
    }

    // 삭제된 항목을 삭제된 목록에 추가
    *deleted_head = insert_last(*deleted_head, p->data);

    free(p->data); // 할당된 문자열 메모리 해제
    free(p);
    return h;
}

ListNode* search_list(ListNode* h, element x) {
    ListNode* p = h;

    while (p != NULL) {
        if (strcmp(p->data, x) == 0) return p;
        p = p->link;
    }
    return NULL;
}

void print_list(ListNode* h) {
    while (h != NULL) {
        printf("[%s] ", h->data);
        h = h->link;
    }
    printf("\n");
}

int main() {
    ListNode* head = NULL;
    ListNode* deleted_head = NULL;

    // 초기 과일 목록을 리스트 끝에 추가
    head = insert_last(head, "Mango");
    head = insert_last(head, "Orange");
    head = insert_last(head, "Apple");
    head = insert_last(head, "Grape");
    head = insert_last(head, "Cherry");
    head = insert_last(head, "Plum");
    head = insert_last(head, "Guava");
    head = insert_last(head, "Raspberry");
    head = insert_last(head, "Banana");
    head = insert_last(head, "Peach");

    while (1) {
        printf("\n다음과 같은 메뉴로 동작하는 프로그램입니다\n");
        printf("1. 맨 마지막에 새로운 과일 추가\n");
        printf("2. 리스트에 있는 과일 삭제\n");
        printf("3. 삭제된 과일 목록 출력\n");
        printf("4. 프로그램 종료\n");

        int choice;
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            char fruit[100];
            printf("\n추가할 과일 이름을 입력하세요: ");
            scanf_s("%99s", fruit, (unsigned)_countof(fruit));  // 수정: 버퍼 크기 지정

            if (search_list(head, fruit) != NULL) {
                printf("이미 존재하는 과일입니다.\n");
            }
            else {
                head = insert_last(head, fruit);
            }

            break;
        }
        case 2: {
            char fruit[100];
            printf("\n삭제할 과일 이름을 입력하세요: ");
            scanf_s("%99s", fruit, (unsigned)_countof(fruit));  // 수정: 버퍼 크기 지정
            head = delete(head, fruit, &deleted_head);
            break;
        }
        case 3: {
            printf("삭제된 과일 목록: ");
            print_list(deleted_head);
            break;
        }
        case 4:
            while (head != NULL) {
                head = delete_first(head);
            }
            while (deleted_head != NULL) {
                deleted_head = delete_first(deleted_head);
            }
            exit(0);
            break;
        default:
            printf("잘못된 선택입니다\n");
            break;
        }
    }

    return 0;
}
