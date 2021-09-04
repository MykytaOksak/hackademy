#include "../libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len = 0, s2_len = 0;
    while (s1[s1_len]) 
    { 
        s1_len++; 
    }
    while (s2[s2_len])
    { 
        s2_len++; 
    }

    char *res;
    if (!(res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
    {
        return NULL;
    }

    for (size_t i = 0; i < s1_len; i++)
    {
        res[i] = s1[i];
    }
    
    for (size_t i = s1_len; i < s1_len + s2_len; i++)
    {
        res[i] = s2[i - s1_len];
    }

    res[s1_len + s2_len] = '\0';

    return res;
}
