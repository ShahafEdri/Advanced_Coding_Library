#include "Queue_arr.h"
#include "stdlib.h"

void create_queue (queue *pq)
{
	pq->items_num = 0;
    pq->front = 0;
    pq->rear = 0;
}

//queue* create_queue(int size)
//{
//	queue* pq = (queue*)malloc(sizeof(queue));
//	pq->items_num = 0;
//	pq->front = 0;
//	pq->rear = 0;
//	pq->items = (queue_type*)malloc(size * sizeof(queue_type));
//	return pq;
//}

int enqueue(queue_type x, queue* pq)
{
	if (pq->items_num == MaxQueue)
		return 0;
	pq->items[pq->rear] = x;
	pq->rear = (pq->rear + 1) % MaxQueue;
	pq->items_num++;
	return 1;
}

int dequeue(queue* pq, queue_type* px)
{
	if (pq->items_num == 0)
		return 0;
	*px = pq->items[pq->front];
	pq->front = (pq->front + 1) % MaxQueue;
	pq->items_num--;
	return 1;
}

int queue_front(queue* pq, queue_type* px)
{
	if (pq->items_num == 0)
		return 0;
	*px = pq->items[pq->front];
	return 1;
}

int queue_is_empty(queue* pq)
{
	return pq->items_num == 0;
}

int queue_is_full(queue* pq)
{
	return pq->items_num == MaxQueue;
}

int size_of_queue(queue* pq)
{
	return pq->items_num;
}











