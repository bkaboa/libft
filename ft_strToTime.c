#include "myLib.h"

time_t
ft_strToTime(const char *str, type_time_t in, type_time_t out)
{
  double time = 0;

  time = ft_strtod(str, NULL);
  if (in &! out) {
    while (!(in & out)) {
		  in >>= 1;
		  time *= 1000;
    }
  }
  else {
    while (in &! out) {
		  in <<= 1;
		  time /= 1000;
    }
  }
  return ((time_t)time);
}
