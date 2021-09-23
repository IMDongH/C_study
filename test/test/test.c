#include<stdio.h>

int fmin(int a, int b, int c);
int main()
{
	int row = 0, cul = 0;
	int matrix[10][100] = { 0, };
	int* dp;
	int* pdp;
	int list[10][100];
	int plist[10][100];
	int min = 0;
	int minN = 0;
	FILE* fp;
	fp = fopen("test.txt", "r");
	if (fp == NULL)
	{
		printf("error");
	}
	else {


		while (!feof(fp))
		{
			fscanf(fp, "%d %d", &cul, &row);

			for (int i = 0; i < cul; i++)
			{
				for (int j = 0; j < row; j++)
				{
					fscanf(fp, "%d ", &matrix[i][j]);
				}
			}

			dp = (int*)malloc(sizeof(int) * cul);


			pdp = (int*)malloc(sizeof(int) * cul);




			for (int i = 0; i < row; i++)
			{
				if (i == 0)
				{
					for (int j = 0; j < cul; j++)
					{
						dp[j] = matrix[j][i];
						list[j][i] = matrix[j][i];
					}
				}
				else
				{
					for (int j = 0; j < cul; j++)
					{
						if (j == 0)
						{
							min = fmin(pdp[cul - 1], pdp[j], pdp[j + 1]);
							if (min == pdp[cul - 1])
							{
								dp[j] = pdp[cul - 1] + matrix[j][i];
								for (int s = 0; s <= i; s++) {
									list[j][s] = plist[cul - 1][s];
								}
								list[j][i] = matrix[j][i];

							}
							else if (min == pdp[j])
							{
								dp[j] = pdp[j] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[j][s];
								list[j][i] = matrix[j][i];
							}
							else
							{
								dp[j] = pdp[j + 1] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[j + 1][s];
								list[j][i] = matrix[j][i];
							}
						}
						else if (j == cul - 1)
						{
							min = fmin(pdp[j - 1], pdp[j], pdp[0]);
							if (min == pdp[j - 1])
							{
								dp[j] = pdp[j - 1] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[j - 1][s];
								list[j][i] = matrix[j][i];
							}
							else if (min == pdp[j])
							{
								dp[j] = pdp[j] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[j][s];
								list[j][i] = matrix[j][i];
							}
							else
							{
								dp[j] = pdp[0] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[0][s];
								list[j][i] = matrix[j][i];
							}
						}
						else
						{
							min = fmin(pdp[j - 1], pdp[j], pdp[j + 1]);
							if (min == pdp[j - 1])
							{
								dp[j] = pdp[j - 1] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[j - 1][s];
								list[j][i] = matrix[j][i];

							}
							else if (min == pdp[j])
							{
								dp[j] = pdp[j] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[j][s];
								list[j][i] = matrix[j][i];
							}
							else
							{
								dp[j] = pdp[j + 1] + matrix[j][i];
								for (int s = 0; s <= i; s++)
									list[j][s] = plist[j + 1][s];
								list[j][i] = matrix[j][i];
							}
						}

					}
				}
				for (int j = 0; j < cul; j++)
				{
					pdp[j] = dp[j];
					for (int s = 0; s < row; s++) {
						plist[j][s] = list[j][s];
					}
				}

			}
			min = dp[0];
			for (int i = 1; i < cul; i++)
			{
				if (min > dp[i])
				{
					minN = i;
				}
			}
			for (int i = 0; i < row; i++)
			{
				printf("%d ", list[minN][i]);
			}
			printf("\n%d\n", dp[minN]);

		}

	}


	return 0;
}
int fmin(int a, int b, int c)
{
	int min = a;
	if (min > b)
	{
		min = b;
	}
	if (min > c)
	{
		min = c;

	}
	return min;
}