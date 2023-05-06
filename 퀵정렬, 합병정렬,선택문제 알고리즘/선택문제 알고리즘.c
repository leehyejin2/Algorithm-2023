#define _CRT_SECURE_NO_WARNINGS
# define LEN 7
#include <stdio.h>
#include <stdlib.h>
int arr[LEN] = { 0 };
int n = 7;
void Swap(int* a, int* b);
int Partition(int arr[], int left, int right);
int QuickSelect(int arr[], int left, int right, int select);
void write_input();
void write_output();

int main(void)
{
    int index; // n: arr size, k: index
    int* arr = NULL;

    printf("�� ��° ũ���� ���� : ");
    scanf_s("%d", &index);

    arr = (int*)malloc(sizeof(int) * n);

    printf("�迭 �Է� : ");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", (arr + i));
    }
    write_input();

    printf("%d ��° ũ���� ���� : %d\n", index, QuickSelect(arr, 0, n - 1, index));
    write_output();
    return 0;
}

/* Swap */
void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Partition */
int Partition(int arr[], int left, int right)
{
    // �⺻������ QuickSort�� Pivot ���� �� ��ȯ ������ ����
    // pivot�� ���� ������ �ε����� ����
    int pos = arr[left];
    int low = left + 1, high = right;
    while (low <= high)
    {
        while (low <= right && arr[low] <= pos)
        {
            low++;
        }
        while (high >= (left + 1) && arr[high] >= pos)
        {
            high--;
        }
        if (low <= high)
        {
            Swap(&arr[low], &arr[high]);
        }
    }
    Swap(&arr[left], &arr[high]);
    return high;
}

/* ���� ã�� �Լ� */
int QuickSelect(int arr[], int left, int right, int select)
{
    // ã���� �ϴ� �ε����� ���� ���� ������ ��,
    if (select > 0 && select <= right - left + 1)
    {
        int pos = Partition(arr, left, right);

        // ã���� �ϴ� ���ڸ� ã�� ���
        if (pos - left == select - 1)
        {
            return arr[pos];
        }
        // ã���� �ϴ� ���ڰ� small group�� �ִ� ���
        else if (pos - left > select - 1)
        {
            return QuickSelect(arr, left, pos - 1, select);
        }
        // ã���� �ϴ� ���ڰ� large group�� �ִ� ���
        else
        {
            return QuickSelect(arr, pos + 1, right, select - pos + left - 1);
        }
    }
    // Ž�� ���� ��,
    return -1;
}

void write_input()
{
    FILE* input_file = fopen("data.txt", "w"); // ���� ����
    if (input_file == NULL) // ���� ���� ���н�
    {
        return;
    }
    for (int i = 0; i < LEN; i++)
    {
        fprintf(input_file, "%d  ", arr[i]); // ���ĵ� �迭�� ���Ͽ� ���
    }
    fprintf(input_file, "\n");
    fclose(input_file); // ���� �ݱ�
}

// ���ĵ� �迭�� ���Ͽ� ����ϴ� �Լ�
void write_output()
{
    FILE* output_file = fopen("result.txt", "w"); // ���� ����
    if (output_file == NULL) // ���� ���� ���н�
    {
        return;
    }
    for (int i = 0; i < LEN; i++)
    {
        fprintf(output_file, "%d  ", arr[i]); // ���ĵ� �迭�� ���Ͽ� ���
    }
    fprintf(output_file, "\n");
    fclose(output_file); // ���� �ݱ�
}