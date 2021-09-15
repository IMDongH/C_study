#include<stdio.h>

int main()
{
	int num = 0;
	int stair[300] = { 0, };
	int DP[300];
	int max = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &stair[i]);
	}
	DP[0] = stair[0];
	DP[1] = stair[0] + stair[1];
	if (stair[0] + stair[2] > stair[1] + stair[2])
	{
		DP[2] = stair[0] + stair[2];
	}
	else
	{
		DP[2] = stair[1] + stair[2];
	}
	for (int i = 3; i < num; i++)
	{
		if (stair[i] + DP[i-2] > stair[i]+stair[i-1]+DP[i-3])
		{
			DP[i] = stair[i] + DP[i - 2];
		}
		else
		{
			DP[i] = stair[i] + stair[i - 1] + DP[i - 3];
		}
	}

	printf("%d", DP[num-1]);
	return 0;
}