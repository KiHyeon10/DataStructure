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
	return 0;
}

int size(void) {
	int i = 0;

	Namecard* p = head;
	for (; p; p = p->link)
		i++;
	return i;
}


void insert(int pos, Namecard item) {
	Namecard* new = (Namecard*)malloc(sizeof(Namecard));
	strcpy(new->name, item.name);
	new->id = item.id;
	
	if (pos == 0) {
			new->link = head;
			head = new;
	}
	else {
		Namecard* pre = getNode(pos - 1);
		if (pre != NULL) {
			new->link = pre->link;
			pre->link = new;
		}
		else
			printf("삽입 위치 오류\n");
	}
}

void delete(int pos) {
	if (is_empty() == 1)
		printf("공백상태 오류\n");
	else {
		if (getNode(pos) == NULL)
			printf("삭제 위치 오류\n");
		else {
			Namecard* del = getNode(pos);
			if (pos == 0) {
				head = del->link;
				free(del);
			}
			else {
				Namecard* pre = getNode(pos - 1);
				pre->link = del->link;
				free(del);
			}
		}
	}
}

Namecard get_entry(int pos) {
	Namecard new;
	if (getNode(pos) == NULL) {
		new.id = -1;
		return new;
	}
	else {
		strcpy(new.name, getNode(pos)->name);
		new.id = getNode(pos)->id;
		return new;
	}
}

int find(Namecard item) {
	Namecard* p = head;
	int i = 0;

	for (; p; p = p->link) {
		if (strcmp(p->name, item.name) == 0 && p->id == item.id)
			return i;
		i++;
	}
	return -1;
}

void replace(int pos, Namecard item) {
	if (getNode(pos) == NULL)
		printf("교체 위치 오류\n");
	else {
		strcpy(getNode(pos)->name, item.name);
		getNode(pos)->id = item.id;
	}
}

void print_list(char* msg) {
	Namecard* p = head;

	printf("%s:  ", msg);
	for (; p != NULL; p = p->link)
		printf("  (%s, %d)  ", p->name, p->id);
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