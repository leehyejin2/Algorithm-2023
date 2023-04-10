// �ǽ���: ������(202211284)

#include <stdio.h>

// ����� �ִ����� �˰���
int eucildRecursive(int a, int b)
{
	// 1. If(b = 0) return a  // �������� of ���ȣ��!
	if (b == 0) return a;

	// 2. return Euclid(b, a mod b)
	return eucildRecursive(b, a % b);
}

// �ݺ��� �ִ����� �˰���
int euclidRepetitive(int c, int d)
{
	// 1. �ӽñ��
	int bsav, tmp;

	// 2. if a < b return 0; // �Է�Ȯ��
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