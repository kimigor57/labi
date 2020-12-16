#include <stdio.h> 
#include <math.h> 

void While(float x, float y, float i, float step); 
void For(float x, float y, float i, float step); 
void Dowhile(float x, float y, float i, float step); 
float function(float x); 

int main() 
{ 
    float x, y; 
    int N; 
    printf("Insert interval:\n"); 
    scanf_s("%f%f", &x, &y); 
    printf("Insert N:\n"); 
    scanf_s("%d", &N); 
    float step = (y - x) / N; 
    float z = x; 
    While(x, y, z, step); 
    For(x, y, z, step); 
    Dowhile(x, y, z, step); 
	getchar();
	getchar();
	return 0;
} 


float function(float x) 
{ 
    float F;
        if (x != 0) 
        {
            F = tan(x)*sqrt(x); 
        } 
        else 
        { 
            printf(" None "); 
        } 
	return F;
}

void header(float x)
{
 	printf("    X         Y\n");
    	printf("+--------+--------+\n"); 
}

void table (float x)
{
	printf("| %.3f  ", x); 
	printf("| %.3f |\n", function(x));
}

void end(int x)
{
	printf("+--------+--------+\n"); 
}

void Dowhile(float x, float y, float z, float step) 
{ 

    do 
    { 
		header(x);
        table(z); 
        z = z + step; 
		end(x);
    } while (z < y + 0.0001 && step != 0); 

} 

void For(float x, float y, float z, float step) 
{ 

    if (step != 0) 
    { 

        for (float z = x; z < y + 0.0001; z = z + step) 
        { 
			header(x);
            table(z);           
			end(x);
        } 
    } 
    else 
    { 
        printf("Step = 0 "); 
    } 
}

void While(float x, float y, float z, float step) 
    { 

        while (z < y + 0.0001 && step != 0) 
        { 
			header(x);
            table(z); 
            z = z + step; 
			end(x);
        } 
    } 
