#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

int main()
{
    int i,err;
    sqlist *list= NULL,*list1= NULL;
    datatype arr[]={12,23,34,45,56};
    datatype arr1[]={89,45,34,67,43,56,23};
    //list = sqlist_create();
    sqlist_create1(&list,6);
    if(list == NULL)
    {
        fprintf(stderr,"sqlist_create() failed!\n");
        exit(1);
    }
    
    list1 = sqlist_create(7);
    if(list1 == NULL)
    {
        fprintf(stderr,"sqlist_create() failed!\n");
        exit(1);
    }

    for(i = 0;i <sizeof(arr)/sizeof(*arr);i++)
    {
        if((err=sqlist_insert(list,0,&arr[i]))!=0)
        {
            if(err == -1)
                fprintf(stderr,"The sqlist is full!\n");
            else if(err ==-2)
                fprintf(stderr,"The pos you want to insert is wrong\n");
                else
                    fprintf(stderr,"Error!\n");
            exit(1);
        }
    }

    for(i = 0;i <sizeof(arr1)/sizeof(*arr1);i++)
    {
        if((err=sqlist_insert(list1,0,&arr1[i]))!=0)
        {
            if(err == -1)
                fprintf(stderr,"The sqlist is full!\n");
            else if(err ==-2)
                fprintf(stderr,"The pos you want to insert is wrong\n");
                else
                    fprintf(stderr,"Error!\n");
            exit(1);
        }
    }
    sqlist_display(list);
    sqlist_display(list1);
    //sqlist_destroy(list);
    //sqlist_destroy(list1);
    sqlist_union(list,list1);
    sqlist_display(list);
    exit(0);
}