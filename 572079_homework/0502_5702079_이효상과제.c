#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h> 

#define MAX_QUEUE_SIZE 50
#define MAX_STACK_SIZE 50

typedef char element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* sptr) {
    sptr->top = -1;
}

bool is_full(StackType* sptr) {
    return (sptr->top == MAX_STACK_SIZE - 1);
}

bool is_empty(StackType* sptr) {
    return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is full\n");
        exit(1);
    }
    sptr->data[++(sptr->top)] = item;
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    return sptr->data[(sptr->top)--];
}

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

bool que_is_full(QueueType* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

bool que_is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void enqueue(QueueType* q, element item) {
    if (que_is_full(q)) {
        fprintf(stderr, "Queue is full\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (que_is_empty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main() {
    QueueType queue;
    StackType stack;

    while (1) {
        printf("\n������ ���� �޴��� �����ϴ� ���α׷��Դϴ�\n");
        printf("1. ȸ�� �Է�\n");
        printf("2. ȸ�� �˻�\n");
        printf("3. ����\n");

        int choice;
        bool is_palindrome;
        scanf_s("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            init_queue(&queue);
            init_stack(&stack);
            printf("ȸ���� �Է��ϼ���: ");
            char input[MAX_QUEUE_SIZE + 1];
            fgets(input, sizeof(input), stdin);


            input[strcspn(input, "\n")] = '\0';

            if (strlen(input) >= MAX_QUEUE_SIZE) {
                printf("�Էµ� ȸ���� �ʹ� ��ϴ�.\n");
                break;
            }

            for (int i = 0; input[i] != '\0'; i++) {
                char ch = tolower(input[i]);
                if ('a' <= ch && ch <= 'z') {
                    push(&stack, ch);
                    enqueue(&queue, ch);
                }
            }
            break;

        case 2:
            is_palindrome = true;
            while (!que_is_empty(&queue)) {
                char q_front = dequeue(&queue);
                char s_top = pop(&stack);
                if (q_front != s_top) {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome == true)
                printf("ȸ���Դϴ�.\n");
            else
                printf("ȸ���� �ƴմϴ�.\n");
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("�߸��� �����Դϴ�\n");
            break;
        }
    }

    return 0;
}