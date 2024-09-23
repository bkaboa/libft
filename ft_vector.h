#ifndef FT_VECTOR_H
# define FT_VECTOR_H
# include "myLib.h"

# define MAX_VECTOR_CAPACITY    0x1000000
# define VECTOR_INIT_CAPACITY   6
# define VECTOR_INIT(vec) vector_t vec;\
    vector_init(&vec)

typedef struct vectorData {
    void    **items;
    size_t  capacity;
    size_t  size;
}   vectorData_t;

typedef struct string_t vector_t;

typedef struct vector {
    vectorData_t    vectorData;
    void    *(*front)(struct vector*);
    void    *(*back)(struct vector*);
    size_t  (*size)(struct vector*);
    size_t  (*capacity)(struct vector*);
    bool    (*empty)(struct vector*);
    void    *(*get)(struct vector*);
    void    (*pushBack)(struct vector*, void *);
    void    (*pushFront)(struct vector*, void *);
    int     (*insert)(struct vector*, void *, int);
    void    (*popBack)(struct vector*);
    void    (*popFront)(struct vector*);
    int     (*remove)(struct vector*, int);
    void    (*destructor)(struct vector*);
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

#endif // !FT_VECTOR_H