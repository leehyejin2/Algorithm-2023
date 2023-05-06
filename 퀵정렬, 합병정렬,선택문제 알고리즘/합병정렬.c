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
	printf("정렬 할 배열 원소값 7개 입력\n: ");
	for (int i = 0; i < LEN; i++)
	{
		scanf("%d", &arr[i]);
	}
	write_input();
	printf("정렬 전 : ");
	for (i = 0; i < LEN; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	mergeSort(arr, 0, 6 - 1);    //배열의 요소를 분할하는 함수

	printf("정렬 후 : ");
	for (i = 0; i < LEN; i++) {
		printf("%d ", arr[i]);
	}
	write_output();
	return 0;
}

void merge(int a[], int low, int mid, int hight)    //분리된 배열 정렬 및 병합 함수
{
	int b[6];
	int i = low;        //왼쪽 시작
	int j = mid + 1;    //오른쪽 시작
	int k = 0;          //배열 b의 인덱스 값

	while (i <= mid && j <= hight)
	{
		if (a[i] <= a[j])        //분리된 왼쪽 배열과 오른쪽 배열 비교
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)             //비교하지 않은 왼쪽 배열이 있다면 배열 b에 전부 채우기
		b[k++] = a[i++];
	while (j <= hight)           //비교하지 않은 오른쪽 배열이 있다면 배열 b에 전부 채우기
		b[k++] = a[j++];
	k--;

	while (k >= 0)               //배열 b 내용을 배열 a 내용에 덮어쓰기
	{
		a[low + k] = b[k];
		k--;
	}
}
void mergeSort(int a[], int low, int hight)    //배열의 요소를 분할하는 함수
{

	int mid;
	if (low < hight)
	{
		mid = (low + hight) / 2;
		mergeSort(a, low, mid);            //왼쪽 배열의 요소 분리
		mergeSort(a, mid + 1, hight);      //오른쪽 배열의 요소 분리
		merge(a, low, mid, hight);         //분리된 배열 정렬 및 병합 함수
	}
}
void write_input()
{
	FILE* input_file = fopen("data.txt", "w"); // 파일 열기
	if (input_file == NULL) // 파일 열기 실패시
	{
		return;
	}
	for (int i = 0; i < LEN; i++)
	{
		fprintf(input_file, "%d  ", arr[i]); // 정렬된 배열을 파일에 출력
	}
	fprintf(input_file, "\n");
	fclose(input_file); // 파일 닫기
}

// 정렬된 배열을 파일에 출력하는 함수
void write_output()
{
	FILE* output_file = fopen("result.txt", "w"); // 파일 열기
	if (output_file == NULL) // 파일 열기 실패시
	{
		return;
	}
	for (int i = 0; i < LEN; i++)
	{
		fprintf(output_file, "%d  ", arr[i]); // 정렬된 배열을 파일에 출력
	}
	fprintf(output_file, "\n");
	fclose(output_file); // 파일 닫기
}