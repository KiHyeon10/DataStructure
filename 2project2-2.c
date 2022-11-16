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

void selectionSort(Fitbit_Daily_Info A[],int  n) {
	for (int i = n; i > 1; i--) {
		int k = theLargest(A, i);
		Fitbit_Daily_Info temp = A[k];
		A[k] = A[i];
		A[i] = temp;
	}
}

int theLargest(Fitbit_Daily_Info A[], int last) {
	int largest = 1;
	for (int i = 2; i < last; i++) {
		if (A[i].duration > A[largest].duration)
			largest = i;
	}
	return largest;
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

	selectionSort(monthly_info, DAY);

	printData();
}