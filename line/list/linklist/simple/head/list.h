/*
 * @Author: wrm244 wrm244@outlook.com
 * @Date: 2023-06-23 15:40:08
 * @LastEditors: wrm244 wrm244@outlook.com
 * @LastEditTime: 2023-06-23 19:10:52
 * @FilePath: /list/linklist/simple/head/list.h
 * @Description:  线性表的链式表示声明函数与数据结构
 * 
 * Copyright © 2023 by RiverMountain, All Rights Reserved. 
 */
#ifndef LIST_H__
#define LIST_H__

typedef int datatype;

typedef struct list
{
    datatype data;
    struct list *next;
}list;

list *list_create();

int list_insert_at(list *,int ,datatype *);
int list_order_insert(list *,datatype *);
int list_delete_at(list *,int i,datatype *);
int list_delete(list *,datatype *);
int list_isempty(list *);
void list_display(list *);
void list_destroy(list *);


#endif