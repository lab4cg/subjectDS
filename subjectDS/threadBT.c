#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

// data를 루트노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight) {
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));

	if (root == NULL) { // 메모리 동적할당 실패
		printf("memory allocation failed\n");
		exit(1);
	}

	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;

	return root;
}

// 중위 후속자 정보 업데이트 하는 연산
void upThreadRight(treeThNode* node, treeThNode* thRight) {
	node->right = thRight; // node의 중위후속자는 thRight
	node->isThreadRight = 1; // 오른쪽 포인터가 중위후속자임을 알려주는 정보 업데이트
}

// 후속자 노드를 반환하는 연산
treeThNode* findThreadSuccessor(treeThNode* p) {
	treeThNode* q = p->right; // q에 p의 오른쪽 자식 노드 저장
	if (q == NULL || p->isThreadRight == 1) return q; // 오른쪽 포인터 반환(오른쪽 자식 or 부모 == 중위후속자)
	while (q->left != NULL) q = q->left; // 왼쪽으로 깊이 감

	return q;
}

// 스레드 이진 트리의 중위 순회
void threadInorder(treeThNode* root) {
	treeThNode* q;
	q = root; // 트리의 루트부터 시작
	while (q->left) // q의 왼쪽 자식이 없을 때까지, 단말노드로 이동할때까지
		q = q->left; // q의 왼쪽 자식으로 이동

	do {
		printf("%3c", q->data); // data 필드 출력
		q = findThreadSuccessor(q); // q의 중위후속자 찾아 이동
	} while (q);
}

int main1() {
	// (A*B-C/D) 수식 이진 트리 만들기
	treeThNode* n7 = makeRootThNode('D', NULL, NULL, 0); // 단말노드
	treeThNode* n6 = makeRootThNode('C', NULL, NULL, 0); // 단말노드
	treeThNode* n5 = makeRootThNode('B', NULL, NULL, 0); // 단말노드
	treeThNode* n4 = makeRootThNode('A', NULL, NULL, 0); // 단말노드
	treeThNode* n3 = makeRootThNode('/', n6, n7, 0);
	treeThNode* n2 = makeRootThNode('*', n4, n5, 0);
	treeThNode* n1 = makeRootThNode('-', n2, n3, 0);

	// 중위 후속자 정보 업데이트. 위에서 만들때 넣어도 무방,
	upThreadRight(n4, n3);
	upThreadRight(n5, n1);
	upThreadRight(n6, n3);

	// 이렇게 해도 무방
	//n4->right = n2;
	//n5->right = n1;
	//n6->right = n3;

	printf("\n 스레드 이진 트리의 중위 순회 : ");
	threadInorder(n1);

	return 0;
}