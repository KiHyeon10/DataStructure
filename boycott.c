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
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
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
	printf("이벤트 %d 발생 (처리시간: %d초)\n", A.id, A.tService);
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

	printf("시뮬레이션 할 최대 시간 (단위: 초) = ");
	scanf("%d", &tSimulation);
	printf("단위시간(1초)에 이벤트가 발생할 확률 (ex| 0.1) = ");
	scanf("%lf", &probEvent);
	printf("한 이벤트에 대한 최대 처리 시간 (단위: 초) = ");
	scanf("%d", &tMaxService);
	printf("============================================================================\n");

	for (sec = 0; sec < tSimulation; sec++) {
		printf("현재 시간: %d\n", sec);
		if (probEvent >= unitRand())
			insertEvent(&q, sec);
		if (serviceTime <= 0 && !is_empty(&q)) {
			a = dequeue(&q);
			nServedEvents++;
			totalWaitTime = sec - a.tEvent;
			serviceTime = a.tService;
			printf("이벤트 %d 처리 시작 (대기시간: %d초)\n", a.id, totalWaitTime);
		}
		serviceTime--;
	}
	printf("============================================================================\n");
	printf("Simulation Report!\n\n\n");
	printf("처리된 이벤트 수\t = %d\n", nServedEvents);
	printf("전체 대기 시간\t\t = %d초\n", totalWaitTime);
	printf("이벤트 당 평균대기시간\t = %.2f초\n", (float)totalWaitTime / nServedEvents);
	printf("현재 대기 이벤트 수 \t = %d\n", nEvents - nServedEvents);
}