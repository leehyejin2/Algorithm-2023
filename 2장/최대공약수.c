#include<stdio.h>

int Euclid(int a, int b);

int main(void)
{
	int result = 0;
	result = Euclid(24, 14);
	printf("�� ������ �ִ������� %d�Դϴ�.", result);
	return 0;
}

int Euclid(int a, int b) 
{
	int bsav = 0;

	while (b != 0) {
		bsav = b;
		b = a % b;
		a = bsav;
	}
	return a;
}