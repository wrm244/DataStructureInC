/*
 * @Author: wrm244 wrm244@outlook.com
 * @Date: 2023-06-23 15:40:15
 * @LastEditors: wrm244 wrm244@outlook.com
 * @LastEditTime: 2023-06-23 19:10:08
 * @FilePath: /list/linklist/simple/head/main.c
 * @Description: 链表测试主函数
 * 
 * Copyright © 2023 by RiverMountain, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    datatype arr[]={12,9,23,6,45,56};
    list *l;
    int i;
    l = list_create();
    if(l == NULL)
        exit(1);
    for(i = 0;i<sizeof(arr)/sizeof(*arr);i++)
    {
        if(list_order_insert(l,&arr[i]))
            exit(1);
    }

    datatype *num = malloc(sizeof(datatype*));
    list_delete_at(l,2,num);
    printf("[%s] *data = %d\n",__FUNCTION__,*num);
    list_display(l);
    list_destroy(l);
    exit(0);
}