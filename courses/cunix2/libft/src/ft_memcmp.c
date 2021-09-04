#include "../libft.h"

int ft_memcmp(const void *p1, const void *p2, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (*(unsigned char *)(p1 + i) != *(unsigned char *)(p2 + i))
        {
            return *(unsigned char *)(p1 + i) < *(unsigned char *)(p2 + i) ? -1 : 1;
        }
    }
    return 0;
}