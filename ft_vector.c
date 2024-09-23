#include "ft_vector.h"

void    vector_init(vector_t *v)
{
    v->vectorData.items = malloc(sizeof(void *) * VECTOR_INIT_CAPACITY);
    v->vectorData.capacity = VECTOR_INIT_CAPACITY;
    v->vectorData.size = 0;
    v->back = vector_back;
    v->size = vector_size;
    v->capacity = vector_capacity;
    v->empty = vector_empty;
    v->get = vector_get;
    v->pushBack = vector_pushBack;
    v->pushFront = vector_pushFront;
    v->insert = vector_insert;
    v->popBack = vector_popBack;
    v->popFront = vector_popFront;
    v->remove = vector_remove;
    v->destructor = vector_destruct;
}

void    *vector_back(vector_t *v)
{
    if (v->vectorData.size == 0)
        return (NULL);
    return (v->vectorData.items[v->vectorData.size - 1]);
}

size_t  vector_size(vector_t *v)
{
    return (v->vectorData.size);
}

void    *vector_get(vector_t *v, int at)
{
    if (at < 0 || at >= v->vectorData.size)
        return (NULL);
    return (v->vectorData.items[at]);
}

size_t  vector_capacity(vector_t *v)
{
    return (v->vectorData.capacity);
}

bool    vector_empty(vector_t *v)
{
    return (v->vectorData.size == 0);
}

int     vector_pushBack(vector_t *v, void *item)
{
    if (v->vectorData.size == v->vectorData.capacity)
    {
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.capacity *= 2;
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
    }
    v->vectorData.items[v->vectorData.size++] = item;
    return (0);
}

int     vector_pushFront(vector_t *v, void *item)
{
    if (v->vectorData.size == v->vectorData.capacity)
    {
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.capacity *= 2;
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
    }
    for (size_t i = v->vectorData.size; i > 0; i--)
        v->vectorData.items[i] = v->vectorData.items[i - 1];
    v->vectorData.items[0] = item;
    v->vectorData.size++;
    return (0);
}

void   vector_popBack(vector_t *v)
{
    if (v->vectorData.size == 0)
        return ;
    v->vectorData.size--;
}

void    vector_popFront(vector_t *v)
{
    if (v->vectorData.size == 0)
        return ;
    for (size_t i = 0; i < v->vectorData.size - 1; i++)
        v->vectorData.items[i] = v->vectorData.items[i + 1];
    v->vectorData.size--;
}

void    vector_remove(vector_t *v, int at)
{
    if (at < 0 || at >= v->vectorData.size)
        return ;
    for (size_t i = at; i < v->vectorData.size - 1; i++)
        v->vectorData.items[i] = v->vectorData.items[i + 1];
    v->vectorData.size--;
}

void    vector_destruct(vector_t *v)
{
    free(v->vectorData.items);
    v->vectorData.items = NULL;
    v->vectorData.capacity = 0;
    v->vectorData.size = 0;
}

int    vector_insert(vector_t *v, void *item, int at)
{
    if (at < 0 || at >= v->vectorData.size)
        return (-1);
    if (v->vectorData.size == v->vectorData.capacity)
    {
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.capacity *= 2;
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
    }
    for (size_t i = v->vectorData.size; i > at; i--)
        v->vectorData.items[i] = v->vectorData.items[i - 1];
    v->vectorData.items[at] = item;
    v->vectorData.size++;
    return (0);
}
