#include<stdio.h>

int Euclid(int a, int b);

int main(void)
{
	int result = 0;
	result = Euclid(24, 14);
	printf("두 정수의 최대공약수는 %d입니다.", result);
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