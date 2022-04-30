#include <stdio.h>
#include <Stdlib.h>
#include <time.h>

typedef struct node {
	int bomb;
	struct node* link;
} Node;

Node* CL = NULL;

void print_list() {
	Node* p;

	p = CL;
	printf("( ");

	if (CL != NULL) {
		do {
			printf("%d ", p->bomb);
			p = p->link;
		} while (p != CL);
	}
	printf(")\n\n");
}

int main() {
	Node* p, * new, * mid;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	CL = new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	p = CL;
	CL->link = new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	p = p->link;
	p->link = new;
	new->link = CL;

	print_list();

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	p = p->link;
	new->link = p->link;
	p->link = new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	p = p->link;
	new->link = CL;
	CL = new;
	p->link = new;

	print_list();

	mid = p;

	int bombCount = 0;
	do {
		if (p->bomb == 1)
			bombCount++;
		p = p->link;
	} while (p != mid);
	printf("Bomb Count is %d!!!\n", bombCount);

	Node* del;
	p = CL;
	while (p->link != CL)
		p = p->link;

	del = p->link;
	p->link = del->link;
	CL = del ->link;
	free(del);

	print_list();
}