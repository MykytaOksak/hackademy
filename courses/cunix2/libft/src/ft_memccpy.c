#include "../libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        *(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
        if (*(unsigned char *)(src + i) == (unsigned char)(c))
        {
            return (void *)(dest + i + 1);
        }
    }

    return NULL;
}
