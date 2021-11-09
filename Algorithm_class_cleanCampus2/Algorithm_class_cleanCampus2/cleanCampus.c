#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#define PI 3.141592654
double angle( point);
void sortA(struct points * , int );
int ccw(point , point , point);
double circumF(struct points * , int);
double circum(point , point );

typedef struct points {
	double x;
	double y;
	double angle;
}point;
void main()
{
	int caseN = 0;
	int pointN = 0;
	point *input;
	point zero;
	zero.x = 0;
	zero.y = 0;
	point* stk;
	printf("Type case number : ");
	scanf("%d", &caseN);
	printf("Type point number : ");
	scanf("%d", &pointN);
	stk = malloc(sizeof(point) * (pointN+1));
	input = malloc(sizeof(point) * pointN);
	
	while (caseN > 0)
	{
		for (int i = 0; i < pointN; i++)
		{
			scanf("%lf %lf", &input[i].x, &input[i].y);
			input[i].angle = angle(input[i]);
		}
		sortA(input, pointN);
		for (int i = 0; i < pointN; i++)
		{
			printf("pointnumber %d %lf %lf : %lf\n", i, input[i].x,input[i].y,input[i].angle);
		}
		stk[0] = zero;
		stk[1] = input[0];
		int count = 2;
		for (int i = 1; i < pointN; i++)
		{
			while (count >= 2 && (ccw(stk[count-2], stk[count - 1], input[i])<=0))
			{
				stk[count].x = 0;
				stk[count].y = 0;
				stk[count].angle = 0;
				count--;
			}
			stk[count] = input[i];
			count++;
		}
		printf("\n%d\n", count);
		for (int i = 0; i < count; i++)
		{
			printf("%lf %lf\n", stk[i].x,stk[i].y);
		}
		printf("\n");
		double circum = circumF(stk, count);
		printf("%.2lf", circum);
		caseN--;
	}
}
double circumF(struct points* input,int count)
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
	return num+2;
}
double circum(point input1, point input2)
{
	return (sqrt(pow((input1.x - input2.x),2)+pow((input1.y-input2.y),2)));
}
double angle(point a)
{
	double degree = (atan2(a.y, a.x) * 180 /PI);

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
void sortA(struct points *input,int count)
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
		}
	}
}