#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

// ���ڿ��� �����ϰ� �����ϴ� �Լ�
void safe_strcpy(char* dest, size_t dest_size, const char* src) {
    strncpy_s(dest, dest_size, src, _TRUNCATE);
}

ListNode* insert_first(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    size_t len = strlen(value) + 1;
    p->data = (char*)malloc(len); // ���ڿ��� �ʿ��� �޸𸮸� �Ҵ�
    safe_strcpy(p->data, len, value); // ���ڿ� ����
    p->link = h;
    h = p;
    return h;
}

ListNode* insert_last(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    size_t len = strlen(value) + 1;
    p->data = (char*)malloc(len); // ���ڿ��� �ʿ��� �޸𸮸� �Ҵ�
    safe_strcpy(p->data, len, value); // ���ڿ� ����
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
    free(remove->data); // �Ҵ�� ���ڿ� �޸� ����
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
        printf("�ش������ �����ϴ�.\n");
        return h;
    }

    if (prev == NULL) {
        h = p->link;
    }
    else {
        prev->link = p->link;
    }

    // ������ �׸��� ������ ��Ͽ� �߰�
    *deleted_head = insert_last(*deleted_head, p->data);

    free(p->data); // �Ҵ�� ���ڿ� �޸� ����
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

    // �ʱ� ���� ����� ����Ʈ ���� �߰�
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
        printf("\n������ ���� �޴��� �����ϴ� ���α׷��Դϴ�\n");
        printf("1. �� �������� ���ο� ���� �߰�\n");
        printf("2. ����Ʈ�� �ִ� ���� ����\n");
        printf("3. ������ ���� ��� ���\n");
        printf("4. ���α׷� ����\n");

        int choice;
        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            char fruit[100];
            printf("\n�߰��� ���� �̸��� �Է��ϼ���: ");
            scanf_s("%99s", fruit, (unsigned)_countof(fruit));  // ����: ���� ũ�� ����

            if (search_list(head, fruit) != NULL) {
                printf("�̹� �����ϴ� �����Դϴ�.\n");
            }
            else {
                head = insert_last(head, fruit);
            }

            break;
        }
        case 2: {
            char fruit[100];
            printf("\n������ ���� �̸��� �Է��ϼ���: ");
            scanf_s("%99s", fruit, (unsigned)_countof(fruit));  // ����: ���� ũ�� ����
            head = delete(head, fruit, &deleted_head);
            break;
        }
        case 3: {
            printf("������ ���� ���: ");
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
            printf("�߸��� �����Դϴ�\n");
            break;
        }
    }

    return 0;
}
