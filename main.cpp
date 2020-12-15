#include <math.h>
#include <malloc.h>
#include "stdio.h"


float inputArray(float* array, int size);
float group(float* array, int size);
float bubbleSort(float* array, int size);
float outputArray(float* array, int size);
int main()
{

	int size;
	printf("Insert number of elements:\n");
	scanf_s("%d", &size);
	float* array = (float*)malloc(size * sizeof(float));
	inputArray(array, size);
	bubbleSort(array, size);
	group(array, size);
	outputArray(array, size);
	getchar();
	getchar();
}

float inputArray(float* array, int size)
{
	for (int i = 0; i < size; i = i + 1)
	{
		scanf_s("%f", &array[i]);
	}
	return 0;
}

float bubbleSort(float *array, int size)
{
 
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = (size - 1); j > i; j--) 
    {
      if (array[j - 1] > array[j]) 
      {
        int temp = array[j - 1]; 
        array[j - 1] = array[j];
        array[j] = temp;
      }
    }
  }
  return 0;
}

float group(float* array, int size)
{
	int k=0;
	for (int i = 0; i < size; i = i + 1)
	{
		if (array[i] < 0)
			k=k+1;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		if (array[i] < 0)
		{
			float tmp;
			float tmp2 = array[i];
			float tmp1 = array[size - 1];
			for (int j = size - 2; j >= i; j--)
			{
				tmp = array[j];
				array[j] = tmp1;
				tmp1 = tmp;
			}
			array[size - 1] = tmp2;
		}
	}
	for (int i = size-k; i < size - 1; i++)
    {
		for (int j = (size - 1); j > i; j--) 
		{
			if (array[j - 1] > array[j]) 
			{
				int temp = array[j - 1]; 
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
    }
	return 0;
}



float outputArray(float* array, int size)
{
	for (int i = 0; i < size; i = i + 1)
	{
		printf("%.0f ", array[i]);
	}
	return 0;
}