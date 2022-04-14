#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_IOT_LIST_SIZE 45

typedef struct {
	char name[20];
	int id;
} Namecard;

Namecard iot_list[40];
int length;

Namecard make_Namecard(char name[], int id) {
	Namecard newCard;

	strcpy(newCard.name, name);
	newCard.id = id;

	return newCard;
}

void init(void) {
	length = 0;
}

int size(void) {
	return length;
}

int is_empty(void) {
	if (size() == 0)
		return 1;
	else
		return 0;
}

int is_full(void) {
	if (length == MAX_IOT_LIST_SIZE) {
		return 1;
	}
	else
		return 0;
}

void insert(int pos, Namecard item) {
	int i;
	if (is_full() == 0 && pos >= 0 && pos <= length) {
		for (i = length; i > pos; i--) {
			iot_list[i] = iot_list[i - 1];
		}
		iot_list[pos] = item;
		length++;
	}
	else
		printf("\n포화상태 오류 또는 삽입 위치 오류\n\n");

}

void delete(int pos) {
	int i;

	if (is_empty() == 0 && pos >= 0 && pos < length) {
		for (i = pos; i < length - 1; i++)
			iot_list[i] = iot_list[i + 1];

		length--;
	}
	else
		printf("\n\n공백상태 오류 또는 삭제 위치 오류\n\n");

}

Namecard get_entry(int pos) {
	if (pos >= 0 && pos < length)
		return iot_list[pos];
	else
		return;

}



int find(Namecard item) {
	for (int i = 0; i < length; i++) {
		if ((strcmp(get_entry(i).name, item.name)) == 0 && get_entry(i).id == item.id)
			return i;
		else
			continue;
	}
	return -1;
}

void replace(int pos, Namecard item) {
	if (pos >= 0 && pos < length)
		iot_list[pos] = item;
	else
		printf("\n\n교체 위치 오류\n\n");
}


void sort_list(void) {
	int i, j;
	Namecard B;
	for (i = 0; i < length; i++) {
		for (j = 0; j < length - 1; j++) {
			if (iot_list[j].id > iot_list[j + 1].id) {
				B = iot_list[j];
				iot_list[j] = iot_list[j + 1];
				iot_list[j + 1] = B;
			}
		}
	}
}

void print_list(char* msg) {
	int i;
	printf("%s : ", msg);
	for (i = 0; i < length; i++) {
		printf("(%s, %d) ", iot_list[i].name, iot_list[i].id);
	}

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
	printf("\n\n\n");

	sort_list();
	print_list("Sort");

	printf("\n\n%s is found at %d\n", "김준형", find(make_Namecard("김준형", 20211516)));
	printf("%s is found at %d\n", "김정우", find(make_Namecard("김정우", 20211526)));
	printf("%s is found at %d\n", "채경훈", find(make_Namecard("채경훈", 20211234)));
}