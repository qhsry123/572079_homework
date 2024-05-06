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
		error("큐가 포화상태입니다\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 현재 공백상태입니다\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return (q->data[q->front]);
	}
}

void print_queue(QueueType* q) {
	int i;
	if (is_empty(q)) {
		error("큐가 비어 있습니다\n");
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
		printf("\n다음과 같은 메뉴로 동작하는 프로그램입니다\n");
		printf("1. 큐에 원소 삽입\n");
		printf("2. 큐에 원소를 삭제\n");
		printf("3. 큐의 원소를 출력\n");
		printf("4. 종료\n");

		int choice;
		scanf_s("%d", &choice);

		switch (choice)
		{

		case 1:
			printf("큐에 삽입할 숫자를 입력하세요");
			int q;
			scanf_s("%d", &q);
			enqueue(&queue, q);
			break;

		case 2:
			op1 = dequeue(&queue);
			if (op1 != -1) {
				printf("큐에서 삭제된 원소: %d\n", op1);
			}
			break;
		case 3:
			print_queue(&queue);

			break;
		case 4:
			printf("프로그램종료\n");
			exit(0);
			break;

		default:
			printf("잘못된 선택입니다\n");
			break;
		}


	}
}