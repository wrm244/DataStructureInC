#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <string.h>
#define NAMESIZE 32
struct score_st{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};
static void print_s(const void *data){
    struct score_st *d = data;//data是void类型的指针，所以要转换成struct score_st类型的指针
    printf("%d %s %d %d\n", d->id, d->name, d->math, d->chinese);
}
static int id_cmp(const void *key,const void *record){
    const int *k = key;
    const struct score_st *r = record;
    return (*k - r->id);
}
static int name_cmp(const void *key,const void *record){
    const char *k = key;
    const struct score_st *r = record;
    return strcmp(k,r->name);
}
int main(){
    LLIST *handler;
    struct score_st tmp;
    int i,ret=0;
    handler = llist_create(sizeof(struct score_st));
    if(handler == NULL)
        exit(1);
    for(i=0;i<7;i++){
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;
        ret = llist_insert(handler,&tmp,LLIST_FORWARD);
        if(ret)
            exit(1);
    }
    llist_travel(handler,print_s);
    #if 0
    int id = 3;
    char *del_name="stu7";
    int ret = llist_delete(handler,del_name,name_cmp);
    if(ret)
        printf("Can not find!\n");
    else
        llist_travel(handler,print_s);
    
    printf("\n");
    int id = 30;
    struct score *data;
    data = llist_find(handler,&id,id_cmp);
    if(data == NULL)
        printf("Can not find!\n");
    else
        print_s(data);
    #endif
    llist_destory(handler);
    exit(0);
}