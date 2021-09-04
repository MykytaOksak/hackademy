#include "../libft.h"

char *ft_strrchr(const char *s, int c)
{
    if (c == 0) 
    {
        return (char *)(s + strlen(s));   
    }

    int i = strlen(s) - 1;
    while (i >= 0)
    {
        if (s[i] == c % 256)
        {
            return (char *)(s + i);
        }
        i--;
    } 
    
    return 0;
}