#include<stdio.h>
#include<stdlib.h>
#include "text7.h"

minheap create(int maxsize)
{
	minheap h = (minheap)malloc(sizeof(struct structheap));
	h->elements = (int*)malloc((maxsize + 1) * sizeof(int));
	h->size = 0;
	h->capacity = maxsize;
	h->elements[0] = mindata;//定义哨兵，小于堆中所有可能元素的值

	return h;
}

void insert(minheap h, int item)
{
	int i;
	if (h->size == h->capacity)
	{
		printf("最小堆已满");
		return;
	}
	i=++h->size;
	for ( ; h->elements[i / 2]>item; i /= 2)
	{
		h->elements[i] = h->elements[i / 2];
	}

	h->elements[i] = item;

}

int delelte(minheap h)
{
	int parent, child;
	int maxitem, x;
	if (h->size == 0)
	{
		printf("最小堆已为空");
		return -10000;
	}
	maxitem = h->elements[1];
	x = h->elements[h->size--];
	for (parent = 1; parent * 2 <= h->size; parent = child)
	{
		child = parent * 2;
		if ((child != h->size) && (h->elements[child] > h->elements[child + 1]))
		{
			child++;
		}
		if (x <= h->elements[child])
		{
			break;
		}
		else
		{
			h->elements[parent] = h->elements[child];
		}
	}
	h->elements[parent] = x;

	return maxitem;
}
