#include<stdio.h>
#include <math.h>
#define PI 3.141592654

int main()
{
	double x, y, result;
	y = -1;
	x = 1;
	result = atan2(y, x);
	result = result * 180.0 / PI;

	printf("Tangent inverse for(x = %.1lf, y = %.1lf) is %.1lf degrees.", x, y, result);
	return 0;
}