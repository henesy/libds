#include <ds.h>

int intcomp(void *a, void *b)
{
	if(*(int*)a < *(int*)b)
		return -1;
	else if(*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}

void
main()
{
	print("\nTesting List\n");
	List l = mklist();
	
	int thirtyfive = 35;
	int fortytwo = 42;
	
	listadd(&l, &fortytwo);
	listadd(&l, &thirtyfive);
	print("Size 2: %d\n", (int)l.size);

	print("Head, tail: %p, %p\n", l.head, l.tail);

	ListNode *ret0 = listfind(&l, &thirtyfive, intcomp);
	ListNode *ret1 = listfind(&l, &fortytwo, intcomp);

	print("Head, tail: %p, %p\n", ret1, ret0);

	listdel(&l, &thirtyfive, intcomp);
	listdel(&l, &fortytwo, intcomp);

	print("Size 0: %d\n", (int)l.size);
}
