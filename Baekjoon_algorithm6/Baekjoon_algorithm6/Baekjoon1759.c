#pragma warning(disable:4996)
int  consorvowel(char arr);
int findarr(int index, int num, char printf[], int consN, int vowelN);
#include<stdio.h>

int N = 0;
int number = 0;
char arr[16];
int main()
{
	
	char print[16] = "";

	scanf("%d %d", &N, &number);


	for (int i = 0; i < number; i++)
	{
		scanf(" %c", &arr[i]);
	}
	for (int i = 0; i < number - 1; i++)
	{
		for (int j = 0; j < number - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	findarr(0, 0, print, 0, 0);


	return 0;
}
int  consorvowel(char arr)
{
	if (arr == 'a' || arr == 'e' || arr == 'i' || arr == 'o' || arr == 'u')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int findarr(int index, int num, char print[], int vowelN, int consN)
{
	if (num > number)
		return;
	if (strlen(print) == N)
	{
		if (vowelN >= 1)
		{
			for (int i = 0; i < N; i++)
			{
				if (consorvowel(print[i]))
				{


				}
				else
				{
					consN++;
				}
				if (consN >= 2)
				{
					printf("%s\n", print);
					return;
				}

			}
			return;
		}
		else
			return;

	}

	print[index] = arr[num];
	if (consorvowel(print[index]))
	{
		vowelN++;
	}

	findarr(index + 1, num + 1, print, vowelN, consN);

	if (consorvowel(print[index]))
		vowelN--;
	print[index] = '\0';

	findarr(index, num + 1, print, vowelN, consN);
}
