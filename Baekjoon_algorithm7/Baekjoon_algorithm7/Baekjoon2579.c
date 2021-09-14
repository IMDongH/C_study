#include<stdio.h>
int recur(int stair[], int num, int i, int count,int sum);
int max = 0;

int main()
{
	int num = 0;
	int stair[300] = { 0, };
	int count = 0;
	int sum=0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &stair[i]);
	}
	recur(stair, num, 0, 0,0);

	
	printf("%d", max);
	return 0;
}
int recur(int stair[], int num, int i, int count, int sum)
{
	
}