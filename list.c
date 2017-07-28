#include "dumb.h"

struct ListNode
{
	ListNode * prev;
	ListNode * next;
	void * data;
};

List mklist(void)
{
	List *ret = (List*)malloc(sizeof(List));
	
}

void listadd(List *l, void *data)
{
	
}

void * listdel(List *l, int n)
{
	
}

void * listget(List *l, int n)
{
	
}

void * car(List *l)
{
	/* Recommendation is to cast at data return */
	return l->head->data;
}

List * cdr(List *l)
{
	List *ret = (List*)malloc(sizeof(List));
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	/* deep copy, don't want to modify original list */
	
	
	ret->size = l->size-1;
	return ret;
}
