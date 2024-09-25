#ifndef MYLIB_H
#define MYLIB_H

# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include <string.h>
# include <limits.h>
# include <time.h>

# include <netinet/in.h>

# include "ft_system.h"

# define MALLOC_FAILED(func) {dprintf(2, "Malloc error in %s\n", func);}

# define UNDEFINE   -1
# define SUCCESS    1
# define ERROR      -1
# define STOP       0

# define READ_SIZE 4096

# define IPV6_LENGTH 39
# define IPV6 128
# define IPV4 32

typedef unsigned __int128 u_int128_t;
typedef u_int16_t type_time_t;
typedef u_int32_t ip4_t;
typedef u_int128_t ip6_t;

void        *ft_realloc(void *ptr, size_t size);


void        showbitsUI( const u_int32_t x, char sep );
void        showbitsUL( const u_int64_t x, char sep );
void        showbitsC(const u_int8_t x, char sep);
void        ft_shownbits(void *ptr, size_t lenght);

void        ft_memset(void *ptr, const u_int8_t data, size_t lenght);
void        *ft_memcpy(void *dst0, const void *src0, size_t length);
bool        ft_memcmp(const void *addr1, const void *addr2);

int         ft_putcf(const unsigned long c, int fd);
int         ft_putc(const unsigned long c);

int         ft_atoi(char *str);

u_int32_t   ft_getip4(const char *str);
char        *ft_inet_ntoa(const struct in_addr ip);

void        *ft_findFirstOf(const char *str, char tofind);
void        *ft_findLastOf(const char *str, char tofind);
void        *findFirstNotOf(const char *str, char tofind);
void        *findLastNotOf(const char *str, char tofind);

u_int32_t   ft_htonl(u_int32_t addr);
int         ft_checkEndian(void);

bool        ft_isnumber(const char *str);
bool        ft_isdecimal(const char *str);
bool        ft_isdigit(const char c);
bool        ft_isalpha(const char c);
bool        ft_isascii(const char c);
bool        ft_isprint(const char c);
bool        ft_isspace(const char c);
bool        ft_islower(const char c);
bool        ft_isupper(const char c);
bool        ft_isblank(const char c);
bool        ft_iscntrl(const char c);
bool        ft_isgraph(const char c);
bool        ft_ispunct(const char c);
bool        ft_ishex(const char c);

double    ft_strtod(const char *str, char **endptr);
time_t    ft_strToTime(const char *str, type_time_t in, type_time_t out);
int8_t    ft_strcmp(const char *str1, const char *str2);
bool      ft_strictStrcmp(const char *str1, const char *str2);
size_t    ft_strlen(const char *str);
void      ft_strcat(const char *str1, char *buffer);
u_int8_t  hexchartonum(u_int8_t c);


#endif // !MY_LIB_H
