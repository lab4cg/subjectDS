#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

// data�� ��Ʈ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight) {
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));

	if (root == NULL) { // �޸� �����Ҵ� ����
		printf("memory allocation failed\n");
		exit(1);
	}

	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;

	return root;
}

// ���� �ļ��� ���� ������Ʈ �ϴ� ����
void upThreadRight(treeThNode* node, treeThNode* thRight) {
	node->right = thRight; // node�� �����ļ��ڴ� thRight
	node->isThreadRight = 1; // ������ �����Ͱ� �����ļ������� �˷��ִ� ���� ������Ʈ
}

// �ļ��� ��带 ��ȯ�ϴ� ����
treeThNode* findThreadSuccessor(treeThNode* p) {
	treeThNode* q = p->right; // q�� p�� ������ �ڽ� ��� ����
	if (q == NULL || p->isThreadRight == 1) return q; // ������ ������ ��ȯ(������ �ڽ� or �θ� == �����ļ���)
	while (q->left != NULL) q = q->left; // �������� ���� ��

	return q;
}

// ������ ���� Ʈ���� ���� ��ȸ
void threadInorder(treeThNode* root) {
	treeThNode* q;
	q = root; // Ʈ���� ��Ʈ���� ����
	while (q->left) // q�� ���� �ڽ��� ���� ������, �ܸ����� �̵��Ҷ�����
		q = q->left; // q�� ���� �ڽ����� �̵�

	do {
		printf("%3c", q->data); // data �ʵ� ���
		q = findThreadSuccessor(q); // q�� �����ļ��� ã�� �̵�
	} while (q);
}

int main1() {
	// (A*B-C/D) ���� ���� Ʈ�� �����
	treeThNode* n7 = makeRootThNode('D', NULL, NULL, 0); // �ܸ����
	treeThNode* n6 = makeRootThNode('C', NULL, NULL, 0); // �ܸ����
	treeThNode* n5 = makeRootThNode('B', NULL, NULL, 0); // �ܸ����
	treeThNode* n4 = makeRootThNode('A', NULL, NULL, 0); // �ܸ����
	treeThNode* n3 = makeRootThNode('/', n6, n7, 0);
	treeThNode* n2 = makeRootThNode('*', n4, n5, 0);
	treeThNode* n1 = makeRootThNode('-', n2, n3, 0);

	// ���� �ļ��� ���� ������Ʈ. ������ ���鶧 �־ ����,
	upThreadRight(n4, n3);
	upThreadRight(n5, n1);
	upThreadRight(n6, n3);

	// �̷��� �ص� ����
	//n4->right = n2;
	//n5->right = n1;
	//n6->right = n3;

	printf("\n ������ ���� Ʈ���� ���� ��ȸ : ");
	threadInorder(n1);

	return 0;
}