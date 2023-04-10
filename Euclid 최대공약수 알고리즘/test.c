// 실습자: 이혜진(202211284)

#include <stdio.h>
#include "euclid.h"

int testEuclid()
{
	//printf("안녕하세요. 테스트합시다.\n");

	//gcd = eucildRecursive(24, 12);
	//printf("%d와 %d의 최대공약수는 %d입니다.\n", 24, 12, gcd);

	int gcd = 0, b, s;
	srand((unsigned)time(NULL));

	b = rand() % 1000;
	s = rand() % 1000;

	gcd = eucildRecursive(b, s);
	printf("%d와 %d의 최대공약수는 %d입니다.\n", b, s, gcd);
	return 0;
}

int testEuclid1()
{
	int gcd = 0, a, b;
	srand((unsigned)time(NULL));

	a = rand() % 1000;
	b = rand() % 1000;

	gcd = euclidRepetitive(a,b);
	printf("%d와 %d의 최대공약수는 %d입니다.\n", a, b, gcd);
	return 0;
}