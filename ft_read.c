#include "libft.h"

int    ft_read_bin(int fd, vector_t *v, size_t sizeToRead)
{
    static char        buffer[READ_SIZE] = {0};
    static int         index = 0;

    if (sizeToRead == 0)
        return (SUCCESS);
    while (true) {
        if (index) {
            if (index - sizeToRead >= 0) {
                v->pushBack_n_string(v, buffer + index, sizeToRead);
                index -= sizeToRead;
                return (SUCCESS);
            }
            else if (index - sizeToRead < 0) {
                v->pushBack_n_string(v, buffer + index, READ_SIZE - index);
                sizeToRead -= ~index + 1;
            }
        }
        index = read(fd, buffer, READ_SIZE);
        if (index == 0)
            return (STOP);
        if (index < 0)
            return (ERROR);
    }
}