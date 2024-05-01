#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <string.h>

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stacktype {
	// element data[];
	element* data;
	int capacity;
	int top;
} StackType;


// create : 이미 만들었음, StackType의 변수를 선언하면 만들어짐
// delete : 할수 없음

// init 
void init(StackType* sptr, int ofs) {
	sptr->data = (element*)malloc(sizeof(StackType) * ofs);
	sptr->top = -1;
	sptr->capacity = ofs;
}

// is_full
int is_full(StackType* sptr) {
	// printf("[is_full] top = %d, capacity = %d\n", sptr->top, sptr->capacity);
	if (sptr->top == sptr->capacity - 1) {
		sptr->capacity = sptr->capacity * 2;
		sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));

	}
	return 0;
}

int is_empty(StackType* sptr) {
	return (sptr->top == -1);
}

// push
void push(StackType* sptr, element item) {

	if (is_full(sptr)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else {
		sptr->top = sptr->top + 1;
		sptr->data[sptr->top] = item;
	}
}

element pop(StackType* sptr) {
	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		// r = sptr->stack[sptr->top];
		// sptr->top = sptr->top - 1;
		// return r;
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

void stack_print(StackType* sptr) {
	for (int i = sptr->top; i >= 0; i--) {
		printf("[%d]", sptr->data[i]);
	}
}

int eval(char* expr) {
	int len;
	StackType s;

	init(&s, 20);
	len = strlen(expr);
	for (int i = 0; expr[i] != '\0'; i++) {
		int ch = expr[i];
		int value;
		int op1, op2;

		printf("\nexpression :%c\n", expr[i]);
		if ((ch == '+') || (ch == '-')
			|| (ch == '*') || (ch == '/')) {
			op1 = pop(&s);
			op2 = pop(&s);
			switch (ch) {
			case '+': push(&s, op2 + op1); break;
			case '-':push(&s, op2 - op1); break;
			case '*':push(&s, op2 * op1); break;
			case '/':push(&s, op2 / op1); break;
			default:;
			}
		}
		else if ((ch >= '0') && (ch <= '9')) {
			value = ch - '0';
			push(&s, value);
		}

	}
	return (pop(&s));
}

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

char* infix_to_postfix(char expr[]) {
	char* postfix_expression = (char*)malloc(sizeof(char) * MAX_STACK_SIZE);
	char top_op;
	int len = strlen(expr);
	StackType s;
	int j = 0;
	init(&s, MAX_STACK_SIZE);
	for (int i = 0; i < len; i++) {
		switch (expr[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!is_empty(&s) && prec(expr[i]) <= prec((char)peek(&s))) {
				postfix_expression[j++] = pop(&s);
			}
			push(&s, (int)expr[i]);
			break;
		case '(': push(&s, (int)expr[i]); break;
		case ')':
			top_op = (char)pop(&s);
			while (top_op != '(') {
				postfix_expression[j++] = top_op;
				top_op = (char)pop(&s);
			}
			break;
		default: postfix_expression[j++] = expr[i];
			break;
		}
		/*printf(" Stack : ");
		stack_print(&s); */
	}
	while (!is_empty(&s)) {
		/* printf(" Stack : ");
		stack_print(&s); */
		postfix_expression[j++] = (char)pop(&s);
	}
	postfix_expression[j] = '\0';
	return postfix_expression;
}

int main() {
	int result;

	char infix_expression[MAX_STACK_SIZE];
	char* postfix_expression;

	while (1)
	{
		printf("다음과 같은 메뉴로 동작하는 프로그램입니다\n");
		printf("1. 중위식 수식 입력 받음\n");
		printf("2. 중위식 수식을 후위식 수식으로 변환\n");
		printf("3. 후위식 수식을 계산\n");
		printf("4. 종료\n");

		int choice;
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("중위식 입력하세요: ");
			getchar();
			fgets(infix_expression, sizeof(infix_expression), stdin);
			printf("입력된 중위식 : %s\n", infix_expression);
			break;

		case 2:
			postfix_expression = infix_to_postfix(infix_expression);
			printf("후위식으로 변환된 수식: %s\n", postfix_expression);
			free(postfix_expression);
			break;

		case 3:
			postfix_expression = infix_to_postfix(infix_expression);
			result = eval(postfix_expression);
			printf("계산 결과: %d\n", result);
			free(postfix_expression);
			break;

		case 4:
			printf("프로그램을 종료합니다\n");
			exit(0);

		default:
			printf("잘못된 선택입니다.\n");
			break;
		}
	}
	return 0;
}