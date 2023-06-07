#pragma once
#define MAXSIZE 5

typedef int element;
typedef struct {
	element data[MAXSIZE];
	int front, rear;
}QueueType;

void init_q_queue(QueueType* q); // 큐 초기화
int is_q_empty(QueueType* q); // 공백 상태 검출
int is_q_full(QueueType* q); // 포화 상태 검출
void queue_print(QueueType* q); // 원형큐 출력
void enqueue(QueueType* q, element item); // 원형큐 삽입
element q_peek(QueueType* q); // 큐 내부 요소 보기
