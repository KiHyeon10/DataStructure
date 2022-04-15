#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct term {
	int row;
	int col;
	int val;
	struct term* link;
} Term;

Term* head = NULL;

int main() {
	int A[5][5] = { {0,0,1,0,0}, {2,0,0,0,0}, {0,0,0,3,0},  {0,4,0,0,0}, {0,0,0,0,5} };

	Term* a = (Term*)malloc(sizeof(Term));
	a->row = a->col = a->val = 5;
	a->link = NULL;
	head = a;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (A[i][j] != 0) {
				Term* b = (Term*)malloc(sizeof(Term));
				b->row = i;
				b->col = j;
				b->val = A[i][j];
				b->link = a->link;
				a->link = b;
				a = a->link;
			}
		}
	}

	Term* p = head;
	for (; p; p->link) {
		printf("%d %d %d\n", p->row, p->col, p->val);
		p = p->link;
	}
}