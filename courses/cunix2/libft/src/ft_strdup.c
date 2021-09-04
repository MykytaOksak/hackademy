#include "../libft.h"

char *ft_strdup(const char *s)
{
    unsigned int s_len = strlen(s);
    char *c = (char *)malloc(sizeof(char) * (s_len + 1));

    size_t i = 0;
    for (i = 0; i < s_len; i++)
    {
        c[i] = s[i];
    }
    c[i] = '\0';

    return c;
}