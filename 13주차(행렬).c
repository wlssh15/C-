#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 100
#define COL 100

void input2DArray(int array[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) array[i][j] = rand() % 1000;
	}
}

void print2DArray(int array[][100], int row, int col) {
	printf("=======================================\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) printf("[%4d]", array[i][j]);
		printf("\n");
	}
}

void addmatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) target[i][j] = s1[i][j] + s2[i][j];
	}
}

void submatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) target[i][j] = s1[i][j] - s2[i][j];
	}
}


void mulmatrix(int s1[][100], int s2[][100], int target[][100], int row1, int col1, int col2) {
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			target[i][j] = 0;
			for (int k = 0; k < col1; k++) {
				target[i][j] += s1[i][k] * s2[k][j];
			}
		}
	}
}

int main()
{
	int matrix1[ROW][COL];
	int matrix2[ROW][COL];
	int result[ROW][COL];
	int row1, col1, row2, col2;
	srand(time(NULL));

	printf("Matrix1: ");
	scanf_s("%d %d", &row1, &col1);

	printf("Matrix2: ");
	scanf_s("%d %d", &row2, &col2);

	if (col1 != row2) {
		printf("NO\n");
		return 1;
	}

	input2DArray(matrix1, row1, col1);
	input2DArray(matrix2, row2, col2);

	mulmatrix(matrix1, matrix2, result, row1, col1, col2);

	printf("Matrix 1:\n");
	print2DArray(matrix1, row1, col1);

	printf("Matrix 2:\n");
	print2DArray(matrix2, row2, col2);

	printf("Result of Multiplication:\n");
	print2DArray(result, row1, col2);

	return 0;
}
