/*
 * @Author: wrm244 wrm244@outlook.com
 * @Date: 2023-06-23 15:39:56
 * @LastEditors: wrm244 wrm244@outlook.com
 * @LastEditTime: 2023-06-26 08:52:25
 * @FilePath: /ds/line/list/linklist/simple/head/list.c
 * @Description: 链式线性表的具体方法实现
 *
 * Copyright © 2023 by RiverMountain, All Rights Reserved.
 */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @description: 初始化线性表
 * @return {list} *
 */
list *list_create() {
  list *me;
  me = malloc(sizeof(*me));
  me->next = malloc(sizeof(
      *me)); // 即使你没有这个语句，程序也可能会执行成功。但是，这是不安全的，因为
             // me->next 将是一个野指针，无法使用。因此，你需要为
             // me->next 分配内存空间。
  printf("[%s] me->next->next = %p", __FUNCTION__, me->next->next);
  if (me == NULL)
    return NULL;
  me->next = NULL;
  return me;
}
/**
 * @description: 基于序列插入数值
 * @param {list} *me
 * @param {int} i
 * @param {datatype} *data
 * @return {int} 成功返回0，不成功返回其余值
 */
int list_insert_at(list *me, int i, datatype *data) {
  int j = 0;
  list *node = me, *newnode; // 代替me防止修改到原指针
  if (i < 0)
    return -1;
  while (j < i && node != NULL) { // 钱去节点
    node = node->next;
    j++;
  }
  if (node) {
    newnode = malloc(sizeof(*newnode));
    if (newnode == NULL)
      return -2;
    newnode->data = *data;

    newnode->next = node->next; // 这句话在第一次头节点next为空的情况下是废话
    node->next = newnode;
    return 0;
  } else {
    return -3;
  }
}

/**
 * @description: 插入的话区分上面尾插法头插法，在按顺序插入比较符合生产
 * @param {list} *me
 * @param {datatype} *data
 * @return {int} 成功返回0，不成功返回其余值
 */
int list_order_insert(list *me, datatype *data) {
  list *p = me, *q;
  while (p->next && p->next->data < *data)
    p = p->next;
  q = malloc(sizeof(*q));
  if (q == NULL)
    return -1;
  q->data = *data;
  q->next = p->next;
  p->next = q;
  return 0;
}
int list_delete_at(list *me, int i, datatype *data) {
  int j = 0;
  list *p = me, *q;
  if (i < 0)
    return -1;
  while (j < i && p) {
    p = p->next;
    j++;
  }
  if (p) {
    q = p->next;
    *data = q->data;
    p->next = q->next;
    free(q);
    q = NULL;
    return 0;
  }
  return -2;
}
int list_delete(list *me, datatype *data) {
  list *p = me, *q;
  while (p->next && p->next->data != *data) // 找到相等的前驱结点
    p = p->next;
  if (p->next == NULL)
    return -1;
  else {
    q = p->next;
    p->next = q->next;
    free(q);
    q = NULL;
  }
  return 0;
}
int list_isempty(list *me) {
  if (me->next == NULL) {
    return 0;
  }
  return 1;
}
void list_display(list *me) {
  list *node = me->next; // 头节点
  if (list_isempty(me) == 0)
    return;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}
void list_destroy(list *me) {
  list *node = me, *next;
  for (node = node->next; node != NULL; node = next) {
    next = node->next;
    free(node);
  }
  free(me);
  return;
}
