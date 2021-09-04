#include "../libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
    size_t s_len = 0;
    while (s[++s_len]) {}

    char* res = (char *)malloc(sizeof(char) * (s_len + 1));

    for (size_t i = 0; i < s_len; i++)
    {
        res[i] = f(s[i]);
    } 
    res[s_len] = '\0';

    return res;
}