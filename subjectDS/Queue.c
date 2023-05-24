#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
void init_q_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_q_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_q_full(QueueType* q) {
	return ((q->rear + 1) % MAXSIZE == q->front);
}

// ����ť ��� �Լ�
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

// ����ť �����Լ�
void enqueue(QueueType* q, element item) {
	if (is_q_full(q)) error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q) {
	if (is_q_empty(q)) error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAXSIZE;
	return q->data[q->front];
}

// ���� �Լ�
element q_peek(QueueType* q) {
	if (is_q_empty(q)) error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAXSIZE];
}

// ����ť �ڵ� ��
int main0() {
	QueueType queue;
	element e;

	init_q_queue(&queue);
	printf("---������ �߰� �ܰ�---\n");

	while (!is_q_full(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &e);
		enqueue(&queue, e);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	return 0;
}