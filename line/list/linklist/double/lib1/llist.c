#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <string.h>
struct llist_node_st
{
    struct llist_node_st *prev;//指向前一个节点
    struct llist_node_st *next;//指向后一个节点 
    char data[0];//柔性数组
};

struct llist_head_st //链表头结构
{
    int size;
    struct llist_node_st head;
    // int (*insert)(LLIST *,const void *,int);
    // void *(*find)(LLIST *,const void *,llist_cmp *);
    // int (*delete)(LLIST *,const void *,llist_cmp *);
    // int (*fetch)(LLIST *,const void *,llist_cmp *,void *);
    // void (*travel)(LLIST *,llist_op *);
};

LLIST* llist_create(int initsize){
    struct llist_head_st *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    new->size = initsize;
    new->head.prev=&new->head;
    new->head.next=&new->head;//循环链表
    return new;
}


int llist_insert(LLIST *p, const void *data, int mode){
    struct llist_node_st *newnode;
    struct llist_head_st *ptr = p;
    newnode = malloc(sizeof(*newnode)+ptr->size);
    if(newnode == NULL)
        return -1;
    if(newnode->data == NULL){
        free(newnode);
        return -1;
    }
    memcpy(newnode->data, data, ptr->size);
    if(mode == LLIST_FORWARD){
        newnode->prev = &ptr->head;
        newnode->next = ptr->head.next;
    }else if(mode == LLIST_BACKWARD){
        newnode->prev = ptr->head.prev;
        newnode->next = &ptr->head;
    }else{
        return -3;
    }
    newnode->prev->next = newnode; //这里是插入操作
    newnode->next->prev = newnode;
    return 0;
}

void llist_destory(LLIST *p){
    struct llist_node_st *cur,*next;
    struct llist_head_st *ptr = p;//带有头节点循环链表
    for(cur=ptr->head.next;cur!=&ptr->head;cur=next){//cur!=&ptr->head 保证了循环链表的遍历
        next=cur->next;
        free(cur);
    }
    free(ptr);
}

static struct llist_node_st* find_(struct llist_head_st *ptr,const void *key,llist_cmp *cmp){
    struct llist_node_st *cur;
    for(cur = ptr->head.next;cur!=&ptr->head;cur = cur->next){
        if(cmp(key,cur->data)==0)
            break;
    }
    return cur;
}

void * llist_find(LLIST *p, const void *key, llist_cmp *cmp){
    struct llist_head_st *ptr=p;
    struct llist_node_st *node;
    node = find_(ptr,key,cmp);
    if(node == &ptr->head)
        return NULL;
    return node->data;
}

int llist_delete(LLIST *p, const void *key, llist_cmp *cmp){
    struct llist_node_st *node;
    struct llist_head_st *ptr=p;
    node = find_(ptr,key,cmp);
    if(node == &ptr->head)
        return -1;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
}

int llist_fetch(LLIST *p, const void *key, llist_cmp *cmp,void *data){
    struct llist_node_st *node;
    struct llist_head_st *ptr = p;
    node = find_(ptr,key,cmp);
    if(node == &ptr->head)
        return -1;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if(data != NULL)
        memcpy(data,node->data,ptr->size);
    return 0;
}

void llist_travel(LLIST *p, llist_op *op){
    struct llist_node_st *cur;
    struct llist_head_st *ptr = p;
    for(cur=ptr->head.next;cur!=&ptr->head;cur=cur->next){
        op(cur->data);
}
}
