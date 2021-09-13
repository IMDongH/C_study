#include<stdio.h>

typedef struct Elepahant {
	int IQ;
	int KG;
	int ID;
}elephant;
int Find(int num);

int DP[1000]; //The number of subsequences that done up to N.
int list[1000]; //list of  loaction that maximum length of the subsequence elements.
int index=0;
elephant Info[1000];

void main()
{
	FILE* fp;
	fp = fopen("test2.txt", "r");
	if (fp == NULL)
	{
		printf("ERROR");
	}
	else {
		int num = 0;
		while (!feof(fp)) {

			fscanf(fp, "%d %d", &Info[num].KG, &Info[num].IQ);
			Info[num].ID = num+1;
			num++;
		}
		elephant temp;
		for (int i = 0; i < num - 1; i++) //sorting
		{
			for (int j = 0; j < num - i - 1; j++)
			{
				if (Info[j].KG > Info[j + 1].KG)
				{
					temp = Info[j];
					Info[j] = Info[j + 1];
					Info[j + 1] = temp;

				}
				else if (Info[j].KG == Info[j + 1].KG)
				{
					if (Info[j].IQ > Info[j + 1].IQ)
					{
						temp = Info[j];
						Info[j] = Info[j + 1];
						Info[j + 1] = temp;
					}
				}
			}

		}

		printf("%d\n", Find(num)); //print maximum  of subsequence
		for (int i = 0; i < index; i++) //print result that number of maximum subsequence
		{
			printf("%d\n", Info[list[i]].ID);
		}


		fclose(fp);
	}
}
int Find(int num)
{
	int max = 0;
	index = 0;
	

	for (int i = 0; i < num; i++)
	{
		DP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (Info[j].KG<Info[i].KG &&Info[j].IQ>Info[i].IQ&&DP[i]<DP[j]+1)// Find the subsequence of the previous maximum length by comparing j values less than i .
			{
				DP[i] = DP[j] + 1;
				if (index==0)
				{
					list[index++] = j;
					list[index++] = i;
				}
				else if (list[index -1]==j)//check previous maximum subsequence's last elements
				{
					list[index++] = i;
				}
			}
			if (max < DP[i]) // find maximum length
				max = DP[i];
		}
	}
	
	return max;
}