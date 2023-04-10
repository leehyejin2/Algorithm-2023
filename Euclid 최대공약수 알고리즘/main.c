// ���α׷� ����: Euclid �ִ����� �˰����� ����� ����� �ݺ��� ������� 2���� �Լ��� ���������ϴ� ���α׷�
// �ǽ���: 2023.04.09
// �ǽ���: ������(202211284)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int testEuclid();
//int testEuclid1();

int eucildRecursive(int a, int b);
int euclidRepetitive(int c, int d);

int main(void)
{
	clock_t start, end;
	double result;

	//int ret = 0;

	// 1. ����� �˰���
	start = clock(); // ���� �ð� ���� ����

	int gcd = 0, b, s;
	srand((unsigned)time(NULL));

	b = rand() % 10000; //rand() % (1100 + 1 - 1000) + 1000; �ſ� ū ��(1000�� �̻�)
	s = rand() % 10000; //rand() % (1100 + 1 - 1000) + 1000;
	gcd = eucildRecursive(b, s);

	printf("%d�� %d�� �ִ������� %d�Դϴ�.\n", b, s, gcd);

	end = clock(); // �ð� ���� ��
	result = (double)(end - start);

	printf("%f\n", result / CLOCKS_PER_SEC);

	// 2. �ݺ��� �˰���
	start = clock(); // ���� �ð� ���� ����

	int gcd1 = 0, a, g;
	srand((unsigned)time(NULL));

	a = rand() % 10000;
	g = rand() % 10000;

	gcd1 = euclidRepetitive(a, g);
	printf("%d�� %d�� �ִ������� %d�Դϴ�.\n", a, g, gcd1);

	end = clock(); // �ð� ���� ��
	result = (double)(end - start);

	printf("%f\n", result / CLOCKS_PER_SEC);

	//ret = testEuclid1();

}
