#ifndef OPTLIB_H
# define OPTLIB_H

#include "../myLib.h"
#include "../ft_system.h"

# define BAD_OPT(str) {dprintf(2, "Bad option %s\n", str);}
# define TOO_MUCH_OPT {dprintf(2, "Too much option\n"); return (-1);}

typedef u_int64_t optType_t;

typedef struct s_optlist
{
  char      *shortOpt;
  char      *longOpt;
  bool      present;
  optType_t type;
  bool      optArg;
  char      *optArgValue;
  struct s_optlist *next;
} t_optlist;

typedef struct s_argList
{
  u_int16_t index;
  u_int16_t r_index;
  char *arg;
  struct s_argList *prev;
  struct s_argList *next;
} t_arglist;

t_optlist   *ft_initOptl(char *programOpt);
int8_t      ft_getopt(int argc, char **argv, t_optlist **optList, t_arglist **argList);
void        freeOptlist(t_optlist *optl);

int8_t      addArgList(t_arglist *argList, char *arg);
int8_t      ft_initArgList(t_arglist **argList);
void        ft_freeArgList(t_arglist *argList);

#endif
