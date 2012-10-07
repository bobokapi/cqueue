/* Header file for queue implementation. */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

struct queue
{
	int capacity, current_size, front, elements[];
};

struct queue * create_queue (const int);
void enqueue (struct queue *, const int);
int dequeue (struct queue *);
void delete_queue (struct queue *);
#endif
