#include <stdio.h>
#include <stdlib.h>

//��� Ÿ�� ����
typedef struct _Node {
	int value;
	Node* left;
	Node* right;
}Node;

Node* root;

//��� �����Լ�
Node* createNode(int val)
{
	//1. sizeof(Node) malloc
	Node* pNode = (Node*)malloc(sizeof(Node));

	//2. �ʱ�ȭ: n->value = val, left, right (NULL)
	pNode->value = val;
	pNode->left = NULL;
	pNode->right = NULL;

	//3. ���� Node ��ü(����) ������ ��ȯ
	return pNode;
}
//Node* connetChild(Node* parent, Node* left, Node* right)
//{
//	if (parent == NULL) return NULL;
//	parent->left = left;
//	parent->right = right;
//	return parent;
//}

//Ʈ�� ���� �Լ�
Node* makeTree()
{
	Node* root = createNode(100);
	root->left = createNode(200);
	root->right = createNode(300);
	root->right->left = createNode(400);
	root->right->right = createNode(500);
	return root;
}

// ��ü ��� �� ��� �Լ�
void printNode(Node* root)
{
	if (root == NULL) return; //����Լ� ����

	printf("Node: %d", root->value);
	printNode(root->left);
	printNode(root->right);

}
void preorder(Node* root)
{
	if (root == NULL) return; //����Լ� ����

	printf("Node: %d", root->value);
	printNode(root->left);
	printNode(root->right);
}
void inorder(Node* root)
{
	if (root == NULL) return; //����Լ� ����

	printNode(root->left);
	printf("Node: %d", root->value);
	printNode(root->right);
}
void postorder(Node* root)
{
	if (root == NULL) return; //����Լ� ����

	printNode(root->left);
	printNode(root->right);
	printf("Node: %d", root->value);
}

//Ư�� ���� ã�� ����� ������ ��ȯ�ϴ� �Լ�
Node* findNode(Node* root, int val)
{
	while (root != NULL) {
		if (val == root->value) {
			return root;
		}
		else if (val < root->value) {
			findNode(root->left, val);
		}
		else findNode(root->right, val);
	}
	printf("���� ã�� �� �����ϴ�.");
	return root;
}
// ��带 Ʈ���� �����ϴ� �ڵ�
Node* insertLeftNode(Node* where, Node* new_node)
{
	if (where == NULL) {
		return new_node;
	}

	Node* temp = where->left;
	where->left = new_node;
	new_node->left = temp;

	return where;
}
Node* insertRightNode(Node* where, Node* new_node)
{
	if (where == NULL) {
		return NULL;
	}

	Node* temp = where->right;
	where->right = new_node;
	new_node->right = temp;

	return where;
}
