#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

//����ó���Լ�
void l_error(char* message) {
	printf("%s\n", message);
	exit(1);
}

// �� �տ� �� ��� ����
ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // �� ��� p ����
	p->data = value; // p�� data �ʵ忡 value�� �� ����
	p->link = head; // p�� link �ʵ忡 head��尡 ����Ű�� ���� �ּҰ� ����
	head = p; // head�����Ͱ� ����Ű�� �ּҸ� ��� p�� �ּҷ� ����
	
	return head; // ���ο� head�� �ּҰ� ��ȯ
}

// ��� pre�ڿ� �� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // �� ��� p ����
	p->data = value; // p�� data �ʵ忡 value�� �� ����
	p->link = pre->link; // p�� link �ʵ忡 ��� pre�� link�� �ִ� �ּҰ�(pre�� ���� ��� �ּҰ�) ����
	pre->link = p; // ��� pre�� link �ʵ忡 p�� �ּҰ� ����(pre�� �� ���� ���� p)
	
	return head; // ���ο� head�� �ּҰ� ��ȯ
}

// �� �� ��� ����
ListNode* delete_first(ListNode* head) {
	ListNode* removed; // ������ ��带 ����Ű�� ������ ���� ����
	if (head == NULL) return NULL; // ���� ����Ʈ�� ����ִٸ�, NULL ��ȯ
	removed = head; // removed�� head�� ����Ų��
	head = removed->link; // ���ο� head�� removed�� ����Ű�� ����� ���� ���
	free(removed); // removed�� ����Ű�� ��� �޸� �Ҵ� ����(����)
	
	return head; // ���ο� head ��� �ּ� ��ȯ
}

// ��� pre ���� ��� ����
ListNode* _delete(ListNode* head, ListNode* pre) {
	ListNode* removed; // ������ ��带 ����Ű�� ������ ���� ����
	removed = pre->link; // removed�� ���pre�� ���� ����� �ּҰ��� ����Ŵ
	pre->link = removed->link; // pre����� link�ʵ忡 removed�� ����Ű�� ����� ���� ��� �ּҰ� ����
	free(removed); // removed�� ����Ű�� ��� �޸� �Ҵ� ����(����)

	return head; // ���ο� head ��� �ּ� ��ȯ
}

// ����Ʈ �ȿ� �ִ� ��� ����� data �ʵ� ���
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