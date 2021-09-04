#include "../libft.h"

void *ft_memset(void *s, int c, unsigned int len)
{
    char *p = s;

    while (len--)
    {
        *p++ = (char)c;
    }

    return s;
}