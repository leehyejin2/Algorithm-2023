#include <stdio.h>
int main(void)
{
    int coin[5] = { 500,100,50,10,5 };
    int change, i, count[5];

    printf("�Ž������� �Է��ϼ���: ");
    scanf("%d", &change);

    for (i = 0; i < 5; i++) {
        count[i] = change / coin[i];
        change = change % coin[i];
        printf("%d�� ���� = %d��\n", coin[i], count[i]);
    }
}