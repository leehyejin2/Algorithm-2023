#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

// Point 구조체 정의
typedef struct {
    int x;
    int y;
} Point;

Point points[MAX_POINTS]; // 점들의 좌표를 저장하는 배열
Point closest_pair[2]; // 최근접 쌍을 저장하는 배열

// 두 점 사이의 거리를 계산하는 함수
double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    FILE* input_file = fopen("data.txt", "r"); // 입력 파일 열기
    FILE* output_file = fopen("result.txt", "w"); // 출력 파일 열기

    int num_points = 0; // 점의 개수 초기화
    // 입력 파일에서 좌표 데이터 읽어들이기
    while (fscanf(input_file, "%d %d", &points[num_points].x, &points[num_points].y) == 2) {
        num_points++;
    }

    double min_dist = INFINITY; // 최소 거리 초기화
    // 이중 반복문을 사용하여 모든 점 쌍의 거리 계산
    for (int i = 0; i < num_points; i++) {
        for (int j = i + 1; j < num_points; j++) {
            double d = dist(points[i], points[j]);
            if (d < min_dist) { // 최소 거리 갱신
                min_dist = d;
                closest_pair[0] = points[i];
            }
        }
    }

    // 출력 파일에 최근접 쌍의 좌표 출력
    int closest_x = closest_pair[0].x;
    int closest_y = closest_pair[0].y;
    fprintf(output_file, "최근접 쌍: (%d, %d)\n", closest_x, closest_y);

    fclose(input_file); // 입력 파일 닫기
    fclose(output_file); // 출력 파일 닫기

    return 0;
}
