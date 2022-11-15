#include <stdio.h>
#pragma warning(disable:4996)
#define DAY 30

typedef struct {
	int date;
	int duration;
	int efficiency;
	char level[10];
} Fitbit_Daily_Info;

Fitbit_Daily_Info monthly_info[DAY + 1];

int partition(Fitbit_Daily_Info A[], int p, int r) {
	Fitbit_Daily_Info x = A[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (A[j].date < x.date) {
			i++;
			Fitbit_Daily_Info temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	Fitbit_Daily_Info temp1 = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp1;

	return i + 1;
}

void quickSort(Fitbit_Daily_Info A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void printData() {
	for (int i = 1; i <= DAY; i++) {
		printf("[%d] Date: %d	Duration: %d	Efficienty: %d	Level:%s\n", i, monthly_info[i].date, monthly_info[i].duration, monthly_info[i].efficiency, monthly_info[i].level);
	}
}

int main() {
	freopen("fitbit_data.txt", "r", stdin);

	for (int i = 1; i <= DAY; i++) {
		scanf("%d", &monthly_info[i].date);
		scanf("%d", &monthly_info[i].duration);
		scanf("%d", &monthly_info[i].efficiency);
		scanf("%s", monthly_info[i].level);
	}

	quickSort(monthly_info, 1, DAY);

	printData();
}