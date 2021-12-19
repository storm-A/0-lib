#pragma once
#ifndef __SY_H__
#define __SY_H__

typedef struct tnode *ptrtotnode;
struct tnode {
	char name;
	short child;  //标记是否是孩子
	int leftsign;
	int rightsign;
	ptrtotnode left;
	ptrtotnode right;
};

typedef int elementtype;
typedef struct node *ptrtonode;
struct node {
	ptrtotnode tptr;
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
void addq(queue q);
position deleteq(queue q);
position findtree(queue q, int sign);
ptrtotnode buildtree(queue q);
short chargetree(ptrtotnode t1, ptrtotnode t2);
void bianli(ptrtotnode t1);
#endif
