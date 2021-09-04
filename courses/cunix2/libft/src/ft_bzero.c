#include "../libft.h"

void ft_bzero(void *s, size_t n)
{
    char *c = s;
    
    for (size_t i = 0; i < n; ++i)
    {
        c[i] = '\0';
    }
}