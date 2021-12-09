#include<stdio.h>
#include"text5.h"

int main(void)
{
	queue q;
	position d;
	int i, j;

	q = creatqueue();

	do
	{
		scanf_s("%d", &i);
		scanf_s("%d", &j);
		addq(q, i, j);
	} while (getchar() != '\n');

	while (!isempty(q))
	{
		d = deleteq(q);
		if (d->edata > 0)
		{
			printf("%d %d ", d->sdata*d->edata, d->edata - 1);
		}
		free(d);
	}

	return 0;

	
}


