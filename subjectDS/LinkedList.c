#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

//오류처리함수
void l_error(char* message) {
	printf("%s\n", message);
	exit(1);
}

// 맨 앞에 새 노드 삽입
ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 새 노드 p 생성
	p->data = value; // p의 data 필드에 value의 값 복사
	p->link = head; // p의 link 필드에 head노드가 가리키는 곳의 주소값 복사
	head = p; // head포인터가 가리키는 주소를 노드 p의 주소로 변경
	
	return head; // 새로운 head의 주소값 반환
}

// 노드 pre뒤에 새 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 새 노드 p 생성
	p->data = value; // p의 data 필드에 value의 값 복사
	p->link = pre->link; // p의 link 필드에 노드 pre의 link에 있는 주소값(pre의 다음 노드 주소값) 복사
	pre->link = p; // 노드 pre의 link 필드에 p의 주소값 복사(pre의 새 다음 노드는 p)
	
	return head; // 새로운 head의 주소값 반환
}

// 맨 앞 노드 삭제
ListNode* delete_first(ListNode* head) {
	ListNode* removed; // 삭제할 노드를 가리키는 포인터 변수 생성
	if (head == NULL) return NULL; // 만약 리스트가 비어있다면, NULL 반환
	removed = head; // removed가 head를 가리킨다
	head = removed->link; // 새로운 head는 removed가 가리키는 노드의 다음 노드
	free(removed); // removed가 가리키는 노드 메모리 할당 해제(삭제)
	
	return head; // 새로운 head 노드 주소 반환
}

// 노드 pre 다음 노드 삭제
ListNode* _delete(ListNode* head, ListNode* pre) {
	ListNode* removed; // 삭제할 노드를 가리키는 포인터 변수 생성
	removed = pre->link; // removed가 노드pre의 다음 노드의 주소값을 가리킴
	pre->link = removed->link; // pre노드의 link필드에 removed가 가리키는 노드의 다음 노드 주소값 복사
	free(removed); // removed가 가리키는 노드 메모리 할당 해제(삭제)

	return head; // 새로운 head 노드 주소 반환
}

// 리스트 안에 있는 모든 노드의 data 필드 출력
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) printf("%d->", p->data);
	printf("NULL\n");
}

int main2() {
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}