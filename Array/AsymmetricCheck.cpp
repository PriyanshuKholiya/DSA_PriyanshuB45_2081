#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
printf("Enter the elements of the matrix:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("Enter element [%d][%d]: ", i, j);
scanf("%d", &matrix[i][j]);
}
}
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
printf("Matrix:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("%d ", matrix[i][j]);
}
printf("\n");
}
}

int isAsymmetric(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
int transpose[MAX_ROWS][MAX_COLS];

for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
transpose[j][i] = matrix[i][j];
}
}

for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
if (matrix[i][j] != transpose[i][j]) {
return 1;
}
}
}

return 0;
}

int main() {
int matrix[MAX_ROWS][MAX_COLS];
int rows, cols;

printf("Enter the number of rows and columns of the matrix: ");
scanf("%d %d", &rows, &cols);

if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
printf("Invalid matrix dimensions.\n");
return 1;
}

inputMatrix(matrix, rows, cols);
printMatrix(matrix, rows, cols);

if (isAsymmetric(matrix, rows, cols)) {
printf("The matrix is asymmetric.\n");
} else {
printf("The matrix is symmetric.\n");
}

return 0;
}

