#include "../libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    size_t s_len = 0;
    while (s[++s_len])
    {
    }

    if (start > s_len)
    {
        char *res = (char *)malloc(sizeof(char));
        res[0] = '\0';
        return res;
    }

    char *res;
    size_t res_len;
    if (start + len > s_len)
    {
        res_len = s_len - start;
    }
    else
    {
        res_len = len;
    }

    if (!(res = (char *)malloc(sizeof(char) * ((res_len) + 1))))
    {
        return NULL;
    }

    size_t i = 0;
    for (; i < res_len; i++)
    {
        res[i] = s[start + i];
    }
    res[i] = '\0';

    return res;
}