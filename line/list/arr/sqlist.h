/*
 * @Author: wrm244 wrm244@outlook.com
 * @Date: 2023-06-22 16:37:43
 * @LastEditors: wrm244 wrm244@outlook.com
 * @LastEditTime: 2023-06-22 21:28:01
 * @FilePath: /arr/sqlist.h
 * @Description: 对顺序线性表的头文件，主要描述了线性表结构体与函数
 * 
 * Copyright © 2023 by RiverMountain, All Rights Reserved. 
 */
#ifndef sqlist_H__
#define sqlist_H__
#define DATASIZE 1024
typedef int datatype;

/**
 * @description: 顺序线性表结构体包含元素指针与元素下标
 * @param *data,last;
 */
typedef struct {
    datatype *data;
    int last;
}sqlist;

sqlist *sqlist_create(int);
void sqlist_create1(sqlist **,int);
int sqlist_insert(sqlist *,int i,datatype *);
int sqlist_delete(sqlist *,int i);
int sqlist_find(sqlist *,datatype *);
int sqlist_isempty(sqlist *);
int sqlist_setempty(sqlist *);
int sqlist_getnum(sqlist *);
int sqlist_union(sqlist *,sqlist*);
void sqlist_display(sqlist *);
int sqlist_destroy(sqlist *);

#endif
