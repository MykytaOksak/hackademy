#include "../libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
    if (*s2 == '\0')
    {
        return (char *)s1;
    }

    for (size_t i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == s2[0])
        {    
            int s1_i = i;        
            for (size_t k = 0; k < strlen(s2); k++)
            {
                if (s1[s1_i++] != s2[k])
                {        
                    break;
                }
                if (k == strlen(s2) - 1)
                {
                    return (char *)(s1 + i);
                }
            }  
        }      
    }
 
    return NULL;
}