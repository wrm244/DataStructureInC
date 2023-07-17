// #define NDEBUG // disables assert()
#include "nohead.h"
#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

int main(int argc, char *argv[]) {
  struct node_st *list = NULL;
  struct score_st tmp;
  int i;
  for (i = 0; i < 7; i++) {

    tmp.id = i;
    snprintf(tmp.name, NAMESIZE, "stu%d", i);
    tmp.math = rand() % 100;
    tmp.chinese = rand() % 100;
    int ret = list_insert(&list, &tmp);
    if (ret != 0) {
      exit(-1);
    }
  }
  list_show(list);
  int id = 90;
  struct node_st *ptr;
  ptr = list_find(list, id);
  if (ptr == NULL) {
    printf("Can't find!");
  } else {
    printf("%s\n", ptr->data.name);
  }
  list_destroy(list);
  return EXIT_SUCCESS;
}
