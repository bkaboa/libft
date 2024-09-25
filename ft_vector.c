#include "ft_vector.h"

void    vector_init(vector_t *v)
{
    v->vectorData.items = malloc(sizeof(void *) * VECTOR_INIT_CAPACITY);
    v->vectorData.capacity = VECTOR_INIT_CAPACITY;
    v->vectorData.size = 0;
    v->back = vector_back;
    v->front = vector_front;
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
    v->findFirstOf = vector_findFirstOf;
    v->findLastOf = vector_findLastOf;
    v->findFirstNotOf = vector_findFirstNotOf;
    v->findLastNotOf = vector_findLastNotOf;
    v->print_string = string_print;
    v->insert_string = string_insert;
    v->pushBack_string = string_pushBack;
    v->pushBack_n_string = string_n_pushBack;
    v->pushFront_string = string_pushFront;
}

void    *vector_back(vector_t *v)
{
    if (v->vectorData.size == 0)
        return (NULL);
    return (v->vectorData.items + v->vectorData.size - 1);
}

void    *vector_front(vector_t *v)
{
    if (v->vectorData.size == 0)
        return (NULL);
    return (v->vectorData.items);
}

size_t  vector_size(vector_t *v)
{
    return (v->vectorData.size);
}

void    *vector_get(vector_t *v, int at)
{
    if (at < 0 || at >= v->vectorData.size)
        return (NULL);
    return (v->vectorData.items + at);
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
        v->vectorData.capacity *= 2;
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
        if (v->vectorData.items == NULL)
            return (-1);
    }
    v->vectorData.items[v->vectorData.size++] = item;
    return (0);
}

int     vector_pushFront(vector_t *v, void *item)
{
    if (v->vectorData.size == v->vectorData.capacity)
    {
        v->vectorData.capacity *= 2;
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
        if (v->vectorData.items == NULL)
            return (-1);
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
        v->vectorData.capacity *= 2;
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
        if (v->vectorData.items == NULL)
            return (-1);
    }
    for (size_t i = v->vectorData.size; i > at; i--)
        v->vectorData.items[i] = v->vectorData.items[i - 1];
    v->vectorData.items[at] = item;
    v->vectorData.size++;
    return (0);
}

void    string_print(vector_t *v)
{
    for (size_t i = 0; i < v->vectorData.size; i++)
        printf("%c", v->vectorData.items[i]);
    printf("\n");
}

void *vector_findFirstOf(vector_t *v, void *tofind)
{
    for (size_t i = 0; i < v->vectorData.size; i++)
    {
        dprintf(2, "%p\n", v->vectorData.items + i);
        if (v->vectorData.items[i] == tofind)
            return (v->vectorData.items + i);
    }
    return (NULL);
}

void *vector_findLastOf(vector_t *v, void *tofind)
{
    for (size_t i = v->vectorData.size - 1; i >= 0; i--)
        if (v->vectorData.items[i] == tofind)
            return (&v->vectorData.items[i]);
    return (NULL);
}

void *vector_findFirstNotOf(vector_t *v, void *tofind)
{
    for (size_t i = 0; i < v->vectorData.size; i++)
        if (v->vectorData.items[i] != tofind)
            return (&v->vectorData.items[i]);
    return (NULL);
}

void *vector_findLastNotOf(vector_t *v, void *tofind)
{
    for (size_t i = v->vectorData.size - 1; i >= 0; i--)
        if (v->vectorData.items[i] != tofind)
            return (&v->vectorData.items[i]);
    return (NULL);
}

int   string_insert(vector_t *v, char *item, int at)
{
    long tmp;
    if (at < 0 || at >= v->vectorData.size)
        return (-1);
    size_t len = ft_strlen(item);
    if(len == 0 || v->vectorData.size + len >= MAX_VECTOR_CAPACITY)
        return (-1);
    if (v->vectorData.size + len >= v->vectorData.capacity)
    {
        v->vectorData.capacity = (v->vectorData.size + len) * 2;
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
        if (v->vectorData.items == NULL)
            return (-1);
    }
    for (int i = v->vectorData.size + len - 1; i >= at + len; i--)
        v->vectorData.items[i] = v->vectorData.items[i - len];
    for (int i = 0; i < len; i++)
    {
        tmp = 0;
        tmp = tmp | item[i];
        v->vectorData.items[at + i] = (void*)tmp;
    }
    v->vectorData.size += len;
}

int string_pushBack(vector_t *v, char *item)
{
    long tmp;
    size_t len = ft_strlen(item);
    if(len == 0)
        return (-1);
    if (v->vectorData.size + len >= v->vectorData.capacity)
    {
        v->vectorData.capacity = (v->vectorData.size + len) * 2;
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
        if (v->vectorData.items == NULL)
            return (-1);
    }
    for (int i = 0; i < len; i++)
    {
        tmp = 0;
        tmp = tmp | item[i];
        v->vectorData.items[v->vectorData.size + i] = (void*)tmp;
    }
    dprintf(2, "truc\n");
    v->vectorData.size += len;
    return (0);
}

int string_pushFront(vector_t *v, char *item)
{
    long tmp;
    size_t len = ft_strlen(item);
    if(len == 0)
        return (-1);
    if (v->vectorData.size + len >= v->vectorData.capacity)
    {
        v->vectorData.capacity = (v->vectorData.size + len) * 2;
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
        if (v->vectorData.items == NULL)
            return (-1);
    }
    for (int i = v->vectorData.size + len - 1; i >= len; i--)
        v->vectorData.items[i] = v->vectorData.items[i - len];
    for (int i = 0; i < len; i++) {
        tmp = 0;
        tmp = tmp | item[i];
        v->vectorData.items[i] = (void*)tmp;
    }
    v->vectorData.size += len;
    return (0);
}

int pushBack_n_string(vector_t *v, char *item, size_t n)
{
    long tmp;
    if(n == 0)
        return (-1);
    if (v->vectorData.size + n >= v->vectorData.capacity)
    {
        v->vectorData.capacity = (v->vectorData.size + n) * 2;
        if (v->vectorData.capacity >= MAX_VECTOR_CAPACITY)
            return (-1);
        v->vectorData.items = ft_realloc(v->vectorData.items, sizeof(void *) * v->vectorData.capacity);
        if (v->vectorData.items == NULL)
            return (-1);
    }
    for (int i = 0; i < n; i++)
    {
        tmp = 0;
        tmp = tmp | item[i];
        v->vectorData.items[v->vectorData.size + i] = (void*)tmp;
    }
    v->vectorData.size += n;
    return (0);
}
