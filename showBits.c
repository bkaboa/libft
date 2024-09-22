#include "myLib.h"

void showbitsUI( const u_int32_t x, char sep )
{
  int i=0;
  for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
  {
    ft_putc(x & (1u << i) ? '1' : '0');
    if (i % 8 == 0 && i != 0)
      ft_putc(sep);
  }
  ft_putc('\n');
}

void showbitsUL( const u_int64_t x, char sep )
{
  int i=0;
  for (i = (sizeof(long) * 8) - 1; i >= 0; i--)
  {
    ft_putc(x & (1ul << i) ? '1' : '0');
    if (i % 8 == 0 && i != 0)
      ft_putc(sep);
  }
  ft_putc('\n');
}

void showbitsC(const u_int8_t x, char sep)
{
  int i = 0;
  for (i = 7; i >= 0; i--)
  {
    ft_putc(x & (1 << i) ? '1' : '0');
  }
  ft_putc(sep);
}

void ft_shownbits(void *ptr, size_t lenght)
{
  int i = 0;
  char *str = (char*)ptr;

  while (i < lenght)
  {
    showbitsC(*str++, ' ');
    i++;
  }
}
