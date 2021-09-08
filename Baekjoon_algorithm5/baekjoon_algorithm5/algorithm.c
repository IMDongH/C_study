#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
void main()
{
	char str[1000001];
	char* result;
	int i = 0;
	int num = 0; 
	gets(str);
	
	result = strtok(str, " ");
	while (result != NULL)
	{
		result = strtok(NULL, " ");
		num++;
	}
	printf("%d", num);
	

}