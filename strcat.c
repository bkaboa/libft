#include "myLib.h"

void ft_strcat(const char *str1, char *buffer)
{
  if (str1 == NULL || buffer == NULL)
    return ;
  while (*buffer)
    buffer++;
  while (*str1)
    *buffer++ = *str1++;
  *buffer = 0;
}
