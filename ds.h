#ifndef DS_H
#define DS_H
#pragma lib "libds.a"
#include <u.h>
#include <libc.h>


/* assume amd64 i guess, do something about it */
typedef unsigned long long uint64;

/* who cares about C99 */
#define true 1
#define false 0
typedef int bool;

/* stack.c */
typedef struct Stack Stack;
typedef struct StackNode StackNode;

Stack mkstack(void);
void stackpush(Stack *, void *);
void * stackpop(Stack *);

struct Stack
{
	StackNode * top;
	uint64 size;
};

/* queue.c */
typedef struct Queue Queue;
typedef struct QueueNode QueueNode;

Queue mkqueue(void);
void enqueue(Queue *, void *);
void * dequeue(Queue *);

struct Queue
{
	QueueNode * head;
	QueueNode * tail;
	uint64 size;
};

/* list.c */
typedef struct List List;
typedef struct ListNode ListNode;

List mklist(void);
void listadd(List *, void *);
void listdel(List *, void *, int(*comp)(void *, void *));
void * car(List *);
List * cdr(List *);
ListNode * listfind(List *, void *, int(*comp)(void *, void *));

struct List
{
	ListNode * head;
	ListNode * tail;
	uint64 size;
};

#endif
