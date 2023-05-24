#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 큐 초기화 함수
void init_q_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_q_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_q_full(QueueType* q) {
	return ((q->rear + 1) % MAXSIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q) {
	printf("Queue(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_q_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAXSIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

// 원형큐 삽입함수
void enqueue(QueueType* q, element item) {
	if (is_q_full(q)) error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_q_empty(q)) error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAXSIZE;
	return q->data[q->front];
}

// 보기 함수
element q_peek(QueueType* q) {
	if (is_q_empty(q)) error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAXSIZE];
}

// 원형큐 코드 끝
int main0() {
	QueueType queue;
	element e;

	init_q_queue(&queue);
	printf("---데이터 추가 단계---\n");

	while (!is_q_full(&queue)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &e);
		enqueue(&queue, e);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	return 0;
}