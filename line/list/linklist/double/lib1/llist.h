#ifndef LLIST_H__
#define LLIST_H__
#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2
struct llist_node_st
{
    void * data; //void *，可以指向任何类型的数据
    struct llist_node_st *prev;//指向前一个节点
    struct llist_node_st *next;//指向后一个节点
    
};

typedef struct llist_head_st //链表头结构
{
    int size;
    struct llist_node_st head;
}LLIST;
typedef void llist_op(const void *);
LLIST* llist_create(int initsize);
int llist_insert(LLIST *, const void *data, int mode);//mode:0头插 1尾插
/*
llist_find(LLIST *, const void *key, llist_cmp *cmp);
llist_destory(LLIST *);
llist_delete(LLIST *, const void *key, llist_cmp *cmp);
llist_fetch(LLIST *, const void *key, llist_cmp *cmp);
*/
void llist_destory(LLIST *);
void llist_travel(LLIST *, llist_op *op);


#endif