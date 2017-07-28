#include <dumb.h>

void
main()
{
	print("\nTesting Queue\n");
	Queue q = mkqueue();
	
	int thirtyfive = 35;
	print("Size 0: %d\n", (int)q.size);
	enqueue(&q, &thirtyfive);
	int fortytwo = 42;
	enqueue(&q, &fortytwo);
	print("Size 2: %d\n", (int)q.size);
	
	int res0 = *(int*)dequeue(&q);
	print("Return 35: %d\n", res0);
	int res1 = *(int*)dequeue(&q);
	print("Return 42: %d\n", res1);
}
