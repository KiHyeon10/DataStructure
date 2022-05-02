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
			printf("���� ��ġ ����\n");
	}
}

void delete(int pos) {
	if (is_empty() == 1)
		printf("������� ����\n");
	else {
		if (getNode(pos) == NULL)
			printf("���� ��ġ ����\n");
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
		printf("��ü ��ġ ����\n");
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

	insert(0, make_Namecard("�Ǳ���", 20191518));
	insert(0, make_Namecard("���翬", 20211521));
	insert(1, make_Namecard("������", 20211516));
	insert(size(), make_Namecard("������", 20211506));
	insert(3, make_Namecard("�ż���", 20211501));
	insert(size(), make_Namecard("������", 20211530));
	insert(10, make_Namecard("������", 20211522));
	print_list("Insert");

	replace(size() - 1, make_Namecard("����", 20211504));
	replace(4, make_Namecard("ä����", 20211498));
	replace(20, make_Namecard("������", 20211490));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	printf("%s is found at %d\n", "������", find(make_Namecard("������", 20211516)));
	printf("%s is found at %d\n", "������", find(make_Namecard("������", 20211526)));
	printf("%s is found at %d\n", "ä����", find(make_Namecard("ä����", 20211234)));

	Namecard temp = get_entry(1);

	if (temp.id != -1)
		printf("\nEntry 1: (%s, %d)\n", temp.name, temp.id);

}