#include<stdio.h>
int GCD(int num1, int num2);
int extended_Euclid(int num1, int num2, int gcd);

void main()
{
	extended_Euclid(17, 17, GCD(17, 17));
}

int GCD(int num1, int num2)
{
	if (num2 == 0)
	{
		return num1;
	}
	else {
		return GCD(num2, num1 % num2);
	}

}
int extended_Euclid(int num1, int num2, int gcd)
{
	int LCM = 0;
	int numB1 = 0;
	int numB2 = 0;
	int min = 0;
	int num = 0;
	LCM = (num1 * num2) / gcd;
	for (int i = 1; num1 * i <= LCM; i++)
	{
		for (int j = 1; num2 * j <= LCM; j++)
		{
			if (abs(num1 * i - num2 * j) == gcd)
			{
				if (num == 0)
				{
					min = i + j;
					if ((num1 * i - num2 * j) > 0)
					{
						numB1 = i;
						numB2 = -j;
					}
					else
					{
						numB1 = -i;
						numB2 = j;
					}
					num++;


				}

				if (num != 0 && min > i + j)
				{
					if ((num1 * i - num2 * j) > 0)
					{
						numB1 = i;
						numB2 = -j;
					}
					else
					{
						numB1 = -i;
						numB2 = j;
					}
				}

			}
		}
	}
	printf("%d %d %d", numB1, numB2, gcd);
}