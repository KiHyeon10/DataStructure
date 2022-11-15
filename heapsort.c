#include <stdio.h>
#include <stdlib.h>

void heapify(int A[], int k, int n) {
	int left = 2 * k; int right = 2 * k + 1;
	int smaller;

	if (right <= n) {
		if (A[left] < A[right])
			smaller = left;
		else
			smaller = right;
	}
	else if (left <= n)
		smaller = left;
	else
		return;

	if (A[smaller] < A[k]) {
		int temp = A[k];
		A[k] = A[smaller];
		A[smaller] = temp;
		heapify(A, smaller, n);
	}
}

void buildHeap(int A[], int n) {
	for (int i = n / 2; i > 0; i--)
		heapify(A, i, n);
}

void heapSort(int A[], int n) {
	buildHeap(A, n);
	for (int i = n; i > 1; i--) {
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		heapify(A, 1, i - 1);
	}
}

int main() {
	int A[] = { 0, 4, 92, 12, 3, 43, 56, 10, 2, 45, 6, 9, 19, 35, 83 };

	heapSort(A, 16);

	for (int i = 0; i < 15; i++) {
		printf("%d\t", A[i]);
	}
}