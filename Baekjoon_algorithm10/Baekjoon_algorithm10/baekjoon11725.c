#include<stdio.h>
typedef struct Tree{
	int parent;
	int node;
}tree;
int main()
{
	int node[100000] = { 0, };
	int nodeC = 0;
	int nodeN = 0;
	int end1 = 0;
	int end2 = 0;
	int* comp;
	int *wait[3];
	int check = 0;
	node[0] = 1;
	scanf("%d", &nodeN);
	int waitN=0;
	tree* Tree = (tree*)malloc(sizeof(tree) * nodeN);
	comp = (int*)malloc(sizeof(int) * nodeN);
	wait[0] = (int*)malloc(sizeof(int) * nodeN); 
	wait[1] = (int*)malloc(sizeof(int) * nodeN);
	wait[2] = (int*)malloc(sizeof(int) * nodeN);
	
	
	for (int i = 0; i < nodeN-1; i++)
	{
		scanf("%d %d", &end1, &end2);
		if (end1 == node[end1 - 1])
		{
			Tree[i].parent = end1;
			Tree[i].node = end2;
			node[end2 - 1] = end2;
			comp[end2 - 1] = end1;
			check = 1;

		}
		else if (end2 == node[end2 - 1])
		{
			Tree[i].parent = end2;
			Tree[i].node = end1;
			node[end1 - 1] = end1;
			comp[end1 - 1] = end2;
			check = 1;
		}
		else
		{
			wait[0][waitN] = end1;
			wait[1][waitN] = end2;
			wait[2][waitN] = i;
			waitN++;
		}
		if (waitN != 0&&check==1)
		{
			if (wait[0][waitN-1] == end1)
			{
				Tree[wait[2][waitN-1]].parent = wait[0][waitN - 1];
				Tree[wait[2][waitN-1]].node = wait[1][waitN - 1];
				node[wait[1][waitN - 1]-1] = wait[1][waitN - 1];
				comp[wait[1][waitN - 1] - 1] = end1;
				waitN--;
			}
			else if (wait[0][waitN - 1] == end2)
			{
				Tree[wait[2][waitN - 1]].parent = wait[0][waitN - 1];
				Tree[wait[2][waitN - 1]].node = wait[1][waitN - 1];
				node[wait[1][waitN - 1] - 1] = wait[1][waitN - 1];
				comp[wait[1][waitN - 1] - 1] = end2;
				waitN--;
			}
			else if (wait[1][waitN - 1] == end1)
			{
				Tree[wait[2][waitN - 1]].parent = wait[1][waitN - 1];
				Tree[wait[2][waitN - 1]].node = wait[0][waitN - 1];
				node[wait[0][waitN - 1] - 1] = wait[0][waitN - 1];
				comp[wait[0][waitN - 1] - 1] = end1;
				waitN--;
			}
			else if (wait[1][waitN - 1] == end2)
			{
				Tree[wait[2][waitN - 1]].parent = wait[1][waitN - 1];
				Tree[wait[2][waitN - 1]].node = wait[0][waitN - 1];
				node[wait[0][waitN - 1] - 1] = wait[0][waitN - 1];
				comp[wait[0][waitN - 1] - 1] = end2;
				waitN--;
			}
		}
			
		
	}
	for (int i = 1; i < nodeN; i++)
	{
		printf("%d\n", comp[i]);
	}
	return 0;
}