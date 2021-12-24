#include<stdio.h>
#include<stdlib.h>
#include "SY1.h"

int main(void)
{
	lgraph graph;
	int i, j, nv = 0;
	scanf_s("%d", &nv);
	graph= buildgraph(nv);
	printf("dfs:\n");
	for (j = 0; j < nv; j++)
	{
		printf("{ ");
		dfs(graph, j);
		printf("}");
		printf("\n");
	}
	for (i = 0; i < 100; i++)
		{
			visited[i] = 0;
		}
	printf("bfs:\n");
	for (j = 0; j < nv; j++)
	{
		printf("{ ");
		bfs(graph, j);
		printf("}");
		printf("\n");
	}
	

	return 0;
}
