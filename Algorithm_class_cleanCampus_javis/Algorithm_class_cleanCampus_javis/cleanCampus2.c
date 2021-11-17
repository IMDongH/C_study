#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point {
	float x;
	float y;
	float angle;
	int visit; //visit or not
}point;


float angle(point A, point B);
float circumF();
float circum(struct point A, struct point B);

point sorted[100]; //Javis Order 
int count = 0;  //sorted's length

int main()
{
	int pointN=0;
	int caseN = 0;
	printf("Type case number : ");
	scanf("%d", &caseN);
	printf("Type point number : ");
	scanf("%d", &pointN);

	point P[100];
	while (caseN > 0)
	{
		P[0].x = 0; P[0].y = 0; P[0].visit = 0;
		pointN++;

		for (int i = 1; i < pointN; i++)
		{
			scanf("%f %f", &P[i].x, &P[i].y);
			P[i].visit = 0;

		}


		int  start = 0;
		for (int i = 0; i < pointN; i++)//start from smallest y value
		{
			if (P[start].y > P[i].y)
			{
				start = i;
			}
		}

		int anchor;

		anchor = start;
		sorted[0] = P[anchor];
		P[anchor].visit = 1;
		P[anchor].angle = 0; // initialization



		float sAngle; //smalleast angle
		int sAngleIndex = 0; //smallest angle's index


		while (1)
		{

			sAngle = 360; // initialization 
			for (int i = 0; i < pointN; i++)
			{

				if (P[i].x == P[anchor].x && P[i].y == P[anchor].y) //Pass itself
					continue;
				
				P[i].angle = angle(P[anchor], P[i]);//Calculation the angle to next point

				
				if ((P[i].angle < sAngle) && (P[i].angle >= P[anchor].angle))
				{
					sAngle = P[i].angle;
					sAngleIndex = i;
				}

			}

			sorted[count++] = P[anchor]; 

			
			if (P[sAngleIndex].visit == 1)// If the next point is already visited break
				break;

			anchor = sAngleIndex;
			P[anchor].visit = 1;


		}
		printf("\n%0.2f\n", circumF());
		caseN--;
	}
	return 0;
}



	float angle(point A, point B)
{
	float  Dx, Dy;
	float Angle;
	Dx = B.x - A.x;
	Dy = B.y - A.y;

	//horizontal line
	if ((Dx >= 0) && (Dy == 0))Angle = 0;
	else {

		Angle = ((float)abs(Dy)) / ((abs(Dx) + abs(Dy)));
		//2 quadrant
		if ((Dx < 0) && (Dy >= 0))Angle = 2 - Angle;
		//3 quadrant
		else if ((Dx <= 0) && (Dy < 0))Angle = 2 + Angle;
		//4 quadrant
		else if ((Dx > 0) && (Dy < 0))Angle = 4 - Angle;

	}
	//Change the tangent value to angle
	return (Angle * 90.0);
}
//Calculate the distance between two points
	float circumF()
	{
		float num = 2;

		for (int i = 0; i < count; i++)
		{
			
				num = num + circum(sorted[i], sorted[i + 1]);
			
		}
		
			num = num + circum(sorted[count], sorted[0]);
		
		return num ;
	}
	float circum(struct point A, struct point B)
	{
		float result = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
		return result;
	}