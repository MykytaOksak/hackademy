#include "../libft.h"

char **ft_strsplit(char const *s, char c)
{
    int word_count = 1;
    size_t i = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            i++;
        }
        else
        {
            word_count++;
            while (s[i] != c && s[i])
            {
                i++;
            }
        }
    }
    
    char **array;
    if (!(array = (char **)malloc(sizeof(char *) * (word_count))))
    {
        return NULL;
    }
    

    i = 0;
    size_t word_length = 0, k = 0; 
    while (s[k])
    {
        if (s[k] == c) // skip delim char
        {
            k++;
        }
        else // if a non-delim char is found
        {
            word_length = 0;
            size_t t = k;
            while (s[t] != c && s[t]) // count word length
            {
                word_length++;
                t++;
            }
            char *word;
            if(!(word = (char *)malloc(sizeof(char) * word_length + 1)))
            {
                return NULL;
            }
            
            size_t j = 0;
            while (j < word_length) // save current word
            {
                word[j] = s[k++];
                j++;
            }
            word[word_length] = '\0';
            array[i] = word; //save word to array
            i++;
        }
    }
    array[word_count - 1] = NULL;

    return array;
}