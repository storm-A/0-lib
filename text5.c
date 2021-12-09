//队列
#include<stdio.h>
#include"text5.h"
#include<stdlib.h>

queue creatqueue()
{
	queue q;
	q = (queue)malloc(sizeof(struct qnode));
	q->rear = (ptrtonode)malloc(sizeof(struct node));

	q->front = q->rear;
	q->rear->next = NULL;				//空队列

	return q;
}

short isempty(queue q)
{
	return(q->front == q->rear);
}

void addq(queue q, elementtype x, elementtype y)
{
	q->rear->sdata = x;
	q->rear->edata = y;
	q->rear->next = (ptrtonode)malloc(sizeof(struct node));
	q->rear = q->rear->next;
	q->rear->next = NULL;

}

position deleteq(queue q)
{
	position p;
	if (isempty(q))
	{
		printf("队列空");
		return NULL;
	}
	else
	{
		p = q->front;
		q->front = q->front->next;
		return p;
	}
}
