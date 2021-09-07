#include<stdio.h>
void main()
{
	int person = 0;
	int money[100] = { 0, };
	int sum = 0;
	int avg = 0;

	
	while (1)
	{
		sum = 0;
		avg = 0;
		scanf_s("%d", &person);
		if (person == 0)
		{
			break;
		}
		for (int i = 0; i < person; i++)
		{
			scanf_s("%d", &money[i]);
			avg = avg + money[i];
		}
		avg = avg / person;
		if (avg % 10 != 0)
		{
			avg = avg - avg % 10;
		}
		for (int i = 0; i < person; i++)
		{
			if (avg > money[i])
			{
				sum = sum + avg - money[i];
			}
		}
		printf("%d\n", sum);

	}
	
}