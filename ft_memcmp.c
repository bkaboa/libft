#include "myLib.h"

bool
ft_memcmp(const void *addr1, const void *addr2)
{
	char *str1 = (char*)addr1;
	char *str2 = (char*)addr2;

	while (*str1 && *str2 && *str1 == *str2) {
		++str1;
		++str2;
	}
	if (*str1 == 0)
		return (true);
	return (false);
}
