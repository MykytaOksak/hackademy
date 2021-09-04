#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_abs(int n);
div_t ft_div(int numer, int denom);
char* ft_strstr(const char *s1, const char *s2);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
void *ft_memset(void *s, int c,  unsigned int len);
void ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t count);
void *ft_memchr(const void *src, int c, size_t n);
int ft_memcmp(const void *p1, const void *p2, size_t count);
void ft_striter(char *s, void (*f)(char *));
char *ft_strmap(char const *s, char (*f)(char));
char *ft_strsub(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s);
char **ft_strsplit(char const *s, char c);


