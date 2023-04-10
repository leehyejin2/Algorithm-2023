// 프로그램 내용: Euclid 최대공약수 알고리즘을 재귀적 방법과 반복적 방법으로 2가지 함수로 각각구현하는 프로그램
// 실습일: 2023.04.09
// 실습자: 이혜진(202211284)

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

	// 1. 재귀적 알고리즘
	start = clock(); // 수행 시간 측정 시작

	int gcd = 0, b, s;
	srand((unsigned)time(NULL));

	b = rand() % 10000; //rand() % (1100 + 1 - 1000) + 1000; 매우 큰 수(1000개 이상)
	s = rand() % 10000; //rand() % (1100 + 1 - 1000) + 1000;
	gcd = eucildRecursive(b, s);

	printf("%d와 %d의 최대공약수는 %d입니다.\n", b, s, gcd);

	end = clock(); // 시간 측정 끝
	result = (double)(end - start);

	printf("%f\n", result / CLOCKS_PER_SEC);

	// 2. 반복적 알고리즘
	start = clock(); // 수행 시간 측정 시작

	int gcd1 = 0, a, g;
	srand((unsigned)time(NULL));

	a = rand() % 10000;
	g = rand() % 10000;

	gcd1 = euclidRepetitive(a, g);
	printf("%d와 %d의 최대공약수는 %d입니다.\n", a, g, gcd1);

	end = clock(); // 시간 측정 끝
	result = (double)(end - start);

	printf("%f\n", result / CLOCKS_PER_SEC);

	//ret = testEuclid1();

}
