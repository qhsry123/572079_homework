#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s", message);
	return -1;
}

int is_full(QueueType* q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ���� ��������Դϴ�\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return (q->data[q->front]);
	}
}

void print_queue(QueueType* q) {
	int i;
	if (is_empty(q)) {
		error("ť�� ��� �ֽ��ϴ�\n");
		return -1;

	}
	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
		printf("[%2d] %2d, ", i, q->data[i]);
	}
	printf("[%2d] %2d\n", i, q->data[i]);
}


main() {

	QueueType queue;
	element e;
	int op1;
	init_queue(&queue);
	while (1)
	{
		printf("\n������ ���� �޴��� �����ϴ� ���α׷��Դϴ�\n");
		printf("1. ť�� ���� ����\n");
		printf("2. ť�� ���Ҹ� ����\n");
		printf("3. ť�� ���Ҹ� ���\n");
		printf("4. ����\n");

		int choice;
		scanf_s("%d", &choice);

		switch (choice)
		{

		case 1:
			printf("ť�� ������ ���ڸ� �Է��ϼ���");
			int q;
			scanf_s("%d", &q);
			enqueue(&queue, q);
			break;

		case 2:
			op1 = dequeue(&queue);
			if (op1 != -1) {
				printf("ť���� ������ ����: %d\n", op1);
			}
			break;
		case 3:
			print_queue(&queue);

			break;
		case 4:
			printf("���α׷�����\n");
			exit(0);
			break;

		default:
			printf("�߸��� �����Դϴ�\n");
			break;
		}


	}
}