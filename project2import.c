#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct name_card {
	char name[20];
	int id;
	struct name_card* link;
} Namecard;

Namecard* head = NULL;

Namecard* getNode(int pos) {
	Namecard* p;
	p = head;

	for (int i = 0; i < pos; i++) {
		if (p == NULL)
			return NULL;

		p = p->link;
	}
	return p;
}

Namecard make_Namecard(char name[], int id) {
	Namecard newCard;

	strcpy(newCard.name, name);
	newCard.id = id;
	newCard.link = NULL;

	return newCard;
}

void init() {
	Namecard* p, * removed;

	for (p = head; p != NULL;) {
		removed = p;
		p = p->link;
		free(removed);
	}

	head = NULL;
}

int is_empty(void) {
	if (head == NULL)
		return 1;
	else
		return 0;
}

void insert(int pos, Namecard item) {
	Namecard* p = (Namecard*)malloc(sizeof(Namecard));
	strcpy(p->name, item.name);
	p->id = item.id;
	
	if (pos == 0) {
		p->link = head;
		head = p;
	}
	else {
		Namecard* pre = getNode(pos - 1);

		if (pre != NULL) {
			p->link = pre->link;
			pre->link = p;
		}
		else
			printf("\n삽입 위치 오류\n");
	}
}

void replace(int pos, Namecard item) {
	Namecard* pre = getNode(pos);

	if (pre != NULL) {
		strcpy(pre->name, item.name);
		pre->id = item.id;
	}
	else
		printf("\n 교체 위치 오류\n");
}

void delete(int pos) {
	if (is_empty() == 0) {

		Namecard* pre = getNode(pos-1);
		Namecard* del;
		if (pre != 0) {
			if (pos == 0) {
				del = head;
				head = del->link;
				free(del);
			}
			else {
				del = pre->link;
				pre->link = del->link;
				free(del);
			}
		}
		else
			printf("\n삭제 위치 오류\n");
	}
	else
		printf("\n공백상태 오류\n");
}

Namecard get_entry(int pos) {

	if (size() > pos) {
		Namecard* p = getNode(pos);
		Namecard A;
		strcpy(A.name, p->name);
		A.id = p->id;
		return A;
	}
	else {
		Namecard A;
		A.id = -1;
		return A;
	}
}

int find(Namecard item) {
	Namecard* p = head;
	int i = 0;
	for (;  p != NULL;) {
		if (strcmp(p->name, item.name) == 0 && p->id == item.id) {
			return i;
		}
		i++;
		p = p->link;
	}
	return -1;
}

int size(void) {
	Namecard* p = head;
	int i = 0;
	for (; p != NULL;) {
		p = p->link;
		i++;
	}
	return i;
}

void print_list(char* msg) {
	Namecard* p = head;

	printf("%s:  ", msg);
	for (; p != NULL;) {
		printf("  (%s, %d)  ", p->name, p->id);
		p = p->link;
	}
	printf("\n\n\n");
}


int main() {

	init();
	print_list("Init");

	insert(0, make_Namecard("권기현", 20191518));
	insert(0, make_Namecard("서재연", 20211521));
	insert(1, make_Namecard("김준형", 20211516));
	insert(size(), make_Namecard("서승진", 20211506));
	insert(3, make_Namecard("신서연", 20211501));
	insert(size(), make_Namecard("김지연", 20211530));
	insert(10, make_Namecard("김현수", 20211522));
	print_list("Insert");
	
	replace(size() - 1, make_Namecard("정현", 20211504));
	replace(4, make_Namecard("채경훈", 20211498));
	replace(20, make_Namecard("허정인", 20211490));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	printf("%s is found at %d\n", "김준형", find(make_Namecard("김준형", 20211516)));
	printf("%s is found at %d\n", "김정우", find(make_Namecard("김정우", 20211526)));
	printf("%s is found at %d\n", "채경훈", find(make_Namecard("채경훈", 20211234)));

	Namecard temp = get_entry(1);

	if (temp.id != -1)
		printf("\nEntry 1: (%s, %d)\n", temp.name, temp.id);
}