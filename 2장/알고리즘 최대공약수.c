#include<stdio.h>

int main(int argc, char* argv[])
{
	test1_euclid();
}

int test1_euclid() // �׽�Ʈ �Լ�
{
	int gcd = 0;

	gcd = euclid(34, 48);
	printf("Hello World! %d\n", gcd);

	return 0;
}

int euclid(int a, int b)
{
	//1. if(b=0) return a // �������� of ���ȣ��
	if (b == 0) return a;

	//2. return Euclid(b, a mod b)
	return euclid(b, a % b);
}