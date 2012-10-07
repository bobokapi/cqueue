/* Test of the queue implementation. */

#include "queue.h"

int main (int argc, char *argv[])
{
	struct queue *q1;
	q1 = create_queue (7);
	
	// int a = dequeue (q1); // successfully results in error
	
	/*for (int i = 0; i < 8; ++i) // successfully results in error
		enqueue (q1, i + 100);
	*/
	
	/* fill and empty queue multiple times */
	for (int i = 0; i < 7; ++i)
		enqueue (q1, i + 100);
	
	for (int i = 0; i < 4; ++i)
		printf ("dequeue#%d: %d\n", i + 1, dequeue (q1));

	for (int i = 7; i < 11; ++i)
		enqueue (q1, i + 200);
	
	for (int i = 4; i < 11; ++i)
		printf ("dequeue#%d: %d\n", i + 1, dequeue (q1));
	
	for (int i = 11; i < 18; ++i)
		enqueue (q1, i + 300);

	for (int i = 11; i < 18; ++i)
		printf ("dequeue#%d: %d\n", i + 1, dequeue (q1));
	
	delete_queue (q1);
	
	printf ("Success!\n");
	return 0;
}
