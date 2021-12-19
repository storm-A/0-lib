#include<stdio.h>
#include<stdlib.h>
#include"SY.h"
 
//队列
queue creatqueue()
{
	queue q;
	q = (queue)malloc(sizeof(struct qnode));
	q->rear = (ptrtonode)malloc(sizeof(struct node));
	q->rear->tptr = (ptrtotnode)malloc(sizeof(struct tnode));
	q->front = q->rear;
	q->rear->next = NULL;				//空队列
	q->rear->tptr->left = NULL;
	q->rear->tptr->right = NULL;

	return q;
}

short isempty(queue q)
{
	return(q->front == q->rear);
}

void addq(queue q)
{
	char a, b, c;
	scanf_s("%c ", &c);
	scanf_s("%c ", &a);
	scanf_s("%c", &b);
	q->rear->tptr->name = c;
	if (a == '-')
	{
		q->rear->tptr->leftsign = -1;
	}
	else
	{
		q->rear->tptr->leftsign = (int)a-48;
	}
	if (b == '-')
	{
		q->rear->tptr->rightsign = -1;
	}
	else
	{
		q->rear->tptr->rightsign = (int)b-48;
	}
	getchar();
	q->rear->tptr->child = 0;
	q->rear->next = (ptrtonode)malloc(sizeof(struct node));
	q->rear = q->rear->next;
	q->rear->next = NULL;
	q->rear->tptr = (ptrtotnode)malloc(sizeof(struct tnode));
	q->rear->tptr->left = q->rear->tptr->right = NULL;
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

position findtree(queue q,int sign)
{
	int i;
	position p;
	p = q->front;
	for (i = 0; i < sign; i++)
	{
		p = p->next;
	}
	return p;
}

ptrtotnode buildtree(queue q)
{
	position cp, np;
	cp = q->front;
	while (cp != q->rear)
	{
		if (cp->tptr->leftsign != -1)
		{
			np = findtree(q, cp->tptr->leftsign);
			cp->tptr->left = np->tptr;
			np->tptr->child = 1;
		}
		if (cp->tptr->rightsign != -1)
		{
			np = findtree(q, cp->tptr->rightsign);
			cp->tptr->right = np->tptr;
			np->tptr->child = 1;
		}
		cp = cp->next;
	}
	cp = q->front;
	while (cp->tptr->child != 0 && cp != q->rear)
	{
		cp = cp->next;
	}
	return cp->tptr;
}

void bianli(ptrtotnode t1)
{
	if (t1)
	{
		bianli(t1->left);
		printf("%c\n", t1->name);
		bianli(t1->right);
	}
}

short chargetree(ptrtotnode t1, ptrtotnode t2)
{
	if (t1 == NULL && t2 == NULL)//判断是否都为空
	{
		return 1;
	}
	if ((t1 == NULL && t2 != NULL )|| (t1 != NULL && t2 == NULL))//判断是否一个为空，一个不空
	{
		return 0;
	}
	if (t1->name != t2->name)//判断名字是否相同
	{
		return 0;
	}
	if (t1->left == NULL && t2->left == NULL)//判断是否都没有左孩子
	{
		return chargetree(t1->right, t2->right);
	}
	if (t1->left != NULL && t2->left != NULL)//如果两个都有左孩子
	{
		if (t1->left->name == t2->left->name)
		{
			return (chargetree(t1->right, t2->right)&& chargetree(t1->left, t2->left));
		}
		else
		{
			return (chargetree(t1->left, t2->right) && chargetree(t1->right, t2->left));
		}
	}
	if (t1->left != NULL && t2->left == NULL)//判断是否一个有左孩子一个没有
	{
		return chargetree(t1->left, t2->right);
	}
	if (t1->left == NULL && t2->left != NULL)//判断是否一个有左孩子一个没有
	{
		return chargetree(t1->right, t2->left);
	}
}