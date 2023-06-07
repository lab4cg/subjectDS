#pragma once
#define MAXSIZE 5

typedef int element;
typedef struct {
	element data[MAXSIZE];
	int front, rear;
}QueueType;

void init_q_queue(QueueType* q); // ť �ʱ�ȭ
int is_q_empty(QueueType* q); // ���� ���� ����
int is_q_full(QueueType* q); // ��ȭ ���� ����
void queue_print(QueueType* q); // ����ť ���
void enqueue(QueueType* q, element item); // ����ť ����
element q_peek(QueueType* q); // ť ���� ��� ����
