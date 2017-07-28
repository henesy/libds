#include "ds.h"

struct ListNode
{
	ListNode * prev;
	ListNode * next;
	void * data;
};

List
mklist(void)
{
	List l;
	l.head = nil;
	l.tail = nil;
	l.size = 0;
	return l;
}

void
listadd(List *l, void *data)
{
	ListNode * node = (ListNode*)malloc(sizeof(ListNode));
	node->data=data;
	node->next=nil;
	node->prev=nil;
	
	if(l->size > 0){
		ListNode * next = l->tail;
		next->prev = node;
		node->next = next;
		l->tail=node;
	}else{
		l->head=node;
		l->tail=node;
	}
	l->size++;
}

void
listdel(List *l, void * data, int(*comp)(void *, void *))
{
	ListNode *todel = listfind(l, data, comp);
	todel->next->prev = todel->prev;
	todel->prev->next = todel->next;
	free(todel);
	l->size--;
}

void *
car(List *l)
{
	/* Recommendation is to cast at data return */
	return l->head->data;
}

List *
cdr(List *l)
{
	if(l->size > 1){
		List *ret = (List*)malloc(sizeof(List));
		/* TODO deep copy, don't want to modify original list
			jk it's a shallow copy, don't try this at home */

		ret->head = l->head->prev;
		ret->tail = l->tail;

		ret->size = l->size-1;
		return ret;
	}else{
		return l;
	}
}

ListNode *
listfind(List *l, void * data, int(*comp)(void *, void *))
{
	/* if they want to search, search from the oldest item */
	ListNode *node = l->head;
	if(!(*comp)(node->data, data))
		return l->head;

	if(l->size > 1){
		/* Circle \Cir"cle\, v. t. [imp. & p. p. Circled; p. pr. & vb. n. */
		node = node->prev;
		while((*comp)(node->data, l->head->data) != 0){
			if(!(*comp)(node->data, data))
				return node;
		}
	}

	return nil;
}
