#include "dumb.h"

struct QueueNode
{
	QueueNode * prev;
	QueueNode * next;
	void * data;
};

Queue
mkqueue(void)
{
	Queue q;
	q.head = nil;
	q.tail = nil;
	q.size = 0;
	return q;
}

void
enqueue(Queue * q, void * data)
{
	QueueNode * node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data=data;
	node->next=nil;
	node->prev=nil;
	
	if(q->size > 0){
		QueueNode * next = q->tail;
		next->prev = node;
		node->next = next;
		q->tail=node;
	}else{
		q->head=node;
		q->tail=node;
	}
	q->size++;
}

void *
dequeue(Queue * q)
{
	if(q->size > 0){
		QueueNode * prev = q->head->prev;
		void * data = q->head->data;
		if(prev != nil){
			prev->next=nil;
		}
		free(q->head);
		q->head = prev;
		q->size--;
		return data;
	}else{
		return nil;
	}
}
