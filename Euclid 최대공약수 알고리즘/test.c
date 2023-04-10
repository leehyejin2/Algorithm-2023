// �ǽ���: ������(202211284)

#include <stdio.h>
#include "euclid.h"

int testEuclid()
{
	//printf("�ȳ��ϼ���. �׽�Ʈ�սô�.\n");

	//gcd = eucildRecursive(24, 12);
	//printf("%d�� %d�� �ִ������� %d�Դϴ�.\n", 24, 12, gcd);

	int gcd = 0, b, s;
	srand((unsigned)time(NULL));

	b = rand() % 1000;
	s = rand() % 1000;

	gcd = eucildRecursive(b, s);
	printf("%d�� %d�� �ִ������� %d�Դϴ�.\n", b, s, gcd);
	return 0;
}

int testEuclid1()
{
	int gcd = 0, a, b;
	srand((unsigned)time(NULL));

	a = rand() % 1000;
	b = rand() % 1000;

	gcd = euclidRepetitive(a,b);
	printf("%d�� %d�� �ִ������� %d�Դϴ�.\n", a, b, gcd);
	return 0;
}