#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define DAY 30

//Merge Sort를 사용하여 efficiency 내림차순으로 정렬

typedef struct {
	int date;
	int duration;
	int efficiency;
	char level[10];
} Fitbit_Daily_Info;

Fitbit_Daily_Info monthly_info[DAY + 1];
Fitbit_Daily_Info temp[DAY + 1];

void merge(Fitbit_Daily_Info A[], int p, int q, int r) {

	int i = p, j = q + 1, z = 1;

	while (i <= q && j <= r) {
		if (A[i].efficiency >= A[j].efficiency)
			temp[z++] = A[i++];
		else
			temp[z++] = A[j++];
	}
	while (i <= q)
		temp[z++] = A[i++];

	while (j <= r)
		temp[z++] = A[j++];

	i = p, z = 1;
	while (i <= r)
		A[i++] = temp[z++];
}

void mergeSort(Fitbit_Daily_Info A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}


void printData() {
	for (int i = 1; i <= DAY; i++) {
		printf("[%d] Date: %d	Duration: %d	Efficienty: %d	Level:%s\n", i, monthly_info[i].date, monthly_info[i].duration, monthly_info[i].efficiency, monthly_info[i].level);
	}
}

int main() {
	freopen("Fitbit_data.txt", "r", stdin);

	for (int i = 1; i <= DAY; i++) {
		scanf("%d", &monthly_info[i].date);
		scanf("%d", &monthly_info[i].duration);
		scanf("%d", &monthly_info[i].efficiency);
		scanf("%s", monthly_info[i].level);
	}

	mergeSort(monthly_info, 1, DAY);

	printData();
}