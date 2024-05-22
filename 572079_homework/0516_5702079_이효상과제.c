#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = h;
    h = p;
    return h;
}

ListNode* insert(ListNode* head, ListNode* pre, element value, int* steps) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    if (pre == NULL) {
        fprintf(stderr, "Insert parameter error: pre == NULL\n");
        return head;
    }
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    (*steps)++;
    return head;
}

ListNode* delete_first(ListNode* h) {
    if (h == NULL) return NULL;
    ListNode* remove = h;
    h = remove->link;
    free(remove);
    return h;
}

ListNode* delete(ListNode* h, ListNode* pre, int* steps) {
    if (pre == NULL || pre->link == NULL) {
        fprintf(stderr, "Delete parameter error: pre is NULL or pre->link is NULL\n");
        return h;
    }
    ListNode* remove = pre->link;
    pre->link = remove->link;
    free(remove);
    (*steps)++;
    return h;
}

void print_list(ListNode* h) {
    while (h != NULL) {
        printf("%d -> ", h->data);
        h = h->link;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = NULL;

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
            int value, position, steps = 0;
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &value);
            printf("�߰��� ��ġ�� �Է��ϼ���: ");
            scanf_s("%d", &position);
            if (position == 0) {
                head = insert_first(head, value);
                steps++;
            }
            else {
                ListNode* p = head;
                for (int i = 1; i < position - 1 && p != NULL; i++) {
                    p = p->link;
                    steps++;

                }
                if (p != NULL) {
                    head = insert(head, p, value, &steps);
                    steps++;
                }
                else {
                    printf("�߸��� ��ġ�Դϴ�\n");
                }
            }
            printf("��ũ�� ���� �̵��� Ƚ��: %d\n", steps);
            break;
        }
        case 2: {
            int position, steps = 0;
            printf("������ ��ġ�� �Է��ϼ���: ");
            scanf_s("%d", &position);
            if (position == 0) {
                head = delete_first(head);
                steps++;
            }
            else {
                ListNode* p = head;
                for (int i = 1; i < position - 1 && p != NULL; i++) {
                    p = p->link;
                    steps++;
                }
                if (p != NULL && p->link != NULL) {
                    head = delete(head, p, &steps);
                    steps++;
                }
                else {
                    printf("�߸��� ��ġ�Դϴ�\n");
                }
            }
            printf("��ũ�� ���� �̵��� Ƚ��: %d\n", steps);
            break;
        }
        case 3: {
            print_list(head);
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
    return 0;
}
