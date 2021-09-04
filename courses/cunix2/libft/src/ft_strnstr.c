#include "../libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    if (*needle == '\0')
    {
        return (char *)haystack;
    }

    if ((int)len < 0)
    {
        len = strlen(haystack) + (int)len * -1;
    }

    for (size_t i = 0; i < len; i++)
    {
        if (haystack[i] == '\0')
        {
            break;
        }
        if (haystack[i] == needle[0])
        {
            size_t haystack_i = i; 
            for (size_t j = 0; j < strlen(needle); j++)
            {

                if (haystack_i >= len)
                {
                    break;
                }

                if (needle[j] != haystack[haystack_i])
                {
                    break;
                }

                if (j == strlen(needle) - 1)
                {
                    return (char *)(haystack + i);
                }

                haystack_i++;
            }
        }
    }

    return NULL;
}