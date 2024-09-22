#include "myLib.h"

char *ft_strsjoin(const char **strs)
{
  char *str;
  char **tmp;
  int nchar = 0;

  tmp = (char**)strs;
  if (tmp == NULL)
      return (NULL);
  while (*tmp)
    nchar += ft_strlen(*tmp++);

  str = malloc(sizeof(char) * (nchar));
  if (str == NULL)
    return (NULL);
  ft_memset(str, 0, nchar);

  tmp = (char**)strs;
  while (*tmp)
    ft_strcat(*tmp++, str);
  return (str);
}
