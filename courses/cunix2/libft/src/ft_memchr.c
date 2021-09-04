#include "../libft.h"

void *ft_memchr(const void *src, int c, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (*(unsigned char *)(src + i) == (unsigned char)(c))
        {
            return (void *)(src + i);
        }
    }

    return NULL;
}