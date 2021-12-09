#pragma once
#ifndef __TEXT5_H__
#define __TEXT5_H__

typedef int elementtype;

typedef struct node *ptrtonode;
struct node {
	elementtype sdata;
	elementtype edata;
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
void addq(queue q, elementtype x, elementtype y);
position deleteq(queue q);

#endif
