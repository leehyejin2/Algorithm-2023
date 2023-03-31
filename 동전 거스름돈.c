#include <stdio.h>
int main(void)
{
    int coin[5] = { 500,100,50,10,5 };
    int change, i, count[5];

    printf("거스름돈을 입력하세요: ");
    scanf("%d", &change);

    for (i = 0; i < 5; i++) {
        count[i] = change / coin[i];
        change = change % coin[i];
        printf("%d원 동전 = %d개\n", coin[i], count[i]);
    }
}