#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include "myLib.h"
#include "ft_vector.h"

struct truc{
    long a;
    long b;
};

int main(void)
{
  struct truc t[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  for (int i = 0; i < 4; i++)
  {
    dprintf(2, "%p\n", t + i);
  }
}
