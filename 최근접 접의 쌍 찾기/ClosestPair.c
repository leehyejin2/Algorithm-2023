#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

// Point ����ü ����
typedef struct {
    int x;
    int y;
} Point;

Point points[MAX_POINTS]; // ������ ��ǥ�� �����ϴ� �迭
Point closest_pair[2]; // �ֱ��� ���� �����ϴ� �迭

// �� �� ������ �Ÿ��� ����ϴ� �Լ�
double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    FILE* input_file = fopen("data.txt", "r"); // �Է� ���� ����
    FILE* output_file = fopen("result.txt", "w"); // ��� ���� ����

    int num_points = 0; // ���� ���� �ʱ�ȭ
    // �Է� ���Ͽ��� ��ǥ ������ �о���̱�
    while (fscanf(input_file, "%d %d", &points[num_points].x, &points[num_points].y) == 2) {
        num_points++;
    }

    double min_dist = INFINITY; // �ּ� �Ÿ� �ʱ�ȭ
    // ���� �ݺ����� ����Ͽ� ��� �� ���� �Ÿ� ���
    for (int i = 0; i < num_points; i++) {
        for (int j = i + 1; j < num_points; j++) {
            double d = dist(points[i], points[j]);
            if (d < min_dist) { // �ּ� �Ÿ� ����
                min_dist = d;
                closest_pair[0] = points[i];
            }
        }
    }

    // ��� ���Ͽ� �ֱ��� ���� ��ǥ ���
    int closest_x = closest_pair[0].x;
    int closest_y = closest_pair[0].y;
    fprintf(output_file, "�ֱ��� ��: (%d, %d)\n", closest_x, closest_y);

    fclose(input_file); // �Է� ���� �ݱ�
    fclose(output_file); // ��� ���� �ݱ�

    return 0;
}
