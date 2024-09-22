#include "optLib.h"

static u_int8_t ft_getoptError(t_arglist *argList, t_optlist *optList, char *str)
{
  freeOptlist(optList);
  ft_freeArgList(argList);
  if (str != NULL)
    BAD_OPT(str)
  return (-1);
}

int8_t ft_getopt(int argc, char **argv, t_optlist **optList, t_arglist **argList)
{
  u_int16_t optind = 1;
  int i = 0;
  t_optlist *tmp = *optList;
  u_int8_t cmp = 0;

  if (argc >= INT_LEAST16_MAX)
    TOO_MUCH_OPT
  if  (ft_initArgList(argList) == -1) {
    freeOptlist(*optList);
    return (-1);
  }
  while (optind < argc) {
    if (argv[optind][i] == '-')
    {
      i++;
      if (argv[optind][i] == '-')
      {
        i++;
        *optList = tmp;
        do {
          cmp = ft_strcmp(&argv[optind][i], (*optList)->longOpt);
          if (cmp == 0 || cmp == '=' || ft_isspace(cmp))
          {
            (*optList)->present = true;
            break;
          }
          (*optList) = (*optList)->next;
        } while (*optList != tmp);
        if (cmp != 0 && cmp != '=' && !ft_isspace(cmp))
        {
          return (ft_getoptError(*argList, *optList, argv[optind]));
        }
      }
      else
      {
        *optList = tmp;
        do {
          cmp = ft_strcmp((*optList)->shortOpt, &argv[optind][i]);
          if (cmp == 0 || ft_isspace(cmp))
          {
            (*optList)->present = true;
            break;
          }
          (*optList) = (*optList)->next;
        }
        while (*optList != tmp);
        if (cmp)
        {
          return (ft_getoptError(*argList, *optList, argv[optind]));
        }
      }
      if  ((*optList)->optArg == true) {
        if (cmp == 0) {
          (*optList)->optArgValue = argv[++optind];
        }
        else {
          while (argv[optind][i] != cmp)
            i++;
          if (argv[optind][i + 1] != '\0')
            (*optList)->optArgValue = &argv[optind][++i];
        }
      }
      else if ((*optList)->optArg == false && cmp) {
        return (ft_getoptError(*argList, *optList, argv[optind]));
      }
      i = 0;
      cmp = 0;
      optind++;
    }
    else {
      if (addArgList(*argList, argv[optind]) == -1) {
        freeOptlist(*optList);
        ft_freeArgList(*argList);
        return (-1);
      }
      optind++;
    }
  }
  return (0);
}
