#include "optLib.h"

void ft_freeArgList(t_arglist *argList)
{
  t_arglist *tmp = NULL;
  while (argList != NULL) {
    tmp = argList;
    argList = argList->next;
    free(tmp);
  }
}

int8_t  ft_initArgList(t_arglist **argList)
{
  *argList = malloc(sizeof(t_arglist));
  if (*argList == NULL) {
    MALLOC_FAILED(__func__);
    return (-1);
  }
  (*argList)->arg = NULL;
  (*argList)->next = NULL;
  (*argList)->prev = NULL;
  (*argList)->index = 0;
  (*argList)->r_index = 0;
  return (0);
}

static void checkIndex(t_arglist *argList)
{
  int i = 0;
  t_arglist *tmp = argList;

  while (argList != NULL && ++i) {
    argList->index = i;
    argList = argList->next;
  }
  while (tmp != NULL) {
    tmp->r_index = i;
    tmp = tmp->next;
    i--;
  }
}

int8_t  addArgList(t_arglist *argList, char *arg)
{
  t_arglist *tmp = argList;

  if  (ft_strlen(arg) >= INT_LEAST16_MAX)
    return (-1);

  if (argList->arg) {
    while (argList->next != NULL)
      argList = argList->next;
    argList->next = malloc(sizeof(t_arglist));
    if (argList->next == NULL) {
      MALLOC_FAILED(__func__);
      return (-1);
    }
    argList = argList->next;
  }
  argList->arg = arg;
  argList->next = NULL;
  argList->prev = argList;
  checkIndex(tmp);

  return (0);
}
