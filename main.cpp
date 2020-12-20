#include <malloc.h>;
#include <math.h>;
#include <stdio.h>


int** allocate(int lines, int columns);
void inputMatrix(int** matrix, int lines, int columns);
void outputMatrix(int** matrix, int lines, int columns);
int snakeSort(int** matrix, int* tempArray, int lines, int columns);
void evenLines(int** matrix, int lines, int columns, int i, int j);
void oddLines(int** matrix, int lines, int columns, int i, int j);

int main()
{
	int lines, number, distance, columns;
	int** matrix;
	printf("input number of lines:\n");
	scanf_s("%d", &lines);
	printf("input number of columns:\n");
	scanf_s("%d", &columns);
	allocate(lines, columns);
	matrix = allocate(lines, columns);
	int* tempArray = (int*)malloc(lines * sizeof(int));
	inputMatrix(matrix, lines, columns);
	snakeSort(matrix, tempArray, lines, columns);
	outputMatrix(matrix, lines, columns);
	getchar();
	getchar();
}

int** allocate(int lines, int columns)
{
	int* array = (int*)malloc(lines * columns * sizeof(int));
	int** matrix = (int**)malloc(lines * sizeof(int*));
	for (int i = 0; i < lines; i++)
	{
		matrix[i] = array + i * columns;
	}
	return matrix;
}

int snakeSort(int** matrix, int* tempArray, int lines, int columns)
{
	for (int k = 0; k < lines * columns; k++)
	{
		for (int i = 0; i < lines; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{	
				if (i % 2 == 0)
				{
					evenLines(matrix, lines, columns, i, j);
				}
				else 
				{
					oddLines(matrix, lines, columns, i, j);
				}
			}
		}
	}
	return 0;
}

void evenLines(int** matrix,int lines,int columns,int i, int j)
{
	if (j != columns - 1)
	{
		if (matrix[i][j + 1] < matrix[i][j])
		{
			int tmp = matrix[i][j + 1];
			matrix[i][j + 1] = matrix[i][j];
			matrix[i][j] = tmp;
		}
	}
	else
	{
		if (i != lines - 1)
		{
			if ((matrix[i + 1][columns - 1] < matrix[i][j]))
			{
				int tmp = matrix[i + 1][columns - 1];
				matrix[i + 1][columns - 1] = matrix[i][j];
				matrix[i][j] = tmp;
			}
		}
	}
}
void oddLines(int** matrix, int lines, int columns, int i, int j)
{
	if (j != 0)
	{
		if (matrix[i][columns - j - 1] < matrix[i][columns - j])
		{
			int tmp = matrix[i][columns - j - 1];
			matrix[i][columns - j - 1] = matrix[i][columns - j];
			matrix[i][columns - j] = tmp;
		}
	}
	else
	{
		if (i != lines - 1)
		{
			if ((matrix[i + 1][0] < matrix[i][j]))
			{
				int tmp = matrix[i + 1][0];
				matrix[i + 1][0] = matrix[i][j];
				matrix[i][j] = tmp;
			}
		}
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