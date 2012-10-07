/* Bounded queue implementation by Evan Brown in C for KPCB Fellow application. */

#include <stdlib.h>
#include <stdio.h>

struct queue
{
	int capacity, current_size, front, elements[];
};

/* This method creates a queue and checks for a malloc error. */
struct queue * create_queue (const int max_elements)
{
	struct queue *q = malloc (sizeof (struct queue) + sizeof (int) * max_elements);
	
	if (!q)
	{
		fprintf (stderr, "Error: failure to allocate enough memory for queue!\n");
		exit (EXIT_FAILURE);
	}
	
	// set capacity, current_size, and front index
	q->capacity = max_elements;
	q->current_size = q->front = 0;

	return q;
}

/* This method adds an integer to the queue and checks that there is enough room for the new integer. */
void enqueue (struct queue *q, const int a)
{
	if (q->capacity == q->current_size)
	{
		fprintf (stderr, "Error: queue is full!\n");
		exit (EXIT_FAILURE);
	}
	
	// increment current size and assign argument to back of queue
	q->elements[(q->front + q->current_size++) % q->capacity] = a;
}

/* This method removes an int from the front of the queue and checks that such an int exists. */
int dequeue (struct queue *q)
{
	if (q->current_size == 0)
	{
		fprintf (stderr, "Error: queue is empty!\n");
		exit (EXIT_FAILURE);
	}
	
	// decrement current_size, increment front index, and return integer from previous front of queue
	--q->current_size;
	int ret = q->elements[q->front];
	if (++q->front == q->capacity) // check that new front is not past end of array
		q->front = 0;
	return ret;
}

/* This method frees the queue's array of elements. */
void delete_queue (struct queue *q)
{
	if (q) // if q is not NULL
		free (q);
}
