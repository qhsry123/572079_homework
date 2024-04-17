#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define MAX_STACK_SIZE 5

typedef int element;
typedef struct Stacktype {
	element data[MAX_STACK_SIZE];
	int capacity;
	int top;
} StackType;


// create : 이미 만들었음, StackType의 변수를 선언하면 만들어짐
// delete : 할수 없음

// init 
void init(StackType* sptr) {

	sptr->top = -1;

}

// is_full
int is_full(StackType* sptr) {
	return (sptr->top == (MAX_STACK_SIZE - 1));

}

int is_empty(StackType* sptr) {
	return (sptr->top == -1);
}

// push
void push(StackType* sptr, element item) {

	if (is_full(sptr)) {
		printf("Stack overflow \n");
		return;

	}
	else sptr->data[++(sptr->top)] = item;

}

element pop(StackType* sptr) {

	if (is_empty(sptr)) {
		printf("Stack underflow\n");
		return -1;
	}
	else {

		return (sptr->data[(sptr->top)--]);
	}
}


element peek(StackType* sptr) {

	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		// r = stack[top];
		// top = top - 1;
		// return r;
		return (sptr->data[sptr->top]);
	}
}




void print_stack(StackType* sptr) {
	if (is_empty(sptr)) {
		printf("Stack is empty \n");
	}
	else {
		printf("Stack elements:");
		for (int i = 0; i < sptr->top; i++) {
			printf(" %d ", sptr->data[i]);
		}
		printf(" %d \n", sptr->data[sptr->top]);
	}
}


int main() {

	StackType sptr;
	init(&sptr);
	int rand_num;
	int i;

	srand(time(NULL));

	for (i = 1; i <= 30; i++) {
		rand_num = rand() % 100 + 1;


		if (rand_num % 2 == 0) {
			if (is_full(&sptr)) {
				printf("current rand num : %d| Even \n", rand_num);
				push(&sptr, rand_num);
				print_stack(&sptr);
			}
			else {
				printf("current rand num : %d| Even \n", rand_num);
				push(&sptr, rand_num);
				printf("Push: %d\n", rand_num);
				print_stack(&sptr);

			}
		}

		else {
			if (is_empty(&sptr)) {
				printf("current rand num : %d| Odd \n", rand_num);
				rand_num = pop(&sptr);
				print_stack(&sptr);
			}
			else {
				printf("current rand num : %d| Odd \n", rand_num);
				rand_num = pop(&sptr);
				printf("Pop:%d\n", rand_num);
				print_stack(&sptr);

			}
		}

		printf("\n");
	}





}