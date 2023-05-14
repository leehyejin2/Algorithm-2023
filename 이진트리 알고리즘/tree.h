#pragma once
typedef struct _Node {
	int value;
	Node* left;
	Node* right;
}Node;

extern Node* makeTree();
extern void printNode(Node* root);