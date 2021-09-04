#include "../libft.h"

void ft_memcpy(void *dest, const void *src, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        *(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
    }
}