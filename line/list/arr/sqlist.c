#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

/**
 * @description: 指针函数初始化顺序线性表
 * @param {int} n
 * @return {sqlist} *
 */
sqlist *sqlist_create(int n)
{
    sqlist *me = NULL;
    me = malloc(sizeof(*me));
    me->data = malloc(sizeof(datatype)*n);
    if (me == NULL)
        return NULL;
    me->last = -1;
    return me;
}

/**
 * @description: 不带返回值初始化顺序线性表，这里双指针**ptr的意思是对指针的地址进行改变
 * @param {sqlist} **ptr
 * @param {int} n
 * @return {*}
 */
void sqlist_create1(sqlist **ptr,int n)

{
    *ptr = malloc(sizeof(**ptr));
    (*ptr)->data = malloc(sizeof(datatype)*n);
    if (*ptr == NULL)
        return;
    (*ptr)->last = -1;
    return;
}

/**
 * @description: 对线性表的插入
 * @param {sqlist} *me
 * @param {int} i
 * @param {datatype} *data
 * @return {*}
 */
int sqlist_insert(sqlist *me, int i, datatype *data)
{
    int j;
    if (me->last == DATASIZE - 1)
        return -1;
    if (i < 0 || i > me->last + 1)
        return -2;

    for (j = me->last; i <= j; j--)
        me->data[j + 1] = me->data[j];
    me->data[i] = *data;
    me->last++;
    return 0;
}
/**
 * @description: 线性表某个i位置元素进行删除
 * @param {sqlist} *me
 * @param {int} i
 * @return {*}
 */
int sqlist_delete(sqlist *me, int i)
{
    int j;
    if (i < 0 || i > me->last)
        return -1;
    for (j = i + 1; j <= me->last; j++)
        me->data[j - 1] = me->data[j];
    me->last--;
    return 0;
}
/**
 * @description: 查找匹配元素的位置下标
 * @param {sqlist} *me
 * @param {datatype} *data
 * @return {int}
 */
int sqlist_find(sqlist *me, datatype *data)
{
    int i;
    if (sqlist_isempty == 0)
        return -1;
    for (i = 0; i < me->last; i++)
        if (me->data[i] == *data)
            return i;
    return -2;
}
/**
 * @description: 判断线性表是否为空
 * @param {sqlist} *me
 * @return {int}
 */
int sqlist_isempty(sqlist *me)
{
    if (me->last = -1)
        return 0;
    return -1;
}
/**
 * @description: 清空线性表
 * @param {sqlist} *me
 * @return {int}
 */
int sqlist_setempty(sqlist *me)
{
    me->last = -1;
    return 0;
}
/**
 * @description: 查看线性表长度
 * @param {sqlist} *me
 * @return {int}
 */
int sqlist_getnum(sqlist *me)
{
    return (me->last + 1);
}

/**
 * @description: 组合两个线性表返回给list1
 * @param {sqlist} *list1
 * @param {sqlist} *list2
 * @return {int}
 */
int sqlist_union(sqlist *list1, sqlist *list2)
{
    int i = 0;
    while (i <= list2->last)
    {
        if (sqlist_find(list1, &list2->data[i]) < 0)
        {
            sqlist_insert(list1,i,&list2->data[i]);
        }
        i++;
    }
}

/**
 * @description: 显示线性表内容
 * @param {sqlist} *me
 * @return {void}
 */
void sqlist_display(sqlist *me)
{
    int i;
    if (me->last == -1)
        return;
    for (i = 0; i <= me->last; i++)
        printf("%d ", me->data[i]);
    printf("\n");
    return;
}
/**
 * @description: 销毁线性表内容
 * @param {sqlist} *me
 * @return {int} 成功返回0
 */
int sqlist_destroy(sqlist *me)
{
    free(me);
    return 0;
}