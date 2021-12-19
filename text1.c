#include<stdio.h>
#include"SY.h"
//二叉树的同构判断
int main(void)
{
	int j,k=0;
	short charge = 0;
	queue q1,q2;
	ptrtotnode tree1,tree2;
	//printf("please input tree1:\n");
	q1= creatqueue();
	scanf_s("%d", &k);
	getchar();
	for (j = 0; j < k; j++)
	{
		addq(q1);
	}
	tree1= buildtree(q1);
	//bianli(tree1);
	//printf("please input tree2:\n");
	q2 = creatqueue();
	scanf_s("%d", &k);
	getchar();
	for (j = 0; j < k; j++)
	{
		addq(q2);
	}
	tree2 = buildtree(q2);
	//bianli(tree2);
	charge = chargetree(tree1,tree2);
	if (charge == 1)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	return 0;
}

