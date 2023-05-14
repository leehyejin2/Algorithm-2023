#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tree.h"

int main(int argc, char* argv[])
{
	printf("Hello World! \n");

	Node* root = makeTree();
	printNode(root);

	_getch();
}