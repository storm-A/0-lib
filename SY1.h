#pragma once
#ifndef __SY1_H__
#define __SY1_H__

#define maxvertexnum 100

extern short visited[100];

//图
typedef int vertex;
typedef int datatype;
//边定义 
typedef struct enode *ptrtoenode;
struct enode {
	vertex v1;
	vertex v2;
};
typedef ptrtoenode edge;
//邻接点 
typedef struct adjvnode *ptrtoadjvnode;
struct adjvnode {
	vertex adjv;
	ptrtoadjvnode next;
};
//顶点表头节点定义
typedef struct vnode {
	ptrtoadjvnode firstedge;  //边表头指针
	datatype data;
} adjlist[maxvertexnum];
//图的定义
typedef struct gnode *ptrtognode;
struct gnode {
	int nv;  //顶点数
	int ne;  //边数
	adjlist g;  //邻接表
};
typedef ptrtognode lgraph;

//队列
typedef int elementtype;
typedef struct node *ptrtonode;
struct node {
	struct vnode v;
	ptrtonode next;
};
typedef ptrtonode position;

typedef struct qnode *ptrtoqnode;
struct qnode {
	position front;
	position rear;
};
typedef ptrtoqnode queue;

queue creatqueue();
short isempty(queue q);
void addq(queue q, struct vnode v);
position deleteq(queue q);

lgraph buildgraph(int nv);
void dfs(lgraph graph, vertex v);
void bfs(lgraph graph, vertex v);

#endif
