#ifndef LLIST_H__
#define LLIST_H__
#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

typedef void LLIST;

typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);

LLIST* llist_create(int initsize);
int llist_insert(LLIST *, const void *data, int mode);//mode:0头插 1尾插
void * llist_find(LLIST *, const void *key, llist_cmp *cmp);
int llist_delete(LLIST *, const void *, llist_cmp *);
int llist_fetch(LLIST *, const void *, llist_cmp *,void *);
void llist_travel(LLIST *, llist_op *op);
void llist_destory(LLIST *);

#endif