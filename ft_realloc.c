#include "myLib.h"

void    *ft_realloc(void *ptr, size_t size)
{
    void    *newPtr;

    if (size == 0)
    {
        free(ptr);
        return (NULL);
    }
    newPtr = malloc(size);
    if (newPtr == NULL)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (newPtr);
    ft_memcpy(newPtr, ptr, size);
    free(ptr);
    return (newPtr);
}