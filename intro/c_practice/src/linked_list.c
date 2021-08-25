#include "linked_list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double_linked_list * make_list() {
  double_linked_list * ret = malloc(sizeof(double_linked_list));
  ret->first = NULL;
  ret->last = NULL;

  return ret;
}

void insert_after(double_linked_list * list,
		  double_linked_node * node,
		  double_linked_node * new_node)
{
  new_node->prev = node;
  if (node->next == NULL) {
    new_node->next = NULL;
    list->last = new_node;
  } else {
    new_node->next = node->next;
    node->next->prev = new_node;
  }
  node->next = new_node;
}

void  insert_before(double_linked_list * list,
		    double_linked_node * node,
		    double_linked_node * new_node)
{
  new_node->next = node;
  if (node->prev == NULL) {
    new_node->prev = NULL;
    list->first = new_node;
  } else {
    new_node->prev = node->prev;
    node->prev->next = new_node;
  }
  node->prev = new_node;
}

void insert_beginning(double_linked_list * list, double_linked_node * new_node)
{
  if (list->first == NULL) {
    list->first = new_node;
    list->last = new_node;
    new_node->prev = NULL;
    new_node->next = NULL;
  } else {
    insert_before(list, list->first, new_node);
  }
}

void insert_end(double_linked_list * list, double_linked_node * new_node)
{
  if (list->last == NULL) {
    insert_beginning(list, new_node);
  } else {
    insert_after(list, list->last, new_node);
  }
}

// Function to add an entry to a linked list
// For now, it will just add it to the end
double_linked_node * find(double_linked_list * dll, char * string) {
  double_linked_node * cursor = dll->first;
  while (cursor != NULL) {
    if (strcmp(string, cursor->value) == 0) {
      break;
    }
    cursor = cursor->next;
  }
  return cursor;
}

void print_list(double_linked_list * ll) {

  double_linked_node * cursor = ll->first;
  if (cursor == NULL) {
    printf("<EMPTY LIST>\n");
    return;
  }

  while (cursor != NULL) {
    printf("%s\n", cursor->value);
    cursor = cursor->next;
  }
}

void remove_node(double_linked_list * list, double_linked_node * node)
{
  if (node->prev == NULL) {
    list->first = node->next;
  } else {
    node->prev->next = node->next;
  }

  if (node->next == NULL) {
    list->last = node->prev;
  } else {
    node->next->prev = node->prev;
  }

  free(node->value);
  free(node);
}

double_linked_node * create_node(const char * string) {
   // Make a new node
  double_linked_node * new_node = (double_linked_node*) malloc(sizeof(double_linked_node));
  char * new_str = (char*) malloc(sizeof(char) * (strlen(string) + 1));
  strncpy(new_str, string, strlen(string));
  new_node->value = new_str;
  return new_node;
}


int main(int argc, char* argv[]) {

  double_linked_list * list = make_list();

  printf("Should be empty:\n");
  print_list(list);

  printf("------------\n");
  insert_beginning(list, create_node("Hello"));
  insert_end(list, create_node("World"));
  print_list(list);

  printf("------------\n");
  double_linked_node * spot = find(list, "World");
  insert_before(list, spot, create_node("Cruel"));
  print_list(list);

  printf("------------\n");
  double_linked_node * spot2 = find(list, "World");
  remove_node(list, spot2);
  print_list(list);

  printf("------------\n");
  double_linked_node * spot3 = find(list, "Hello");
  remove_node(list, spot3);
  print_list(list);
  
}
