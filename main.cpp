#include <stdio.h>;
#include <math.h>;
#include <malloc.h>


int** allocate(int lines, int columns);
void inputMatrix(int** matrix, int lines, int columns);
void outputMatrix(int** matrix, int lines, int columns);
void transport(int** matrix, int lines, int columns);
void swapMinMax(int** matrix, int lines, int columns);
void tallMatrix(int** matrix, int lines, int  columns, int square);
void longMatrix(int** matrix, int lines, int columns, int square);
void squaredMatrix(int** matrix, int lines, int columns, int square);


int main()
{
	int lines, number, distance, columns;
	int** matrix;
	printf("input number of lines:\n");
	scanf_s("%d", &lines);
	printf("input number of columns:\n");
	scanf_s("%d", &columns);

	allocate( lines, columns);
	matrix= allocate(lines, columns);
	inputMatrix(matrix, lines, columns);
	outputMatrix(matrix, lines, columns);
	transport( matrix,lines,columns);
	outputMatrix(matrix, lines, columns);	
	getchar();
	getchar();
}

int** allocate(int lines, int columns)
{
	int* array = (int*) malloc(lines * columns * sizeof(int));
	int** matrix = (int**)malloc(lines * sizeof(int*));
	for (int i = 0; i < lines; i++)
	{
		matrix[i] = array + i * columns;
	}
	return matrix;
}
void inputMatrix(int** matrix, int lines, int columns)
{
	for (int i = 0; i < lines; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			scanf_s("%d", &matrix[i][j]);
		}
		printf("\n");
	}
}
void outputMatrix(int** matrix, int lines, int columns)
{
	for (int i = 0; i < lines; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}
void tallMatrix(int** matrix, int lines, int  columns, int square)
{
	
	for (int i = square; i < lines; ++i)
		for (int j = 0; j < columns - i + square; ++j)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[lines - j - 1][columns - i - 1 + square];
			matrix[lines - j - 1][columns - i - 1 + square] = tmp;
		}
	
}
void longMatrix(int** matrix, int lines, int columns, int square)
{
	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < columns - i - square; ++j)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[lines - j - 1][columns - i - 1 - square];
			matrix[lines - j - 1][columns - i - 1 - square] = tmp;
		}
}
void squaredMatrix(int** matrix, int lines, int columns, int square)
{
	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < columns - i; ++j)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[lines - j - 1][columns - i - 1];
			matrix[lines - j - 1][columns - i - 1] = tmp;
		}
}
void transport(int** matrix, int lines, int columns)
{
	int square = abs(lines - columns);
	if (lines < columns)
	{
		longMatrix(matrix, lines, columns, square);
	}

	else if (lines > columns) 
	{
		tallMatrix(matrix, lines, columns, square);
	}
	else
	{
		squaredMatrix(matrix, lines, columns, square);	
	}
}

