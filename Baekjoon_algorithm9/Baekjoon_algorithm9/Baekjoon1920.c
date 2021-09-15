#include<stdio.h>
#include<stdlib.h>
typedef struct M{
	int value;
	int boolean;
}m;
int cmp(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main()
{
	int N = 0, M = 0;
	int* arrN;
	m* arrM;
	m tempM;
	int temp = 0;

	scanf("%d", &N);
	arrN = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{

		scanf("%d", &arrN[i]);
	}
	scanf("%d", &M);
	arrM = malloc(sizeof(struct M) * M);
	for (int i = 0; i < M; i++)
	{

		scanf("%d", &arrM[i].value);
		arrM[i].boolean = 0;

	}
	qsort(arrN, N, sizeof(int), cmp);
		
	int f = 0, l = 0;
	for (int i = 0; i < M; i++)
	{
		f = 0;
		l = N - 1;
		while (f <= l)
		{
			int d = (f + l) / 2;
			if (arrN[(f + l) / 2] == arrM[i].value)
			{
				arrM[i].boolean = 1;
				break;
			}
			else if (arrN[d] < arrM[i].value)
			{
				f = d + 1;
			}
			else
			{
				l = d - 1;
			}

		}
	}
	for (int i = 0; i < M; i++)
		printf("%d ", arrM[i].boolean);
	free(arrN);
	free(arrM);
}