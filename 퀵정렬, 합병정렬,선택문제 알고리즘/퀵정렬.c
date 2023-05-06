#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# define LEN 7
int arr[LEN] = {0};
void write_input();
void write_output();

void quickSort(int arr[], int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
      int temp;
      do
      {
        while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        if (left<= right)    // left가 right보다 왼쪽에 있다면 교환 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
            left++;
            right--;
        }
      } while (left<= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 
 
    /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 
 
    if (left < R)
        quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}
 
int main()
{
  int i;
  printf("정렬 할 배열 원소값 7개 입력\n: ");
  for (int i = 0; i < LEN; i++)
  {
      scanf("%d", &arr[i]);
  }

  write_input();

  printf("정렬 전 : ");
  for(i=0; i<LEN; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
    
  quickSort(arr, 0, LEN-1);

  printf("정렬 후 : ");
  for(i=0; i<LEN; i++){
    printf("%d ", arr[i]);
  }
  write_output();
  return 0; 
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