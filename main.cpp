#include <math.h>
#include <conio.h>
#include <stdio.h>
 
 
double fact (int n)
{
  return (n < 2) ? 1 : n * fact (n - 1);
}

double f(int k)
{
    double res;
    res =1/fact(k)	 ;
    return res;
}

int main()
{
    float e;
    printf("E = ");
    scanf_s("%f", &e);
    double previous, current;
    double sum = 0;
    int k = 1;
    current = f(k);
    sum += current;
    k++;
    do
    {
        previous = current;
        current = f(k);
        sum += current;
        k++;
    } while (abs(current - previous) > e);
 
    printf("S = %f\n", sum);
 
    _getch();
 
    return 0;
}

