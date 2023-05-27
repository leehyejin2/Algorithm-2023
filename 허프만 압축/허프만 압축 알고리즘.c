/*
배열의 최대 크기를 MAX 매크로로 일정하게 정의
문자열 함수를 사용하는 string 헤더, 동적할당 malloc을 사용하기 위해 stdlib 헤더를 불러옴.
*/

#define MAX 99999
#define ASCII_SIZE 128
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
허프만 트리 안에 들어갈 심볼과 빈도 정보를 담은 노드를 정의
*/
typedef struct nodetype* nodepointer;
typedef struct nodetype
{
	char symbol;
	int frequency;
	nodepointer left;
	nodepointer right;
}node;


/* 우선순위 큐를 구현하기 위한 최소 힙. */
nodepointer heap[MAX];
int size = 0;
nodepointer root = NULL;


/* ASCII 표현할 수 있는 허프만 코드*/
char huffmanCode[ASCII_SIZE][MAX];

void fileCompress(FILE* fp, char* outputHuf);
void fileDecompress(FILE* fp, FILE* outputFile);

void push(nodepointer item);
nodepointer pop();
void Huffmancode(nodepointer node, char code[]);
void write_input();
void ascii();
double calculateCompressionRatio();

int main()
{
	/*
파일 열기. in = 압축할 텍스트 파일, out = 압축 결과 출력 & 복원할 텍스트 파일
압축할 파일은 읽기만 해서 r모드로, 입출력 모두 하는 파일은 w+모드로 열기
*/

	write_input();
	ascii();


	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w+");


	/* 파일 열기 오류 처리 */
	if (!in || !out)
	{
		printf("파일 열기 실패!\n");
		exit(1);
	}
	else
		printf("파일 열기 성공!\n");

	fileCompress(in, "output.txt");
	fileDecompress(out, stdout);

	fclose(in);
	fclose(out);

	double compressionRatio = calculateCompressionRatio();
	printf("\n압축률: %.2f\n", compressionRatio);

	return 0;
}


/* fp가 가리키는 파일을 압축하여 이름이 outputHuf인 파일을 생성한다. */
void fileCompress(FILE* fp, char* outputHuf)
{
	/* 정의 */
		/* 2차원 문자열로 for 연산을 할 때 runtime error 가 발생하여 동적할당으로 입출력 텍스트배열 선언함*/
	char* filetxt = (char*)malloc(sizeof(char) * 10000);
	char* output = (char*)malloc(sizeof(char) * 10000);
	char code[MAX] = { NULL };
	nodepointer temp_node;
	char c;
	int freq;
	int len = 0;
	FILE* cmp = fopen(outputHuf, "w");

	/* 1. 압축할 문자열을 불러온다 */
	do {
		c = fgetc(fp);
		filetxt[len++] = c;
	} while (c != EOF);

	/* 2. 문자열의 문자의 빈도수를 구한다 */
	/* 3. 빈도수에 따라 우선순위 큐(priority queue)를 만든다. */
	for (int i = 0; i < 128; i++)
	{
		freq = 0;
		temp_node = (nodepointer)malloc(sizeof(node));
		do {
			c = fgetc(fp);
			if (c == i) freq++;
		} while (c != EOF);
		fseek(fp, 0L, SEEK_SET);
		if (freq != 0)
		{
			temp_node->symbol = i;
			temp_node->frequency = freq;
			temp_node->left = NULL;
			temp_node->right = NULL;
			push(temp_node);
		}

	}
	fclose(fp);

	/* 4. 우선순위 큐로부터 호프만 트리를 만든다. */
	int n = size;
	for (int i = 1; i < n; i++)
	{
		nodepointer r = (nodepointer)malloc(sizeof(node));
		nodepointer p = pop();
		nodepointer q = pop();
		r->symbol = NULL;
		r->left = p;
		r->right = q;
		r->frequency = p->frequency + q->frequency;
		push(r);
	}
	root = pop();

	/* 5. 호프만 트리로부터 호프만 코드 배열을 만든다. */
	Huffmancode(root, code);

	/* 6. 호프만 코드에 따라 각 문자열을 압축한다. */
	/* 7. 압축한 문자열들을 차례로 파일에 저장한다.*/
	for (int j = 0; j < len; j++)
	{
		strcpy(output, huffmanCode[filetxt[j]]);
		if (fputs(output, cmp) != -1);
		else printf("압축 실패!");
		fputc('\n', cmp);
	}
	fclose(cmp);

	/* 8. 사용한 메모리를 반환해준다. */
	free(filetxt);
	free(output);
	free(temp_node);
}

/* fp가 가리키는 파일을 해독하여 원래 파일을 복원한다.*/
void fileDecompress(FILE* fp, FILE* outputFile)
{
	/* 정의 */
	char* filetxt = (char*)malloc(sizeof(char) * 10000);
	char* output = (char*)malloc(sizeof(char) * 10000);
	char c;
	int freq;
	int len = 0;
	int cnt = 0;
	nodepointer curr = root;

	/* 1. 복원할 문자열을 불러온다. */
	do {
		c = fgetc(fp);
		filetxt[len++] = c;
	} while (c != EOF);

	/* 6. 호프만 코드에 따라 문자열을 복원한다. */
	for (int i = 0; i < len; i++)
	{
		//null일수도있어서 두개로 검사
		if (filetxt[i] == '0') curr = curr->left;
		else if (filetxt[i] == '1') curr = curr->right;

		if (!curr->left && !curr->right)
		{
			output[cnt++] = curr->symbol;
			curr = root;
		}
	}
	output[cnt] = '\0';

	/* 7. 복원한 문자열을 차례로 파일에 저장한다. */
	fputc('\n', stdout);
	if (fputs(output, fp) != -1) {
		fprintf(outputFile, "%s", output);
	}
	else printf("압축 실패!");
	fclose(fp);

	/* 8. 사용한 메모리를 반환해준다. */
	free(filetxt);
	free(output);
}

