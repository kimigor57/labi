#include <stdio.h> 
#include <math.h> 

void While(float x, float y, float i, float step); 
void For(float x, float y, float i, float step); 
void Dowhile(float x, float y, float i, float step); 
void function(float x); 

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

void function(float x) 
{ 
    float F;
    printf("+------------+------------+\n"); 
    printf("|"); 
        if (x != 0) 
        { 
            F = tan(x)*sqrt(x); 
            printf(" X = %.3f ", x); 
            printf("|"); 
            printf(" Y = %.3f ", F); 
            printf("|\n"); 
        } 
        else 
        { 
            printf(" X = %.3f ", x); 
            printf("|"); 
            printf(" None "); 
            printf("|\n"); 
        } 
    printf("+------------+------------+\n"); 

}

void Dowhile(float x, float y, float z, float step) 
{ 

    do 
    { 
        function(z); 
        z = z + step; 
    } while (z < y + 0.0001 && step != 0); 

} 

void For(float x, float y, float z, float step) 
{ 

    if (step != 0) 
    { 
    
        for (float z = x; z < y + 0.0001; z = z + step) 
        { 
    
            function(z);           
            
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
            function(z); 
            z = z + step; 
        } 
    } 
