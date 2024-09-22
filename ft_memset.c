#include "myLib.h"

void ft_memset(void *ptr, const u_int8_t data, size_t lenght)
{
  u_int8_t *strPtr = (u_int8_t*)ptr;

  while (lenght-- > 0)
    *strPtr++ = data;
}
