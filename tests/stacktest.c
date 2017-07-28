#include <dumb.h>

void
main()
{
	print("\nTesting Stack\n");
	Stack s = mkstack();
	int myint = 35;
	int yourint = 42;

	print("Size 0: %d\n", (int)s.size);
	stackpush(&s, &myint);
	stackpush(&s, &yourint);
	print("Size 2: %d\n", (int)s.size);

	int thirtyfive = *(int*)stackpop(&s);
	print("Return 42: %d\n", thirtyfive);
	int fortytwo = *(int*)stackpop(&s);
	print("Return 35: %d\n", fortytwo);
}

