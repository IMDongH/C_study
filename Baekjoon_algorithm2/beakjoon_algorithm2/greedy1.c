#include<stdio.h>
#pragma warning(disable:4996)
void main()
{
	unsigned long sum=0;
	scanf("%lu", &sum);
	int i = 1;

	while ((long long)((i * (i + 1)) / 2) <= sum)
	{
		i++;
	}
	i--;
	printf("%d", i);
}