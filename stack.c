#include "dumb.h"

struct StackNode
{
	StackNode * below;
	void * data;
};

Stack
mkstack(void)
{
	Stack s;
	s.size=0;
	s.top=nil;
	return s;
}

void
stackpush(Stack * s, void * data)
{
	StackNode * node = (StackNode*)malloc(sizeof(StackNode));
	node->data = data;
	node->below = s->top;
	s->top = node;
	s->size++;
}

void *
stackpop(Stack * s)
{
	if(s->size > 0){
		StackNode * next = s->top->below;
		void * data = s->top->data;
		free(s->top);
		s->top = next;
		s->size--;
		return data;
	}else{
		return nil;
	}
}
