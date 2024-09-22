#ifndef FT_SYSTEM_H
# define FT_SYSTEM_H

# include <sys/param.h>
# include <endian.h>

# define UNKNOWN 0

/* system type */
# define __LINUX 1
# define __UNIX 2

/* arch type */
# define __ARM64 1
# define __X86_64 2
# define __I386 3

# ifdef __linux__
  #  define OS __LINUX
# elif __unix__
  #  define OS __UNIX
# else
  #  define OS UNKNOWN
# endif

# ifdef __AARCH64EL__
  #  define ARCH __ARM64
# elif __x86_64__
  #  define ARCH __X86_64
# elif __i386__
  #  define ARCH __I386
# else
  #  define ARCH UNKNOWN
# endif

# ifdef __BYTE_ORDER
  # if __BYTE_ORDER == __LITTLE_ENDIAN
    #  define ENDIAN __LITTLE_ENDIAN
  # elif __BYTE_ORDER == __BIG_ENDIAN
    #  define ENDIAN __BIG_ENDIAN
  # elif __BYTE_ORDER == __PDP_ENDIAN
    #  define ENDIAN __PDP_ENDIAN
  # endif
# endif

#endif // !#ifndef FT_SYSTEM_H
