#include<stdio.h>

int binary_search(int list[], int n, int search)
{
    int i, a;
    a = b;
    for (i = 0; i < n; i++) {
        if (list[a / 2] == search) {
            a = a / 2;
            return a;
        }
        else if (list[a / 2] < search)
            a += a / 2;
        else if (list[a / 2] > search)
            a = a / 2;
    }
    return -1;
}

int main(void)
{
    int i, num, search, bin;

    int list[] = { 1, 2, 5, 9, 15, 20, 26, 34, 44, 62 };

    printf("ã���� �ϴ� ���� �Է��ϼ���: ");
    scanf("%d", &search);
    bin = binary_search(list, 10, search);

    if (list[bin] == search) {
        printf("%d���� %d��°�� �ֽ��ϴ�.", list[bin], bin);
    }
    else {
        printf("%d���� �����ϴ�.", search);
    }

}