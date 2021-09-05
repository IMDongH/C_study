#include<stdio.h>


int num[2][41] = { 0, };
void fibo(int fiboN);
void sum(int n);

int main()
{
	int T = 0;
	int fiboN[41];


	num[0][0] = 1;

	num[1][1] = 1;



	for (int i = 0; i < T; i++)
	{
		scanf("%d", &fiboN[i]);
		sum(fiboN[i]);
	}

	for (int i = 0; i < T; i++)
	{

		fibo(fiboN[i]);
	}
	return 0;
}
void fibo(int fiboN)
{

	printf("%d %d\n", num[0][fiboN], num[1][fiboN]);

}
void sum(int n)
{
	for (int i = 2; i <= n; i++)
	{


		num[0][i] = num[0][i - 1] + num[0][i - 2];
		num[1][i] = num[1][i - 1] + num[1][i - 2];

	}
}