#pragma once
typedef struct treeThNode {
	char data; // 데이터필드
	struct treeThNode* left; // left link 필드
	struct treeThNode* right; // right link 필드
	int isThreadRight; // right link가 후속자인가?
}treeThNode;
treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight);
treeThNode* findThreadSuccessor(treeThNode* p);
void threadInorder(treeThNode* root);
void upThreadRight(treeThNode* node, treeThNode* thRight);