void push(nodepointer item)
{
	/* 힙은 index 1부터 채워 나간다.
	1. push할 노드 item의 우선순위가 부모노드보다 높을때 자리를 바꾼다.
	2. 부모노드쪽으로 올라가며 index가 1이 되기 전까지 반복한다.
	3. 최종적으로 정해진 index에 item을 삽입한다.
	*/

	int i = ++size;
	while ((i != 1) && (item->frequency < heap[i / 2]->frequency))
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;

}

nodepointer pop()
{

	/* 첫번째 노드를 반환하고 삭제하는 함수
	1.첫번째 노드를 item에 저장, 마지막 노드를 temp에 저장 후, 힙의 size를 줄인다.
	2.재정렬을 하기 위해 첫번째 노드를 부모로, 왼편 자식노드를 child로 초기 설정
	3.비어있는 첫번째 노드를 자식이 채우며 최종노드쪽으로 내려간다.
	4.매 노드마다 현재 위치가 최종노드인지, 다음 분기 할 주소가 오른편 자식인지,
	왼쪽자식인지 판단, 그리고 마지막 노드와 우선순위를 비교한다.
	5.첫번째 노드를 반환하고 종료 */

	nodepointer item = heap[1];
	nodepointer temp = heap[size--];

	int parent = 1, child = 2;
	while (child <= size)
	{
		if ((child < size) && heap[child]->frequency > heap[child + 1]->frequency)
			child++;
		if (temp->frequency <= heap[child]->frequency)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

void Huffmancode(nodepointer node, char code[])
{
	/* 재귀를 이용한 허프만 코드 생성 함수
	1. 탐색할 노드가 NULL이면 종료.
	2. 매개변수로 받은 code를 temp에 복사
	3. 노드에 symbol이 존재하면 huffmanCode배열에 code를 복사 +) 모니터에도 출력
	4. 왼쪽 노드로 함수를 호출하면 code에 0을, 오른쪽 노드로 호출하면 1을 덧붙임(strcat)
	*/
	if (node == NULL)
		return;

	char tmp[MAX] = { NULL };

	strcpy(tmp, code);

	if (node->symbol)
	{
		strcpy(huffmanCode[node->symbol], code);
		printf("%c:%s\n", node->symbol, huffmanCode[node->symbol]);
	}

	Huffmancode(node->left, strcat(code, "0"));
	strcpy(code, tmp);
	Huffmancode(node->right, strcat(code, "1"));

}

void ascii() {
	// 빈도수를 저장할 배열 초기화
	int frequencies[ASCII_SIZE] = { 0 };

	// input.txt 파일 열기
	FILE* inputFile = fopen("input.txt", "r");
	if (inputFile == NULL) {
		printf("input.txt 파일을 열 수 없습니다.\n");
		return 1;
	}

	// ASCII 글자별 빈도수 계산
	int ch;
	while ((ch = fgetc(inputFile)) != EOF) {
		if (ch >= 0 && ch < ASCII_SIZE) {
			frequencies[ch]++;
		}
	}

	// input.txt 파일 닫기
	fclose(inputFile);

	// stats.txt 파일 열기
	FILE* statsFile = fopen("stats.txt", "w");
	if (statsFile == NULL) {
		printf("stats.txt 파일을 열 수 없습니다.\n");
		return 1;
	}

	// 빈도수를 stats.txt 파일에 저장
	for (int i = 0; i < ASCII_SIZE; i++) {
		if (frequencies[i] > 0) {
			fprintf(statsFile, "%d\t%d\n", i, frequencies[i]);
		}
	}

	// stats.txt 파일 닫기
	fclose(statsFile);

	printf("빈도수가 계산되어 stats.txt 파일에 저장되었습니다.\n");

	// 우선순위 큐에 노드 삽입
	for (int i = 0; i < ASCII_SIZE; i++) {
		if (frequencies[i] > 0) {
			nodepointer temp_node = (nodepointer)malloc(sizeof(node));
			temp_node->symbol = i;
			temp_node->frequency = frequencies[i];
			temp_node->left = NULL;
			temp_node->right = NULL;
			push(temp_node);
		}
	}

	// 우선순위 큐로부터 허프만 트리 재구성
	int n = size;
	for (int i = 1; i < n; i++) {
		nodepointer r = (nodepointer)malloc(sizeof(node));
		nodepointer p = pop();
		nodepointer q = pop();
		r->symbol = NULL;
		r->left = p;
		r->right = q;
		r->frequency = p->frequency + q->frequency;
		push(r);
	}
	nodepointer root = pop();

	return root;
}

void write_input() {
	// 압축할 문자열
	char input[] = "This is a sample input string.";

	// 입력 파일을 열기 (쓰기 모드)
	FILE* fp = fopen("input.txt", "w");

	// 파일 열기 오류 처리
	if (!fp) {
		printf("파일 열기 실패!\n");
		return 1;
	}

	// 문자열을 파일에 쓰기
	fprintf(fp, "%s", input);
	// 파일 닫기
	fclose(fp);

	return 0;
}

double calculateCompressionRatio()
{
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "r");

	if (!input || !output)
	{
		printf("파일 열기 실패!\n");
		return -1;
	}

	// input.txt 파일 크기 계산
	fseek(input, 0, SEEK_END);
	long inputSize = ftell(input);

	// output.txt 파일 크기 계산
	fseek(output, 0, SEEK_END);
	long outputSize = ftell(output);

	// 압축률 계산
	double compressionRatio = (double)outputSize / (double)inputSize;

	fclose(input);
	fclose(output);

	return compressionRatio;
}
