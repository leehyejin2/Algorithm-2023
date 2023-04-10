// 실습자: 이혜진(202211284)

#include <stdio.h>

// 재귀적 최대공약수 알고리즘
int eucildRecursive(int a, int b)
{
	// 1. If(b = 0) return a  // 종료조건 of 재귀호출!
	if (b == 0) return a;

	// 2. return Euclid(b, a mod b)
	return eucildRecursive(b, a % b);
}

// 반복적 최대공약수 알고리즘
int euclidRepetitive(int c, int d)
{
	// 1. 임시기억
	int bsav, tmp;

	// 2. if a < b return 0; // 입력확인
	if (c < d) {
		tmp = c;
		c = d;
		d = tmp;
	}

	// 3. while (b!=0)
	// 4. {
	//      bsav = b
	//      b = a mod b
	//      a = bsav
    //    }
	while (d != 0)
	{
		bsav = d;
		d = c % d;
		c = bsav;
	}

	// 5. return a
	return c;
}