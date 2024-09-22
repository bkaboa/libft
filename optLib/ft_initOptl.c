#include "optLib.h"

void freeOptlist(t_optlist *optl)
{
  t_optlist *tmp;
  t_optlist *tmp2 = optl;

  do {
    tmp = optl->next;
    free(optl);
    optl = tmp;
  } while (optl && optl != tmp2);
}

static void *optlError(t_optlist *optl, const char *functionName, char character)
{
  freeOptlist(optl);

  if (character == 0)
    dprintf(2, "%s: Invalid syntax at the end of the string\n", functionName);
  else
    dprintf(2, "%s: Invalid syntax next to '%c'\n", functionName, character);
  return (NULL);
}

static bool optlCheck(t_optlist *optl)
{
  t_optlist *tmp = optl->next;

  while (optl->next) {
    while (tmp) {
      if (tmp->shortOpt != NULL && optl->shortOpt != NULL)
        if (ft_strcmp(optl->shortOpt, tmp->shortOpt) == 0)
          return (false);
      if (tmp->longOpt != NULL && optl->longOpt != NULL)
        if (ft_strcmp(optl->longOpt, tmp->longOpt) == 0)
          return (false);
      tmp = tmp->next;
    }
    optl = optl->next;
  }
  return (true);
}

static t_optlist *addOptlist(t_optlist *optl)
{
  t_optlist *tmp;

  tmp = malloc(sizeof(t_optlist));
  if (tmp == NULL) {
    dprintf(2, "%s: malloc failed\n", __func__);
    return (NULL);
  }
  optl->next = tmp;
  return (tmp);
}

t_optlist *ft_initOptl(char *programOpt)
{
  t_optlist *optl;
  t_optlist *tmp;
  optType_t type = 1;

  if (programOpt == NULL || *programOpt == 0 || *programOpt == ',')
    return (NULL);

  optl = malloc(sizeof(t_optlist));
  if (optl == NULL)
    return (NULL);
  tmp = optl;

  while (*programOpt) {
    ft_memset(tmp, 0, sizeof(t_optlist));
    tmp->type = type;
    type <<= 1;
    if (*programOpt == '%') {
      tmp->optArg = true;
      programOpt++;
    }
    if (!(*programOpt)) {
      freeOptlist(optl);
      return (NULL);
    }
    else if (*programOpt != ':') {
      if (*programOpt == 0 || *programOpt == ',') {
        return (optlError(optl, __func__, *(programOpt - 1)));
      }
      tmp->shortOpt = programOpt;
      while (*programOpt && *programOpt != ':')
        programOpt++;
      if (*programOpt == ':') {
        *programOpt = '\0';
        programOpt++;
      }
    }
    else
      programOpt++;
    if (*programOpt != ',' && *programOpt != 0) {
      tmp->longOpt = programOpt;
      while (*programOpt && *programOpt != ',')
        programOpt++;
    }
    if (*programOpt == ',') {
      *programOpt = 0;
      programOpt++;
      if (*programOpt == 0){
        dprintf(2, "%c\n", *(programOpt - 1));
        return (optlError(optl, __func__, *programOpt));
      }
      tmp = addOptlist(tmp);
      if (tmp == NULL) {
        freeOptlist(optl);
        MALLOC_FAILED(__func__);
        return (NULL);
      }
    }
  }
  if (!optlCheck(optl)) {
    freeOptlist(optl);
    return (NULL);
  }
  tmp->next = optl;
  return (optl);
}
