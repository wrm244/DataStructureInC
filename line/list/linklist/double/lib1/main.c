#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#define NAMESIZE 32
struct score_st{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};
void print_s(const void *data){
    struct score_st *d = data;//data是void类型的指针，所以要转换成struct score_st类型的指针
    printf("%d %s %d %d\n", d->id, d->name, d->math, d->chinese);
}
int main(){
    LLIST *handler;
    struct score_st tmp;
    int i;
    handler = llist_create(sizeof(struct score_st));
    if(handler == NULL)
        exit(1);
    for(i=0;i<7;i++){
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;
        if(llist_insert(handler, &tmp, LLIST_FORWARD) != 0)
            exit(1);
    }
    llist_travel(handler,print_s);
    llist_destory(handler);
    exit(0);
}