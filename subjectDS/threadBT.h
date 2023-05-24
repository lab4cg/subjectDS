#pragma once
typedef struct treeThNode {
	char data; // �������ʵ�
	struct treeThNode* left; // left link �ʵ�
	struct treeThNode* right; // right link �ʵ�
	int isThreadRight; // right link�� �ļ����ΰ�?
}treeThNode;
treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight);
treeThNode* findThreadSuccessor(treeThNode* p);
void threadInorder(treeThNode* root);
void upThreadRight(treeThNode* node, treeThNode* thRight);