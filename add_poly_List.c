#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)
		printf("error\n");

	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* p_A = plist1->head;
	ListNode* p_B = plist2->head;
	int sum = 0;

	while (p_A != NULL && p_B != NULL) {

		if (p_A->expon == p_B->expon) {
			sum = p_A->coef + p_B->coef;
			insert_last(plist3, sum, p_A->expon);
			p_A = p_A->link;
			p_B = p_B->link;
		}
		else if (p_A->expon > p_B->expon) {
			insert_last(plist3, p_A->coef, p_A->expon);
			p_A = p_A->link;
		}
		else {
			insert_last(plist3, p_B->coef, p_B->expon);
			p_B = p_B->link;
		}
	}
	if (p_A != NULL) {
		for (; p_A; p_A = p_A->link)
			insert_last(plist3, p_A->coef, p_A->expon);
	}
	else {
		for (; p_B; p_B = p_B->link)
			insert_last(plist3, p_B->coef, p_B->expon);
	}
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d", p->coef, p->expon);
		if (p->link != NULL)
			printf(" + ");
	}
	printf("\n");
}

int main(void) {
	ListType* A, * B, * C;

	A = create();
	B = create();
	C = create();

	insert_last(A, 3, 12);
	insert_last(A, 2, 8);
	insert_last(A, 1, 0);

	insert_last(B, 8, 12);
	insert_last(B, -3, 10);
	insert_last(B, 10, 6);

	poly_print(A);
	poly_print(B);

	poly_add(A, B, C);
	poly_print(C);

	free(A);
	free(B);
	free(C);

}
