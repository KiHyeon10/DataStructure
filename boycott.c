#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

#define MAX_QUEUE_SIZE 100

typedef struct {
	int id;
	int tEvent;
	int tService;
} Event;

typedef Event element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

int tSimulation;
double probEvent;
int tMaxService;
int totalWaitTime;
int nEvents;
int nServedEvents;

double unitRand() {
	return (rand() / (double)RAND_MAX);
}

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void insertEvent(QueueType* q, int eventTime) {
	nEvents++;
	Event A;
	A.id = nEvents;
	A.tEvent = eventTime;
	A.tService = (rand() % tMaxService) + 1;
	enqueue(q, A);
	printf("�̺�Ʈ %d �߻� (ó���ð�: %d��)\n", A.id, A.tService);
}

int main() {
	QueueType q;
	init_queue(&q);
	Event a;
	int serviceTime = 0;
	int sec;

	srand((unsigned int)time(NULL));

	totalWaitTime = 0;
	nEvents = 0;
	nServedEvents = 0;

	printf("�ùķ��̼� �� �ִ� �ð� (����: ��) = ");
	scanf("%d", &tSimulation);
	printf("�����ð�(1��)�� �̺�Ʈ�� �߻��� Ȯ�� (ex| 0.1) = ");
	scanf("%lf", &probEvent);
	printf("�� �̺�Ʈ�� ���� �ִ� ó�� �ð� (����: ��) = ");
	scanf("%d", &tMaxService);
	printf("============================================================================\n");

	for (sec = 0; sec < tSimulation; sec++) {
		printf("���� �ð�: %d\n", sec);
		if (probEvent >= unitRand())
			insertEvent(&q, sec);
		if (serviceTime <= 0 && !is_empty(&q)) {
			a = dequeue(&q);
			nServedEvents++;
			totalWaitTime = sec - a.tEvent;
			serviceTime = a.tService;
			printf("�̺�Ʈ %d ó�� ���� (���ð�: %d��)\n", a.id, totalWaitTime);
		}
		serviceTime--;
	}
	printf("============================================================================\n");
	printf("Simulation Report!\n\n\n");
	printf("ó���� �̺�Ʈ ��\t = %d\n", nServedEvents);
	printf("��ü ��� �ð�\t\t = %d��\n", totalWaitTime);
	printf("�̺�Ʈ �� ��մ��ð�\t = %.2f��\n", (float)totalWaitTime / nServedEvents);
	printf("���� ��� �̺�Ʈ �� \t = %d\n", nEvents - nServedEvents);
}