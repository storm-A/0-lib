#pragma once
#ifndef __TEXT7_H__
#define __TEXT7_H__

#define mindata -10000
typedef struct structheap {
	int *elements;
	int size;
	int capacity;
}*minheap;

minheap create(int maxsize);
void insert(minheap h, int item);
int delelte(minheap h);

#endif