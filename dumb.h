#ifndef DUMB_H
#define DUMB_H
#pragma lib "libdumb.a"

#ifdef __unix__
#include <stdio.h>
#include <stdlib.h>
#define nil ((void*)0)
#define print(format, ...) fprintf(stdout, format, ##__VA_ARGS__)
#else
	#ifdef __WIN32__
	#include <stdio.h>
	#include <stdlib.h>
	#define nil ((void*)0)
	#define print(format, ...) fprintf(stdout, format, ##__VA_ARGS__)
	#else
	#include <u.h>
	#include <libc.h>
	#endif
#endif

/* avoid using u.h, assume amd64 */
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
void * listdel(List *, int);
void * listget(List *, int);
void * car(List *);
List * cdr(List *);

struct List
{
	ListNode * head;
	ListNode * tail;
	uint64 size;
};

#endif
