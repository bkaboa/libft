#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  dprintf(2, "%zu\n", strlen("2001:0db8:0000:85a3:0000:0000:ac1f:8001"));
}
