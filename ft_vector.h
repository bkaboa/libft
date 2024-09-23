#ifndef FT_VECTOR_H
# define FT_VECTOR_H
# include "myLib.h"

# define MAX_VECTOR_CAPACITY    0x1000000
# define VECTOR_INIT_CAPACITY   6

typedef struct vectorData {
    void    **items;
    size_t  capacity;
    size_t  size;
}   vectorData_t;

typedef struct vector {
    vectorData_t    vectorData;
    void    *(*front)(struct vector*);
    void    *(*back)(struct vector*);
    size_t  (*size)(struct vector*);
    size_t  (*capacity)(struct vector*);
    bool    (*empty)(struct vector*);
    void    *(*get)(struct vector*, int at);
    int     (*pushBack)(struct vector*, void *item);
    int     (*pushFront)(struct vector*, void *);
    int     (*insert)(struct vector*, void *, int);
    void    (*popBack)(struct vector*);
    void    (*popFront)(struct vector*);
    void    (*remove)(struct vector*, int);
    void    (*destructor)(struct vector*);
    void    *(*findFirstOf)(struct vector*, void *tofind);
    void    *(*findLastOf)(struct vector*, void *tofind);
    void    *(*findFirstNotOf)(struct vector*, void *tofind);
    void    *(*findLastNotOf)(struct vector*, void *tofind);
    void    (*print_string)(struct vector*);
    int     (*insert_string)(struct vector*, char *, int);
    int     (*pushBack_string)(struct vector*, char *);
    int     (*pushFront_string)(struct vector*, char *);
}   vector_t;

void    vector_init(vector_t *v);
void    *vector_front(vector_t *v);
void    *vector_back(vector_t *v);
void    *vector_get(vector_t *v, int at);
size_t  vector_size(vector_t *v);
size_t  vector_capacity(vector_t *v);
bool    vector_empty(vector_t *v);
int     vector_pushBack(vector_t *v, void *item);
int     vector_pushFront(vector_t *v, void *item);
void    vector_popBack(vector_t *v);
void    vector_popFront(vector_t *v);
void    vector_remove(vector_t *v, int at);
void    vector_destruct(vector_t *v);
int     vector_insert(vector_t *v, void *item, int at);
void    *vector_findFirstOf(vector_t *v, void *tofind);
void    *vector_findLastOf(vector_t *v, void *tofind);
void    *vector_findFirstNotOf(vector_t *v, void *tofind);
void    *vector_findLastNotOf(vector_t *v, void *tofind);

void    string_print(vector_t *v);
int     string_insert(vector_t *v, char *str, int at);
int     string_pushBack(vector_t *v, char *str);
int     string_pushFront(vector_t *v, char *str);

# define VECTOR_INIT(vec) vector_t vec;\
    vector_init(&vec)

#endif // !FT_VECTOR_H