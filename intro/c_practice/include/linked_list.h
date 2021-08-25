#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct _double_linked_node {

  struct _double_linked_node * prev;
  struct _double_linked_node * next;
  char * value;

} double_linked_node;

typedef struct _double_linked_list {

  double_linked_node * first;
  double_linked_node * last;

} double_linked_list;

#endif 
