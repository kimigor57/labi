
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int SumIncrease(double a, double b , int n, double h, double cur);
int ResultOfSum(double a, double b, double cur, double prev, int n, double h,double e);

void main()
{
	double a, b, e;
	int n = 2;
	printf("Insert interval:\n");
	scanf_s("%lf%lf", &a, &b);
	printf("Insert E:\n");
	scanf_s("%lf", &e);
	double h = (b - a) / n;
	double cur = log(b) * (b - a);
	double prev = 0;
	ResultOfSum(a, b, cur, prev, n, h, e);
	printf("%lf", cur);

	getchar();
	getchar();
}


int SumIncrease(double a, double b , int n, double h, double cur)
{
	for (float i = a; i < b; i = i + h)
		{
		cur = cur + (log(i)+log(i+h)) / 2 * ((b - a) / n);
		}
	return cur;
}


int ResultOfSum(double a, double b, double cur, double prev, int n, double h,double e)
{
	while (abs(cur - prev) > e)
		{
		prev = cur;
		cur = 0;
		SumIncrease(a, b, n, h, cur);
		n++;
		}
	return cur;
}
