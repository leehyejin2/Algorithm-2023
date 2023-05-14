#include <stdio.h>
#include <stdlib.h>

//노드 타입 선언
typedef struct _Node {
	int value;
	Node* left;
	Node* right;
}Node;

Node* root;

//노드 생성함수
Node* createNode(int val)
{
	//1. sizeof(Node) malloc
	Node* pNode = (Node*)malloc(sizeof(Node));

	//2. 초기화: n->value = val, left, right (NULL)
	pNode->value = val;
	pNode->left = NULL;
	pNode->right = NULL;

	//3. 만든 Node 객체(변수) 포인터 반환
	return pNode;
}
//Node* connetChild(Node* parent, Node* left, Node* right)
//{
//	if (parent == NULL) return NULL;
//	parent->left = left;
//	parent->right = right;
//	return parent;
//}

//트리 생성 함수
Node* makeTree()
{
	Node* root = createNode(100);
	root->left = createNode(200);
	root->right = createNode(300);
	root->right->left = createNode(400);
	root->right->right = createNode(500);
	return root;
}

// 전체 노드 값 출력 함수
void printNode(Node* root)
{
	if (root == NULL) return; //재귀함수 조건

	printf("Node: %d", root->value);
	printNode(root->left);
	printNode(root->right);

}
void preorder(Node* root)
{
	if (root == NULL) return; //재귀함수 조건

	printf("Node: %d", root->value);
	printNode(root->left);
	printNode(root->right);
}
void inorder(Node* root)
{
	if (root == NULL) return; //재귀함수 조건

	printNode(root->left);
	printf("Node: %d", root->value);
	printNode(root->right);
}
void postorder(Node* root)
{
	if (root == NULL) return; //재귀함수 조건

	printNode(root->left);
	printNode(root->right);
	printf("Node: %d", root->value);
}

//특정 값을 찾는 노드의 포인터 반환하는 함수
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
	printf("값을 찾을 수 없습니다.");
	return root;
}
// 노드를 트리에 삽입하는 코드
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
