//未



//完



//成



//仅供参考，dijkstar函数有部分问题
#include<stdio.h>
#include<stdlib.h>

#define INF 10000
#define NUM 100

typedef struct adjvnode {//邻居
	int adjv, weight;
	struct adjvnode *next;
}vnode;

typedef struct gnode {
	int nv;
	int ne;
	vnode *g[NUM];//表头
}*lgraph;

struct enode {//边
	int v1, v2, weight;
}edges[] = { {0,1,5},{0,3,2},{1,4,3},{1,3,2},{3,4,6},{4,6,2},{3,6,1},{6,5,1},{3,5,7},{3,2,10},{2,0,1},{2,5,4} };

lgraph creategraph(int num)
{
	int v, w;
	lgraph g = (lgraph)malloc(sizeof(struct gnode));
	g->nv = num;
	g->ne = 0;
	for (v = 0; v < g->nv; v++)
	{
		g->g[v] = NULL;
	}
	return g;
}

void insertedge(lgraph g, struct enode *e)
{
	vnode *newnode;
	newnode = (vnode*)malloc(sizeof(struct adjvnode));
	newnode->adjv = e->v2;
	g->ne++;
	newnode->weight = e->weight;
	newnode->next = g->g[e->v1]->next;
	g->g[e->v1]->next = newnode;
}

int gitweight(lgraph g, int v, int w)
{
	vnode *vp;
	vp = g->g[v]->next;
	while (vp->adjv != w && vp->adjv != NULL)
	{
		vp = vp->next;
	}
	if (vp->adjv != NULL)
	{
		return vp->weight;
	}
	else
		return INF;
	
}

int findmindist(lgraph g, int dist[], int collect[])
{
	int minv, v;
	int mindist = INF;
	for (v = 0; v < g->nv; v++)
	{
		if (collect[v] == 0 && dist[v] < mindist)
		{
			mindist = dist[v];
			minv = v;
		}
	}
	if (mindist < INF)
		return minv;
	else
		return -1;
}

dijkstra(lgraph g, int dist[], int path[], int collected[], int s)
{
	int v, w;
	vnode *vp;
	dist[s] = 0;
	collected[s] = 1;
	while (1)
	{
		v = findmindist(g, dist, collected);
		if (v == -1)
			break;
		collected[v] = 1;

		for (vp=g->g[v]->next; vp!=NULL; vp=vp->next)
		{
			if (collected[vp->adjv] == 0 && vp->weight < INF)
			{
				if (dist[v] + vp->weight < dist[vp->adjv])
				{
					dist[vp->adjv] = dist[v] + vp->weight;
					path[vp->adjv] = v;
				}
			}
		}
	}
	return 1;
}

int main(void)
{
	int collected[7] = { 0 };
	int dist[7] = { INF,INF,INF,INF,INF,INF,INF };
	int path[7] = { -1,-1,-1,-1,-1,-1,-1 };
	lgraph lg = creategraph(7);
	int i = 0, s = 0;
	for (i = 0; i < 12; i++)
	{
		insertedge(lg, &edges[i]);
	}
	dijkstra(lg, dist, path, collected, 3);
	for (i = 0; i < 7; i++)
	{
		printf("%d ", dist[i]);
	}

}
