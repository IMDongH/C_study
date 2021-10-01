#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct data {
	int sPoint;
	int ePoint;
	double length;
};
double length(double p1, double p2);

int main()
{
	int dots = 0;//number of dots
	double** Point;//store coordinates of the dots.
	double minS = 0; //the minimum total length
	scanf("%d", &dots);
	struct data* Data;//for minimum total length

	Point = (double**)malloc(sizeof(double) * dots);
	Data = (struct data*)malloc(sizeof(struct data) * ((dots*(dots - 1)) / 2));
	for (int i = 0; i < dots; i++)
	{	
		Point[i] = (double*)malloc(sizeof(double)*2);
		scanf("%lf %lf", &Point[i][0], &Point[i][1]);
	}
	int n = 0;
	for (int i = 0; i < dots-1; i++)
	{
		for (int j = i+1; j < dots; j++)
		{
			Data[n].sPoint = i;//store coordinates
			Data[n].ePoint = j;//store coordinates
			Data[n].length = length(fabs(Point[i][0]-Point[j][0]),fabs(Point[i][1]-Point[j][1]));//store length between start point and end point
			n++;
		}
	}
	struct data temp ;
	for (int i = 0; i < ((dots * (dots - 1)) / 2); i++)//sort ascending order
	{
		for (int j = 0; j < ((dots * (dots - 1)) / 2) - 1 - i; j++)
		{
			if (Data[j].length > Data[j + 1].length)
			{
				temp = Data[j];
				Data[j] = Data[j + 1];
				Data[j + 1] = temp;
			}
		}
	}
	
	int bool[2] = { 0, };//check cycle
	int** point;//for check cycle
	point = (int**)malloc(sizeof(int)* ((dots * (dots - 1)) / 2));
	
	for(int i=0; i< ((dots * (dots - 1)) / 2); i++)
	point[i] = (int*)malloc(sizeof(int)*2);
	
	for (int i = 0; i < ((dots * (dots - 1)) / 2); i++)
	{
		if (i == 0)//first try
		{
			point[i][0] = Data[i].sPoint;
			point[i][1] = Data[i].ePoint;
			minS = minS + Data[i].length;

		}
		else
		{
			bool[0] = 0;
			bool[1] = 0;
			for (int j = 0; j < i; j++)
			{
				if ( Data[i].ePoint == point[j][1]|| Data[i].ePoint == point[j][0])//If the value end point to add already exists,
					
				{
					bool[0] = 1;
				}
				if ((Data[i].sPoint == point[j][0] || Data[i].sPoint == point[j][1]))//If the value start point to add already exists,
				{
					bool[1] = 1;
				}
				
			}
			if (bool[0]==0 || bool[1] == 0)//If there's no starting point or ending point,
			{
				point[i][0] = Data[i].sPoint;
				point[i][1] = Data[i].ePoint;
				minS = minS + Data[i].length;

			}

		}
	}

	printf("\n%.2lf\n", minS);

	for (int i = 0; i < dots; i++)
	{
		free(Point[i]);
	}
	free(Data);
	free(Point);

	for (int i = 0; i < ((dots * (dots - 1)) / 2); i++)
	{
		free(point[i]);
	}
	free(point);
	return 0;
}
double length(double p1, double p2)//calculate length
{
	return sqrt(pow(p1,2) + pow(p2,2));
}