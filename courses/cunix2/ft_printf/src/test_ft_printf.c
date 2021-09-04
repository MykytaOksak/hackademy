#include <stdio.h>
#include <string.h>
#include "../printf.h"

int main()
{
    char str1[100];
    char str2[100];

    // TEST 1

    int str_len1 = sprintf(str1, "%3d", -123456789);
    int str_len2 = ft_sprintf(str2, "%3d", -123456789);

    if (!strcmp(str1, str2) && str_len1 == str_len2)
    {
        printf("TEST 1: OK\n");
    }
    else
    {
        printf("TEST 1: KO");
    }

    // TEST 2

    str_len1 = sprintf(str1, "%05d", 10);
    str_len2 = ft_sprintf(str2, "%05d", 10);

    if (!strcmp(str1, str2) && str_len1 == str_len2)
    {
        printf("TEST 2: OK\n");
    }
    else
    {
        printf("TEST 2: KO");
    }

    // TEST 3

    str_len1 = sprintf(str1, "%10s", "Hello");
    str_len2 = ft_sprintf(str2, "%10s", "Hello");

    if (!strcmp(str1, str2) && str_len1 == str_len2)
    {
        printf("TEST 3: OK\n");
    }
    else
    {
        printf("TEST 3: KO");
    }

    // TEST 4

    str_len1 = sprintf(str1, "{%+03d}", 123456);
    str_len2 = ft_sprintf(str2, "{%+03d}", 123456);

    if (!strcmp(str1, str2) && str_len1 == str_len2)
    {
        printf("TEST 4: OK\n");
    }
    else
    {
        printf("TEST 4: KO");
    }
    
    // TEST 5

    str_len1 = sprintf(str1, "%05d", 10);
    str_len2 = ft_sprintf(str2, "%05d", 10);

    if (!strcmp(str1, str2) && str_len1 == str_len2)
    {
        printf("TEST 5: OK\n");
    }
    else
    {
        printf("TEST 5: KO");
    }

    return 0;
}