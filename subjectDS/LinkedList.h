#pragma once
#define MAXSIZE 100

typedef int element;
typedef struct ListNode{
	element data;
	struct LinstNode* link;
}ListNode;


void error(char* message); // 오류처리함수
ListNode* insert_first(ListNode* head, int value); // 맨 처음에 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value); // pre라는 노드 뒤에 노드 추가
ListNode* delete_first(ListNode* head); // 맨 앞 노드 삭제 
ListNode* _delete(ListNode* head, ListNode* pre); // pre라는 노드 다음의 노드 삭제
void print_list(ListNode* head);