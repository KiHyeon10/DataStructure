#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	char name[20];
	int id;
	struct node* link;
} Node;

Node* head = NULL;

Node* search_list_by_name(char* name) {
	Node* p;
	p = head;
	for (; p; p->link) {
		if (strcmp(p->name, name) == 0)
			return p;

		p = p->link;
	}
	return NULL;
}
Node* search_list_by_id(int id) {
	Node* p;
	p = head;
	for (; p; p->link) {
		if (p->id == id)
			return p;
		p = p->link;
	}
	return NULL;
}

void print_list() {
	Node* p;
	p = head;
	for (; p; p->link) {
		printf("(%s, %d)", p->name, p->id);
		p = p->link;
	}
	printf("\n");
}

void insert(Node* pre, char* name, int id) {
	Node* A = (Node*)malloc(sizeof(Node));
	strcpy(A->name, name);
	A->id = id;

	if (pre == NULL) {
		A->link = head;
		head = A;
	}
	else {
		A->link = pre->link;
		pre->link = A;
		//pre = pre->link;
	}

}

void delete(char* name, int id) {
	Node* pre;
	Node* del;

	if (head == NULL) {
		printf("List is empty!!!\n");
		return;
	}
	if(strcmp(head->name, name) == 0 && head->id == id) {
		del = head;
		head = del->link;
		free(del);
		return;
	}
	else {
		pre = head;
		for (;pre->link;) {
			if (strcmp(pre->link->name, name) == 0 && pre->link->id == id) {
				del = pre->link;
				pre->link = del->link;
				free(del);
				return;
			}
			pre = pre->link;
		}
		printf("No items\n");
	}
}

int main() {
	Node* pre = NULL;
	Node* new = (Node*)malloc(sizeof(Node));

	insert(NULL, "ÀüÃ¢¿Ï", 1000);
	print_list();

	insert(NULL, "À±Àç¼®", 2000);
	print_list();

	pre = search_list_by_name("ÀüÃ¢¿Ï");
	insert(pre, "±è´ëÈñ", 3000);
	print_list();

	pre = search_list_by_id(1000);
	insert(pre, "±èµ¿¹Î", 4000);
	print_list();

	insert(NULL, "¼ÛÅÂ¿ø", 5000);
	print_list();

	new = search_list_by_name("À±Àç¼®");
	printf("name: %s  id:%d\n", new->name, new->id);

	new = search_list_by_id(3000);
	printf("name: %s  id:%d\n", new->name, new->id);

	printf("Delete start\n");
	delete("¼ÛÅÂ¿ø", 5000);
	print_list();

	delete("À±Àç¼®", 2000);
	print_list();

	delete("±èµ¿¹Î", 4000);
	print_list();

	delete("±è´ëÈñ", 3000);
	print_list();
	
	delete("ÀüÃ¢¾È", 1000);
	print_list();

	delete("ÀüÃ¢¿Ï", 1000);
	print_list();
	
	delete("±è´ëÈñ", 3000);
}