#include "../libft.h"

char *ft_strchr(const char *s, int c)
{
    if (c == 0) 
    {
        return (char *)(s + strlen(s));   
    }

    size_t i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c % 256)
        {
            return (char *)(s + i);
        }
        i++;
    } 
    
    return 0;
}