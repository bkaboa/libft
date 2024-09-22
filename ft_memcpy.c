#include "myLib.h"

typedef	int word;

#define	wsize	sizeof(word)
#define	wmask	(wsize - 1)

void * ft_memcpy(void *dst0, const void *src0, size_t length)
{
    char *dst = dst0;
    const char *src = src0;
    size_t t;

    if (length == 0 || dst0 == src0)
        return (dst0);
    if (src0 == NULL)
        return (NULL);

#define	TLOOP(s) if (t) TLOOP1(s)
#define	TLOOP1(s) do { s; } while (--t)

    if ((unsigned long)dst < (unsigned long)src) {
        t = (uintptr_t)src;
        if ((t | (uintptr_t)dst) & wmask)
        {
            if ((t ^ (uintptr_t)dst) & wmask || length < wsize)
                t = length;
            else
                t = wsize - (t & wmask);
            length -= t;
            TLOOP1(*dst++ = *src++);
        }
        t = length / wsize;
        TLOOP(*(word *)dst = *(word *)src; src += wsize; dst += wsize);
        t = length & wmask;
        TLOOP(*dst++ = *src++);
    } else {
        src += length;
        dst += length;
        t = (uintptr_t)src;
        if ((t | (uintptr_t)dst) & wmask) {
            if ((t ^ (uintptr_t)dst) & wmask || length <= wsize)
                t = length;
            else
                t &= wmask;
            length -= t;
            TLOOP1(*--dst = *--src);
        }
        t = length / wsize;
        TLOOP(src -= wsize; dst -= wsize; *(word *)dst = *(word *)src);
        t = length & wmask;
        TLOOP(*--dst = *--src);
    }
    return (dst0);
}
