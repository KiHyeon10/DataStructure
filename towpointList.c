#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int bomb;
	struct node* llink;
	struct node* rlink;
}Node;

Node* DL = NULL;

void print_list() {
	Node* p;

	p = DL;
	printf("( ");
	while (p != NULL) {
		printf("%d ", p->bomb);
		p = p->rlink;
	}
	printf(")\n\n");
}

int main() {
	Node* p, * new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	DL = new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	p = DL;
	p->rlink = new;
	new->llink = p;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	p = DL;
	p->rlink->llink = new;
	new->rlink = p->rlink;
	p->rlink = new;
	new->llink = p;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	p = p->rlink->rlink;
	p->rlink = new;
	new->llink = p;

	print_list();

	p = DL;
	while (p->rlink != NULL)
		p = p->rlink;

	int bombCount = 0;
	while (p != NULL) {
		if (p->bomb == 1)
			bombCount++;
		p = p->llink;
	}
	printf("Bomb Count is %d!!!\n", bombCount);
}