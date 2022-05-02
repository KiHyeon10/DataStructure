#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init_stack(LinkedStackType* s) {
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else
		return s->top->data;
}

void printStack(LinkedStackType* s) {
	for (StackNode* p = s->top; p; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	LinkedStackType s;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printStack(&s);
	printf("pop\t=> %d\t", pop(&s));
	printStack(&s);
	printf("peek\t=> %d\t", peek(&s));
	printStack(&s);
	printf("pop\t=> %d\t", pop(&s));
	printStack(&s);
	printf("pop\t=> %d\t", pop(&s));
	printStack(&s);

}