#include "../libft.h"

void *ft_memmove(void *dest, const void *src, size_t count)
{
    unsigned char *src_cpy = (unsigned char *)malloc(count);
    
    for (size_t i = 0; i < count; i++)
    {
        *(unsigned char *)(src_cpy + i) = *(unsigned char *)(src + i);
    }

    for (size_t i = 0; i < count; i++)
    {
        *(unsigned char *)(dest + i) = *(unsigned char *)(src_cpy + i);
    }    
    
    free(src_cpy);

    return dest;
}