#include<stdio.h>
void recur(int num,int sum, int check );

int number = 0;
int arr[20] = { 0, };
int N = 0;
int S = 0;
int main() {

	
	int sum = 0; 
	scanf_s("%d ", &N);

	scanf_s("%d", &S);
	for (int i = 0; i < N; i++)
	{
		scanf_s(" %d", &arr[i]);
	}
	
		recur(0,0,0);

	printf("%d", number);

	return 0;

}
void recur(int num,int sum, int check)
{
	
	if (num == N) {
		if (sum == S&&check==1)
		{
			number++;
			
		}
		return;
	}
			recur(num+1, sum+arr[num],1);
			recur(num + 1, sum,check);
	
}