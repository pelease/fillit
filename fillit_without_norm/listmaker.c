#include "fillit.h"

v_list      *init_list()
{
    v_list    *lst;

    lst = (v_list*)malloc(sizeof(v_list));
    lst->next = NULL;
    lst->prev = NULL;
    return(lst);
}

v_list      *addelem(v_list *lst)
{
    v_list  *temp, *p;
    temp = (v_list*)malloc(sizeof(v_list));
    p = lst->next;
    lst->next = temp;
    temp->next = p;
    temp->prev = lst;
    if (p != NULL)
        p->prev = temp;
    return(temp);
}

v_list     *deletelem(v_list *lst)
{
  v_list *prev, *next;
  prev = lst->prev;
  next = lst->next;
  if (prev != NULL)
    prev->next = lst->next;
  if (next != NULL)
    next->prev = lst->prev;
  free(lst);
  return(prev);
}

void      points(v_list **lst)
{
  while ((*lst)->prev)
  {
    (*lst)->x = -1;
    (*lst)->y = -1;
    (*lst) = (*lst)->prev;
  }
  (*lst)->x = -1;
  (*lst)->y = -1;
}