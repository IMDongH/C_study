#include<stdio.h>

int distinct(char X[], char Z[], int DP[]);


int LCS[101][1001] = { 0 , };
void main()
{
	int caseN = 0;
	char X[10001];
	char Z[101];
	char *XN[100];
	char *ZN[100];
	int DP[1000] = { 0, };
	
	printf("Type number of test case : ");
	scanf("%d", &caseN);

	for (int i = 0; i < caseN; i++)
	{
		scanf("%s", X);
		scanf("%s", Z);

		XN[i] = (char*)malloc(sizeof(char) * strlen(X));
		ZN[i] = (char*)malloc(sizeof(char) * strlen(Z));
		
		strcpy(XN[i], X);
		strcpy(ZN[i], Z);
	}

	for (int i = 0; i < caseN; i++) {
		printf("%d\n", distinct(XN[i], ZN[i], DP));
	}
	
}
int distinct(char X[], char Z[], int DP[])
{
	int check = 0;
	int checkF = 0;
	int max = 0;
	for (int i = 0; i < strlen(Z); i++)
	{

		for (int j = 0; j < strlen(X); j++)
		{
			
			if (X[j] == Z[i])
			{	
				
				if (checkF == 0&&check>=0)
				{
					LCS[i + 1][j + 1] = LCS[i+1][j] + 1;
					check++;		
				}
				else
				{
					LCS[i + 1][j + 1] = LCS[i+1][j] + LCS[i][j];
				}
				
				DP[i] = LCS[j + 1][i + 1];
			}
			else
			{
				LCS[i + 1][j + 1] = LCS[i+1][j];

			}
		}
		if (check == 0)
		{
			return 0;
		}
		else {
			check = -1;
		}
		
	}
	for (int i = 0; i < strlen(X); i++)
	{
		if (max < LCS[strlen(Z)][i+1]);
		max = LCS[strlen(Z)][i+1];
	}
	return max;
}