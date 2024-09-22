#include "myLib.h"

int ft_putcf(const unsigned long c, int fd)
{
  return (write(fd, &c, 1));
}

int ft_putc(const unsigned long c)
{
  return (write(1, &c, 1));
}
