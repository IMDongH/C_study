#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#define PI 3.141592654

double angle(struct points);
void sortA(struct points*, int);
int ccw(point, point, point);
double circumF(struct points*, int);
double circum(point, point);	

typedef struct points {
	double x;
	double y;
	double angle;
}point;
void main()
{
	int caseN = 0;
	int pointN = 0;
	point* input;
	point* sort;
	point zero;
	zero.x = 0;
	zero.y = 0;
	zero.angle = 0;
	point* stk;
	printf("Type case number : ");
	scanf("%d", &caseN);
	printf("Type point number : ");
	scanf("%d", &pointN);
	stk = malloc(sizeof(point) * (pointN + 1));
	input = malloc(sizeof(point) * pointN);
	sort = malloc(sizeof(point) * pointN);
	while (caseN > 0)
	{
		for (int i = 0; i < pointN; i++)
		{
			scanf("%lf %lf", &input[i].x, &input[i].y);
			input[i].angle = angle(input[i], zero.angle);
		}
		sortA(input, pointN);
		sort = input;
		stk[0] = zero;
		stk[1] = input[0];
		int count = 2;
		point max = input[pointN - 1];
		point min = input[0];

		while (1)
		{
			for (int i = 0; i < pointN; i++)
			{
				input[i].angle = angle(input[i], min.angle);
			}
			sortA(input, pointN);
			min = input[0];


			if (min.x == max.x && min.y == max.y) {

				stk[count] = min;
				count++;
				break;
			}
			else
			{
				stk[count] = min;
				count++;

			}
		}

			for (int i = 0; i < count; i++)
			{
				printf("%lf %lf\n", stk[i].x, stk[i].y);
			}
			printf("\n");
			double circum = circumF(stk, count);
			printf("%.2lf", circum);
			caseN--;
		}

}
double circumF(struct points* input, int count)
{
	double num = 0;

	for (int i = 0; i < count; i++)
	{
		if (i + 1 == count) {
			num = num + circum(input[i], input[0]);
		}
		else {
			num = num + circum(input[i], input[i + 1]);
		}
	}
	return num + 2;
}
double circum(point p1, point p2)
{
	double result = (double)sqrt(pow((double)p2.x - (double)p1.x, 2) + pow((double)p2.y - (double)p1.y, 2));
	return result;
}
double angle(point a, double angle)
{
	double degree = (atan2(a.y, a.x) * 180 / PI) - angle;

	if (degree < 0)
	{
		return degree + 360;
	}
	else
	{
		return degree;
	}
}
int ccw(point A, point B, point C)
{
	return (int)((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}
void sortA(struct points* input, int count)
{
	point temp;
	temp.angle = 0;
	temp.x = 0;
	temp.y = 0;

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (input[j].angle > input[j + 1].angle)
			{
				
					temp = input[j];
					input[j] = input[j + 1];
					input[j + 1] = temp;
							
			}
			else
			{
				if (input[j].angle == input[j + 1].angle)
				{
					if (input[j].x < (input[j + 1].x) || (input[j].y) < (input[j + 1].y))
					{
						temp = input[j];
						input[j] = input[j + 1];
						input[j + 1] = temp;
					}
				}
			}
			
		}
	}
}
