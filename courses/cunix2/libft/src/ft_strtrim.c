#include "../libft.h"

char *ft_strtrim(char const *s)
{
    size_t s_len = 0;
    while (s[s_len]) 
    {
        s_len++;
    }

    size_t i = 0;
    size_t start_spaces = 0; // start space count    
    while (s[i])
    {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        {
            start_spaces++;
            i++;
        }
        else
        {
            break;
        }
    }

    if (start_spaces == s_len)
    {
        char *res = (char *)malloc(sizeof(char));
        res[0] = '\0';
        return res;
    }

    size_t k = s_len - 1; 
    size_t end_spaces = 0; // end space count
    while (k > start_spaces)
    {
        if (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
        {
            k--;
            end_spaces++;
        }
        else
        {
            break;
        }
    } 

    if (start_spaces == 0 && end_spaces == 0)
    {
        char *res = (char *)malloc(sizeof(char) * (s_len + 1));
        size_t i = 0;
        while(s[i])
        {
            res[i] = s[i];
            i++;
        }
        res[s_len] = '\0';
        return res;
    }

    char *res;
    size_t res_len = s_len - start_spaces - end_spaces;
    if (!(res = (char *)malloc(sizeof(char) * (res_len + 1))))
    {
        return NULL;
    }   

    for (size_t i = 0; i < res_len; i++)
    {
        res[i] = s[start_spaces + i];
    }
    res[res_len] = '\0';
    
    return res;   
}