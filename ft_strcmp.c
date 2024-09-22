#include "myLib.h"

int8_t
ft_strcmp(const char *str1, const char *str2)
{
	char *tmpstr1 = (char*)str1;
	char *tmpstr2 = (char*)str2;

  if (str1 == NULL && str2 == NULL)
    return (0);
  if (str1 == NULL || str2 == NULL)
    return (1);

	while (*tmpstr1 && *tmpstr2 && *tmpstr1 == *tmpstr2) {
		tmpstr1++;
		tmpstr2++;
	}

  if (*tmpstr1 == 0)
    return (*tmpstr2);
  if (*tmpstr2 == 0)
    return (*tmpstr1);
	return (1);
}
