#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
#pragma warning(disable:4996)

typedef char element[100];
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

DlistNode* current;

DlistNode* dinsert(DlistNode* head, DlistNode* pre, element value) {
	DlistNode* new = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy(new->data, value);

	if (head == NULL) {
		head = new;
		new->rlink = NULL;
		new->rlink = NULL;
	}
	else if (pre == NULL) {
		new->rlink = head;
		head = new;
		new->llink = NULL;
		new->rlink->llink = new;
	}
	else {
		new->rlink = pre->rlink;
		pre->rlink = new;
		new->llink = pre;
		if (new->rlink != NULL)
			new->rlink->llink = new;
	}
	return head;
}

DlistNode* ddelete(DlistNode* head, DlistNode* removed) {
	if (head == NULL)
		printf("ddelete() error\n");

	else if (head == removed) {
		head = removed->rlink;
		if (removed->rlink != NULL)
			removed->rlink->llink = NULL;
		free(removed);
	}
	else {
		removed->llink->rlink = removed->rlink;
		if (removed->rlink != NULL)
			removed->rlink->llink = removed->llink;
		free(removed);
	}
	return head;
}

void print_dlist(DlistNode* head) {
	DlistNode* p;

	for (p = head; p != NULL; p = p->rlink) {
		if (p == current)
			printf("<-| #%s# |->", p->data);
		else
			printf("<-| %s |->", p->data);
	}
	printf("\n");
}

int main() {
	DlistNode* head = NULL;
	char filename[100];
	char ch;

	head = dinsert(head, NULL, "The Next Right Thing");
	head = dinsert(head, NULL, "Show Yourself");
	head = dinsert(head, NULL, "Into The Unknown");
	head = dinsert(head, NULL, "All Is Found");

	current = head;
	print_dlist(head);
	strcpy(filename, current->data);
	strcat(filename, ".wav");
	PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);

	do {
		printf("\n명령어를 입력하시오(<, >, q): ");
		ch = getch();
		printf("\n\n\n");
		if (ch == '<') {
			if (current->llink != NULL) {
				current = current->llink;
				print_dlist(head);
				strcpy(filename, current->data);
				strcat(filename, ".wav");
				PlaySoundA(NULL, NULL, NULL);
				PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);
			}
			else
				printf("첫 번째 노래입니다\n");
		}
		else if (ch == '>') {
			if (current->rlink != NULL) {
				current = current->rlink;
				print_dlist(head);
				strcpy(filename, current->data);
				strcat(filename, ".wav");
				PlaySoundA(NULL, NULL, NULL);
				PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);
			}
			else
				printf("마지막 노래입니다.\n");
		}
	} while (ch != 'q');

}