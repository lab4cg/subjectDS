#pragma once

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode* link;
} ListNode;


void l_error(char* message); // ����ó���Լ�
ListNode* insert_first(ListNode* head, int value); // �� ó���� ����
ListNode* insert(ListNode* head, ListNode* pre, element value); // pre��� ��� �ڿ� ��� �߰�
ListNode* delete_first(ListNode* head); // �� �� ��� ���� 
ListNode* _delete(ListNode* head, ListNode* pre); // pre��� ��� ������ ��� ����
void print_list(ListNode* head);