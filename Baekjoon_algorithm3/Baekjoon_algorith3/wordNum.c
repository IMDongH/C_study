#include<stdio.h>
#include<stdlib.h>
void main()
{
	int num = 0;
	int number = 0;
	int end = 26;
	char word[10][9];
	int wordN[26] = { 0, };
	int sum = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		int count = 1;
		number = 1;
		scanf(" %s", &word[i]);
		while (count < strlen(word[i]))
		{
			number = number * 10;
			count++;
		}

		for (int j = 0; j < strlen(word[i]); j++) 
		{
		
			wordN[word[i][j] - 65] = wordN[word[i][j] - 65]+ number;
			number = number / 10;

		}
			
		}

	
	int swap = 0;
	for (int i = 0; i < 26-1 ; i++)
	{
		
		for (int j = 0; j < 26 - i-1 ; j++)
		{
			
			if (wordN[j] > wordN[j + 1])
			{
				swap = wordN[j];
				wordN[j] = wordN[j + 1];
				wordN[j + 1] = swap;
			}
		}
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (wordN[i] == 0)
		{
			end = i;
			break;
		}
	}
	int x = 9;
	for (int j=25; j>end; j--)
	{
		
		sum = sum + wordN[j] * x;
		x--;
	}
	printf("%d", sum);
}