#include<stdio.h>
#include<stdlib.h>
#include "SY1.h"

short visited[100] = { 0 };
//队列
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

void addq(queue q, struct vnode v)
{
	q->rear->v = v;
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
//图
lgraph creatgraph(int vertexnum)
{
	vertex v;
	lgraph graph;

	graph = (lgraph)malloc(sizeof(struct gnode));
	graph->nv = vertexnum;
	graph->ne = 0;

	for (v = 0; v < graph->nv; v++)
	{
		graph->g[v].firstedge = NULL;
		graph->g[v].data = v;
	}
	return graph;
}

void insertedge(lgraph graph, edge e)
{
	ptrtoadjvnode newnode;
	newnode = (ptrtoadjvnode)malloc(sizeof(struct adjvnode));
	newnode->adjv = e->v2;

	newnode->next = graph->g[e->v1].firstedge;
	graph->g[e->v1].firstedge = newnode;

	newnode = (ptrtoadjvnode)malloc(sizeof(struct adjvnode));
	newnode->adjv = e->v1;
	newnode->next = graph->g[e->v2].firstedge;
	graph->g[e->v2].firstedge = newnode;
}

lgraph buildgraph(int nv)
{
	lgraph graph;
	edge e;
	int i;

	graph = creatgraph(nv);

	scanf_s("%d", &(graph->ne));
	if (graph->ne != 0)
	{
		e = (edge)malloc(sizeof(struct enode));
		for (i = 0; i < graph->ne; i++)
		{
			scanf_s("%d %d", &e->v1, &e->v2);
			insertedge(graph, e);
		}
	}
	return graph;
}

void dfs(lgraph graph, vertex v)
{
	ptrtoadjvnode w;

	if (!visited[v])
	{
		printf("%d ", v);
		visited[v] = 1;
	}

	for (w = graph->g[v].firstedge; w; w = w->next)
	{
		if (!visited[w->adjv])
			dfs(graph, w->adjv);
	}
}

void bfs(lgraph graph, vertex v)
{
	queue q;
	ptrtoadjvnode w;
	position pos;

	q = creatqueue();
	addq(q, graph->g[v]);
	
	while (!isempty(q))
	{
		pos = deleteq(q);
		if (!visited[pos->v.data])
		{
			visited[pos->v.data] = 1;
			printf("%d ", pos->v.data);
		}
		
		for (w = pos->v.firstedge; w; w = w->next)
		{
			if (!visited[w->adjv])
				addq(q, graph->g[w->adjv]);
		}
		free(pos);

	}

}
