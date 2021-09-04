#include "../libft.h"
 
int ft_isalpha(int c)
{
    return (c >= 97 && c <= 122) || (c >= 65 && c <= 90);
} 