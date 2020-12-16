#include <stdio.h>
#include <math.h>

float inputArray(float* array, int amount);
float findMini(float* array, int amount);
float findZero(float* array, int amount);
double avgGeom( int zero, int mini, float* array);

int main()
{
	float array[10000];
	int amount;
	printf("Insert number of elements:\n");
	scanf_s("%d", &amount);
	inputArray(array, amount);
	int min = findMini(array, amount);

	int zero = findZero(array, amount);


	printf("%lf",avgGeom(zero, min, array));
	getchar();
	getchar();
	
}

float inputArray(float *array,int amount)
{
	for (int i = 0; i < amount; i = i + 1)
	{
		scanf_s("%f", &array[i]);
	}
	return 0;
}

float findMini(float* array, int amount)
{
	float min = array[0];
	int mini = 0;
	for (int i = 0; i < amount; i = i + 1)
	{
		if (array[i] < min)
		{
			min = array[i];
			mini = i;
		}
	}
	return mini;
}

float findZero(float* array, int amount)
{
	int zero = 10000;
	for (int i = 0; i < amount; i = i + 1)
	{
		if (array[i] == 0)
			zero = i;
	}
	return zero;
}

double avgGeom(int zero, int mini,float* array)
{
	float multi = 1;
	float count=0;
	if (zero < mini)
	{
	for (int i = 0; i < zero; i = i + 1)
	{
		multi = multi * array[i];
		count = count + 1;
	}
	}
	else if (mini < zero)
	{
	for (int i = 0; i < mini; i = i + 1)
	{
		multi = multi * array[i];
		count = count + 1;
	}
	}
	return powf(multi,(1/count));
}

