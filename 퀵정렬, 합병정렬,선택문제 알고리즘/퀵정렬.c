#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# define LEN 7
int arr[LEN] = {0};
void write_input();
void write_output();

void quickSort(int arr[], int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2];    // pivot ���� (���) 
      int temp;
      do
      {
        while (arr[left] < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
            left++;
        while (arr[right] > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
            right--;
        if (left<= right)    // left�� right���� ���ʿ� �ִٸ� ��ȯ 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
            left++;
            right--;
        }
      } while (left<= right);    // left�� right ���� �����ʿ� ���� ������ �ݺ� 
 
    /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // ���� �迭 ��������� �ݺ� 
 
    if (left < R)
        quickSort(arr, left, R);    // ������ �迭 ��������� �ݺ� 
}
 
int main()
{
  int i;
  printf("���� �� �迭 ���Ұ� 7�� �Է�\n: ");
  for (int i = 0; i < LEN; i++)
  {
      scanf("%d", &arr[i]);
  }

  write_input();

  printf("���� �� : ");
  for(i=0; i<LEN; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
    
  quickSort(arr, 0, LEN-1);

  printf("���� �� : ");
  for(i=0; i<LEN; i++){
    printf("%d ", arr[i]);
  }
  write_output();
  return 0; 
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