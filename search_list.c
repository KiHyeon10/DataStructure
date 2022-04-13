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

	insert(NULL, "��â��", 1000);
	print_list();

	insert(NULL, "���缮", 2000);
	print_list();

	pre = search_list_by_name("��â��");
	insert(pre, "�����", 3000);
	print_list();

	pre = search_list_by_id(1000);
	insert(pre, "�赿��", 4000);
	print_list();

	insert(NULL, "���¿�", 5000);
	print_list();

	new = search_list_by_name("���缮");
	printf("name: %s  id:%d\n", new->name, new->id);

	new = search_list_by_id(3000);
	printf("name: %s  id:%d\n", new->name, new->id);

	printf("Delete start\n");
	delete("���¿�", 5000);
	print_list();

	delete("���缮", 2000);
	print_list();

	delete("�赿��", 4000);
	print_list();

	delete("�����", 3000);
	print_list();
	
	delete("��â��", 1000);
	print_list();

	delete("��â��", 1000);
	print_list();
	
	delete("�����", 3000);
}