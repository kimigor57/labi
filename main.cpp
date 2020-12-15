#include <stdio.h>
float GetPosition(float x, float y);
void main()
{
	float x;
	float y;
	printf("y = 2x + 2\n");
	printf("y = 0.5x - 1\n");
	printf("y = -x + 2\n");
	printf("Please insert coordinates of the point\n");
	scanf("%f%f", &x, &y);
	int p = GetPosition(x, y);
	switch (p)
	{
	    case 1:
		    printf("Point is placed in region 1");
			break;
		case 2:
			printf("Point is placed in region 2");
			break;
		case 3:
		    printf("Point is placed in region 3");
			break;
		case 4:
		    printf("Point is placed in region 4");
			break;
		case 5:
		    printf("Point is placed in region 5");
			break;
		case 6:
		    printf("Point is placed in region 6");
			break;
		case 7:
		    printf("Point is placed in region 7");
			break;
		case 10:
		    printf("Point is placed on line 1");
			break;
		case 20:
		    printf("Point is placed on line 2");
			break;
		case 30:
		    printf("Point is placed on line 3");
			break;
        case 12:
		    printf("Point is located at the intersection of lines 1 and 2");
			break;
		case 13:
		    printf("Point is located at the intersection of lines 1 and 3");
			break;
		case 23:
		    printf("Point is located at the intersection of lines 2 and 3");
			break;
	}

	getchar();
	getchar();
}

float a ( float x, float y )
{
	int g;
    if ( y - 2 * x - 2 > 0 )
		g = 1;
	if ( y - 2 * x - 2 < 0 )
		g = - 1;
	if ( y - 2 * x - 2 == 0 )
		g = 0;
	return g;
}

float b (float x, float y )
{
	int h;
    if (y - 0.5 * x + 1 > 0 )
		h = 1;
	if (y - 0.5 * x + 1< 0 )
		h = - 1;
	if (y - 0.5 * x + 1 == 0 )
		h = 0;
	return h;
}

float c ( float x, float y )
{
	int j;
    if (y + x - 2 > 0 )
		j = 1;
	if ( y + x - 2 < 0 )
		j = - 1;
	if (y + x - 2 == 0 )
		j = 0;
	return j;
}


float GetPosition(float x, float y)
{
	float f;
	if (( a(x , y) < 0 ) && ( b(x , y) > 0 ) && ( c(x , y) > 0 ))
		f = 1;
	else if (( a(x , y) < 0) && ( b(x , y) < 0 ) && ( c(x , y) > 0 ))
		f = 2;
	else if (( a(x , y) < 0 ) && ( b(x , y) < 0 ) && ( c(x , y) < 0 ))
		f = 3;
	else if ( (a(x , y) > 0) && ( b(x , y) < 0 ) && ( c(x , y) < 0 ))
		f = 4;
	else if ( (a(x , y) < 0 ) && ( b(x , y) < 0 ) && ( c(x , y) > 0 ))
		f = 5;
	else if ( (a(x , y) > 0 ) && ( b(x , y) > 0 ) && ( c(x , y) > 0 ))
		f = 6;
	else if ( (a(x , y) < 0 ) && ( b(x , y) > 0 ) && ( c(x , y) < 0 ))
		f = 7;
	else if ( (a(x , y) == 0 ) && (b(x , y) != 0) && ( c(x , y) != 0 ))
		f = 10;
	else if ( (a(x , y) != 0 ) && (b(x , y) == 0) && ( c(x , y) != 0 ))
		f = 20;
	else if (( a(x , y) != 0 ) && (b(x , y) != 0) && ( c(x , y) == 0 ))
		f = 30;
	else if (( a(x , y) == 0 ) && ( b(x , y) == 0 ))
		f = 12;
	else if (( a(x , y) == 0 ) && ( c(x , y) == 0 ))
		f = 13;
	else if (( b(x , y) == 0 ) && ( c(x , y) == 0 ))
		f = 23;
	return f;
}
