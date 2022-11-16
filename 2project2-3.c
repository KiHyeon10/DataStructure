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

void bubbleSort(Fitbit_Daily_Info A[], int n) {
	for (int i = DAY; i > 1 ; i--) {
		for (int j = 1; j < n; j++) {
			if (A[j].efficiency > A[j + 1].efficiency) {
				Fitbit_Daily_Info temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
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

	bubbleSort(monthly_info, DAY);

	printData();
}