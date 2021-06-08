#include <stdlib.h>
#include <stdio.h>

struct node
{
  int d;
  struct node *next;
};

struct node *start = NULL;
struct node *create_node(int);
struct node *deleteNodes(struct node *list, int *arr, int n)
{
  struct node *temp, *r, *s;
  int j = 0, w = 1, flag = 0;

  temp = list;

  while (temp != NULL)
  {
    for (j = 0; j < n; j++)
    {
      if (temp->d == arr[j])
      {
        flag = 0;
        break;
      }
      else
        flag = 1;
    }
    if (flag)
    {
      struct node *new_node = create_node(temp->d);
      if (w) // this if for run only one time coz we have to make a head pointer
      {
        r = s = new_node;
        w = 0;
      }
      s->next = new_node;
      s = s->next;
    }
    temp = temp->next;
  }

  return r;
}

struct node *create_node(int item)
{
  struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
  n->d = item;
  n->next = NULL;
  return n;
}