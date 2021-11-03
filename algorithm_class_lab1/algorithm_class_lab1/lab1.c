#include<stdio.h>
#include<math.h>;
typedef struct {
	int start;
	int end;
	int distance;

}intersection;
void main()
{
	int eFireS = 0;
	int INF = 1000000;
	int fire[100] = { 0 ,};
	int inN = 0;
	int adj[101][101] = { 0, };
	int dist[101][101] = { 0, };
	int sum[100] = { 0, };
	scanf("%d %d", &eFireS, &inN);
	intersection* inter = (intersection*)malloc(sizeof(intersection) * inN);
	for (int i = 0; i < eFireS; i++)
	{
		int num = 0;
		scanf("%d", &num);
		fire[i] = num;
	}
	for (int i = 0; i < inN; i++)//initialize 
	{
		scanf("%d %d %d", &inter[i].start, &inter[i].end, &inter[i].distance);
		adj[inter[i].start][inter[i].end] = inter[i].distance;
		adj[inter[i].end][inter[i].start] = inter[i].distance;
	}
	

	for (int i = 1; i <= inN; i++)//make matrix
	{
		for (int j = 1; j <= inN; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else if (adj[i][j])
			{
				dist[i][j] = adj[i][j];
			}
			else
				dist[i][j] = INF;
		}
	}

	for (int k = 1; k <= inN; k++)//using Floyd-Warshall algorithm make matrix
	{
		for (int i = 1; i <= inN; i++)
		{
			for (int j = 1; j <= inN; j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				dist[i][j] =  dist[i][k] + dist[k][j];
			}
		}
	}
	int minN ;
	int min = 0;
	for (int i = 1; i <= inN; i++)
	{
		minN = dist[i][1];
		
		for (int j = 1; j <= inN; j++)
		{
			if (dist[i][j] == INF)
			{

			}
			else
			{
				
				sum[i] = sum[i] + dist[i][j];
				for (int k = 0; k < eFireS; k++) {
				if (i == fire[k])
				{
					if (minN < dist[i][j])
					{
						minN = dist[i][j];
						min = j;
					}
				}
			}
			}

		}
		
	}
	int min1 = sum[1];
	for (int i = 2; i <= inN; i++)
	{
		if (sum[i] < min)
		{
			min = sum[i];
		}
	}

	if (eFireS > 1)
	{
		
	}
	else
	{
		printf("%d", min);
	}

	

}