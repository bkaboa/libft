#include "myLib.h"

bool ft_isnumber(const char *str)
{
  int i = 0;
  if (str == NULL)
    return (false);
  while (str[i] != '\0')
  {
      if (str[i] < '0' || str[i] > '9')
        return false;
      i++;
  }
  if (i <= 0)
    return (false);
  return true;
}

bool
ft_isdecimal(const char *str)
{
  void *dec_addr = NULL;
	void *exp_addr = NULL;
  char *tmp = (char*)str;

  if (tmp == NULL)
    return (false);

  while (*tmp)
  {
    if (*tmp < '0' || *tmp > '9') {
      if (*tmp == '.') {
        if (dec_addr) {
          return (false);
        }
        dec_addr = tmp;
      }
			else if (*tmp == 'e' || *tmp == 'E') {
			  if (exp_addr)
				  return (false);
			  exp_addr = tmp;
		  }
      else
        return (false);
    }
    tmp++;
  }

  if (dec_addr == tmp || dec_addr == NULL)
    return (false);

  return (true);
}


bool
ft_isdigit(const char c)
{
  if (c >= '0' && c <= '9')
    return true;
  return false;
}

bool
ft_isalpha(const char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return true;
  return false;
}

bool
ft_isalnum(const char c)
{
  if (ft_isdigit(c) || ft_isalpha(c))
    return true;
  return false;
}

bool
ft_isascii(const char c)
{
  if (c >= 0 && c <= 127)
    return true;
  return false;
}

bool
ft_isprint(const char c)
{
  if (c >= 32 && c <= 126)
    return true;
  return false;
}

bool
ft_isspace(const char c)
{
  if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
    return true;
  return false;
}

bool
ft_islower(const char c)
{
  if (c >= 'a' && c <= 'z')
    return true;
  return false;
}

bool
ft_isupper(const char c)
{
  if (c >= 'A' && c <= 'Z')
    return true;
  return false;
}

bool
ft_isblank(const char c)
{
  if (c == ' ' || c == '\t')
    return true;
  return false;
}

bool
ft_iscntrl(const char c)
{
  if (c >= 0 && c <= 31)
    return true;
  return false;
}

bool
ft_isgraph(const char c)
{
  if (c >= 33 && c <= 126)
    return true;
  return false;
}

bool
ft_ispunct(const char c)
{
  if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
    return true;
  return false;
}

bool
ft_ishex(const char c)
{
  if (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
    return true;
  return false;
}
