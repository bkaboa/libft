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

# define UNDEFINE	-1
# define SUCCESS	1

# define LONG_OPT	258
# define NON_OPT	257

# define MAX_VECTOR_CAPACITY	0x1000000
# define VECTOR_INIT_CAPACITY	6
# define VECTOR_INIT(vec) vector_t vec;\
	vector_init(&vec)

# define IPV6_LENGTH 39
# define IPV6 128
# define IPV4 32

enum Time {
    T_usec	=	0b1,
    T_msec	=	0b10,
    T_sec	=	0b100,
};




typedef u_int16_t argType_t;
typedef unsigned __int128 u_int128_t;
typedef u_int16_t type_time_t;
typedef u_int32_t ip4_t;
typedef u_int128_t ip6_t;
typedef char* string_t;

typedef struct ArgType {
  unsigned Neg :1;
  unsigned Arg_uint8 :1;
  unsigned Arg_uint16 :1;
  unsigned Arg_uint32 :1;
  unsigned Arg_uint64 :1;
  unsigned Arg_float :1;
  unsigned Arg_ip4 :1;
  unsigned Arg_ip6 :1;
  unsigned Arg_string :1;

  union {
    long Neg;
    u_int8_t Arg_uint8;
    u_int16_t Arg_uint16;
    u_int32_t Arg_uint32;
    u_int64_t Arg_uint64;
    double Arg_float;
    ip4_t Arg_ip4;
    ip6_t Arg_ip6;
  } u ;

}	ArgType_t;

typedef struct longopt {
    char			*opt;
    bool			arg;
    bool			present;
    char			*optarg;
    struct longopt 	*next;
}	longopt_t;

typedef struct vectorData {
	void	**items;
	size_t	capacity;
	size_t	size;
}	vectorData_t;

typedef struct vector {
	vectorData_t	vectorData;
	void	  *(*back)(struct vector*);
	void	  *(*front)(struct vector*);

	size_t	(*size)(struct vector*);
	size_t	(*capacity)(struct vector*);
	bool	  (*empty)(struct vector*);

	void	  *(*get)(struct vector*);

	void	  (*pushBack)(struct vector*, void *);
	void	  (*pushFront)(struct vector*, void *);
	int 	  (*insert)(struct vector*, void *, int);
	void	  (*popBack)(struct vector*);
	void	  (*popFront)(struct vector*);
	int 	  (*remove)(struct vector*, int);
	void	  (*destructor)(struct vector*);
}	vector_t;

typedef struct optl {
    longopt_t	*longopts;
    int			opt;
    int			opterr;
    int			optind;
    int			optopt;
    char		*optarg;
}	optl_t;




extern int	ft_optind;
extern int	nonopt;
extern char	*ft_optarg;
extern int	argError;
extern optl_t optl;




void		  *ft_getarg(argType_t argType, char *arg);

void		  showbitsUI( const u_int32_t x, char sep );
void		  showbitsUL( const u_int64_t x, char sep );
void		  showbitsC(const u_int8_t x, char sep);
void		  ft_shownbits(void *ptr, size_t lenght);

void		  ft_memset(void *ptr, const u_int8_t data, size_t lenght);
void		  *ft_memcpy(void *dst0, const void *src0, size_t length);
bool      ft_memcmp(const void *addr1, const void *addr2);

int			  ft_putcf(const unsigned long c, int fd);
int			  ft_putc(const unsigned long c);

int			  ft_atoi(char *str);

u_int32_t	ft_getip4(const char *str);
char	    *ft_inet_ntoa(const struct in_addr ip);

void		  *ft_findFirstOf(const char *str, char tofind);
void		  *ft_findLastOf(const char *str, char tofind);
void		  *findFirstNotOf(const char *str, char tofind);
void		  *findLastNotOf(const char *str, char tofind);

u_int32_t	ft_htonl(u_int32_t addr);
int			  ft_checkEndian(void);

bool		  ft_isnumber(const char *str);
bool		  ft_isdecimal(const char *str);
bool		  ft_isdigit(const char c);
bool      ft_isalpha(const char c);
bool      ft_isascii(const char c);
bool      ft_isprint(const char c);
bool		  ft_isspace(const char c);
bool      ft_islower(const char c);
bool      ft_isupper(const char c);
bool      ft_isblank(const char c);
bool      ft_iscntrl(const char c);
bool      ft_isgraph(const char c);
bool      ft_ispunct(const char c);
bool      ft_ishex(const char c);

double		ft_strtod(const char *str, char **endptr);
time_t		ft_strToTime(const char *str, type_time_t in, type_time_t out);
int8_t		ft_strcmp(const char *str1, const char *str2);
bool		  ft_strictStrcmp(const char *str1, const char *str2);
size_t		ft_strlen(const char *str);
void		  ft_strcat(const char *str1, char *buffer);
u_int8_t  hexchartonum(u_int8_t c);

void		  vector_init(vector_t *v);
void		  *vector_back(vector_t *v);
void		  *vector_front(vector_t *v);
void		  *vector_get(vector_t *v, int at);
size_t		vector_size(vector_t *v);
size_t		vector_capacity(vector_t *v);
bool		  vector_empty(vector_t *v);
int			  vector_pushBack(vector_t *v, void *item);
int			  vector_pushFront(vector_t *v, void *item);
void		  vector_popBack(vector_t *v);
void		  vector_popFront(vector_t *v);
void		  vector_remove(vector_t *v, int at);
void		  vector_destruct(vector_t *v);
int			  vector_insert(vector_t *v, void *item, int at);

#endif // !MY_LIB_H
