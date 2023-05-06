#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
# define LEN 7
void merge(int a[], int low, int mid, int hight);
void mergeSort(int a[], int low, int hight);
int arr[LEN] = { 0 };
void write_input();
void write_output();

int main(void)
{

	int i;
	printf("���� �� �迭 ���Ұ� 7�� �Է�\n: ");
	for (int i = 0; i < LEN; i++)
	{
		scanf("%d", &arr[i]);
	}
	write_input();
	printf("���� �� : ");
	for (i = 0; i < LEN; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	mergeSort(arr, 0, 6 - 1);    //�迭�� ��Ҹ� �����ϴ� �Լ�

	printf("���� �� : ");
	for (i = 0; i < LEN; i++) {
		printf("%d ", arr[i]);
	}
	write_output();
	return 0;
}

void merge(int a[], int low, int mid, int hight)    //�и��� �迭 ���� �� ���� �Լ�
{
	int b[6];
	int i = low;        //���� ����
	int j = mid + 1;    //������ ����
	int k = 0;          //�迭 b�� �ε��� ��

	while (i <= mid && j <= hight)
	{
		if (a[i] <= a[j])        //�и��� ���� �迭�� ������ �迭 ��
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)             //������ ���� ���� �迭�� �ִٸ� �迭 b�� ���� ä���
		b[k++] = a[i++];
	while (j <= hight)           //������ ���� ������ �迭�� �ִٸ� �迭 b�� ���� ä���
		b[k++] = a[j++];
	k--;

	while (k >= 0)               //�迭 b ������ �迭 a ���뿡 �����
	{
		a[low + k] = b[k];
		k--;
	}
}
void mergeSort(int a[], int low, int hight)    //�迭�� ��Ҹ� �����ϴ� �Լ�
{

	int mid;
	if (low < hight)
	{
		mid = (low + hight) / 2;
		mergeSort(a, low, mid);            //���� �迭�� ��� �и�
		mergeSort(a, mid + 1, hight);      //������ �迭�� ��� �и�
		merge(a, low, mid, hight);         //�и��� �迭 ���� �� ���� �Լ�
	}
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