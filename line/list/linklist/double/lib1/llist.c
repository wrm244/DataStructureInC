#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <string.h>

LLIST* llist_create(int initsize){
    LLIST *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    new->size = initsize;
    new->head.data=NULL;
    new->head.prev=&new->head;
    new->head.next=&new->head;//循环链表
}// 1.分配空间 2.初始化头节点 3.返回头节点地址


int llist_insert(LLIST *ptr, const void *data, int mode){
     struct llist_node_st *newnode;
     newnode = malloc(sizeof(*newnode));
    if(newnode == NULL)
        return -1;
    newnode->data = malloc(ptr->size);
    if(newnode->data == NULL){
        free(newnode);
        return -2;
    }
    memcpy(newnode->data, data, ptr->size);
    if(mode == LLIST_FORWARD){
        newnode->prev = &ptr->head;
        newnode->next = ptr->head.next;
        newnode->next->prev = newnode;
        newnode->prev->next = newnode;
    }else if(mode == LLIST_BACKWARD){
        newnode->prev = ptr->head.prev;//头节点的前一个节点,也就是最后一个节点。
        newnode->next = &ptr->head;
        newnode->prev->next = newnode;
        newnode->next->prev = newnode;
    }else{
        return -3;
    }   
}

void llist_destory(LLIST *ptr){
    struct llist_node_st *cur,*next;
    for(cur=ptr->head.next;cur!=&ptr->head;cur=next){//cur!=&ptr->head 保证了循环链表的遍历
        next=cur->next;
        free(cur->data);
        free(cur);
    }
    free(ptr);
}
/*
llist_find(LLIST *, const void *key, llist_cmp *cmp);
llist_delete(LLIST *, const void *key, llist_cmp *cmp);
llist_fetch(LLIST *, const void *key, llist_cmp *cmp);
*/
void llist_travel(LLIST *ptr, llist_op *op){
    struct llist_node_st *cur;
    for(cur=ptr->head.next;cur!=&ptr->head;cur=cur->next){
        op(cur->data);
}
}