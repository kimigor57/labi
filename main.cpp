#include <stdio.h>
int Pos(float x, float y);
void main()
{
	float x;
	float y;
	printf("y = 2x + 2\n");
	printf("y = 0.5x - 1\n");
	printf("y = -x + 2\n");
	printf("Please insert coordinates of the point\n");
	scanf("%f%f", &x, &y);
	int p = Pos(x, y);
	if (p == 1)
		printf("Point is placed in region 1");
	else if (p == 2)
		printf("Point is placed in region 2");
	else if (p == 3)
		printf("Point is placed in region 3");
	else if (p == 4)
		printf("Point is placed in region 4");
	else if (p == 5)
		printf("Point is placed in region 5");
	else if (p == 6)
		printf("Point is placed in region 6");
	else if (p == 7)
		printf("Point is placed in region 7");
	else if (p == 10)
		printf("Point is placed on line 1");
	else if (p == 20)
		printf("Point is placed on line 2");
	else if (p == 30)
		printf("Point is placed on line 3");
	else if (p == 12)
		printf("Point is located at the intersection of lines 1 and 2");
	else if (p == 13)
		printf("Point is located at the intersection of lines 1 and 3");
	else if (p == 23)
		printf("Point is located at the intersection of lines 2 and 3");
	getchar();
	getchar();
}

int Pos(float x, float y)
{
	int f;
	if ( (y - 0.5 * x + 1 > 0) && (y + x - 2 > 0) && (y - 2 * x - 2 < 0) )
		f = 1;
	else if ( (y - 0.5 * x + 1 < 0) && (y + x - 2 > 0) && (y - 2 * x - 2 < 0) )
		f = 2;
	else if ( (y - 0.5 * x + 1 < 0) && (y + x - 2 < 0) && (y - 2 * x - 2 < 0) )
		f = 3;
	else if ( (y - 0.5 * x + 1 < 0) && (y + x - 2 < 0) && (y - 2 * x - 2 > 0) )
		f = 4;
	else if ( (y - 0.5 * x + 1 > 0) && (y + x - 2 < 0) && (y - 2 * x - 2 > 0) )
		f = 5;
	else if ( (y - 0.5 * x + 1 > 0) && (y + x - 2 > 0) && (y - 2 * x - 2 > 0) )
		f = 6;
	else if ( (y - 0.5 * x + 1 > 0) && (y + x - 2 < 0) && (y - 2 * x - 2 < 0) )
		f = 7;
	else if ( (y - 2 * x - 2 == 0) && (y - 0.5 * x + 1 != 0) && (y + x - 2 != 0) )
		f = 10;
	else if ( (y - 2 * x - 2 != 0) && (y - 0.5 * x + 1 == 0) && (y + x - 2 != 0))
		f = 20;
	else if ( (y - 2 * x - 2 != 0) && (y - 0.5 * x + 1 != 0) && (y + x - 2 == 0))
		f = 30;
	else if ( (y - 2 * x - 2 == 0) && (y - 0.5 * x + 1 == 0) )
		f = 12;
	else if ( (y - 2 * x - 2 == 0) && (y + x -2 == 0) )
		f = 13;
	else if ( (y - 0.5 * x + 1 == 0) && (y + x -2 == 0) )
		f = 23;
	return f;
}