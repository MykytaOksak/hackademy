#include "../printf.h"

void ft_printf(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    int minus_flag = 0, plus_flag = 0, zero_flag = 0, space_flag = 0; 
    size_t str_len = ft_strlen(format);            
    
    for (size_t i = 0; i < str_len; i++)
    {
        if (format[i] == '%' && i != str_len - 1)
        {
            i++;
            
            while (format[i] == ' ') // skip all spaces
            {
                space_flag = 1;
                i++;
            }
            
            // determine flags
            while (format[i] == '-' || format[i] == '+' || format[i] == '0')
            {
                if (format[i] == '-') 
                { 
                    minus_flag = 1; 
                }
                if (format[i] == '+') 
                { 
                    plus_flag = 1; 
                }
                if (format[i] == '0') 
                { 
                    zero_flag = 1; 
                }
                i++;
            }
            
            while (format[i] == ' ') // skip all spaces
            {
                space_flag = 1;
                i++;
            }
            
            // determine field width
            int field_width = 0;
            while (format[i] >= '0' && format[i] <= '9') // is num in range [0-9]
            {
                char *digit_str = (char *)malloc(2 * sizeof(char));
                digit_str[0] = format[i];
                digit_str[1] = '\0';
                field_width = field_width * 10 + ft_atoi(digit_str);
                free(digit_str);
                i++;
            }
            
            // determine format
            if (format[i] == '%')
            {
                write(1, &format[i], 1);
            }
            else
            {
                char *output = NULL;
                if (format[i] == 's')
                {
                    output = va_arg(arg, char *);
                }
                else if (format[i] == 'c')
                {
                    output = (char *)malloc(2 * sizeof(char));
                    output[0] = va_arg(arg, int);
                    output[1] = '\0';
                }
                else if (format[i] == 'd' || format[i] == 'i')
                {
                    int num = va_arg(arg, int);
                    output = ft_itoa(num);
                    
                    if (plus_flag)
                    {
                        if (num >= 0)
                        { 
                            write(1, "+", 1); 
                        }
                        
                        field_width--;
                    }

                    // if num is positive and here is a space before it
                    if (space_flag && num >= 0) 
                    {
                        write(1, " ", 1); // print 1 space char 
                        field_width--;
                    }
                }
                
                if (!output) // if NULL passed as argument 
                { 
                    output = "(null)"; 
                } 

                if (field_width != 0)
                {
                    size_t str_len = (format[i] == 'c' && output[0] == 0) ? 1 : ft_strlen(output);
                    int diff = field_width - str_len; // how many spaces 
                    if (diff > 0) // print with spaces
                    {
                        char *space = (char *)malloc(2 * sizeof(char));
                        space[0] = zero_flag ? '0' : ' '; // determine space char
                        space[1] = '\0';
                        
                        if (minus_flag) // left-aligned 
                        {
                            write(1, output, ft_strlen(output));
                            
                            while (diff-- > 0) 
                            { 
                                write(1, space, 1); 
                            } 
                        }
                        else // right-aligned 
                        {
                            if (ft_atoi(output) < 0 && zero_flag) // print - before "0..0"
                            {
                                write(1, "-", 1);
                                //free(output);
                                output = ft_itoa(ft_atoi(output) * -1);
                                str_len--;
                            }

                            while (diff-- > 0) 
                            { 
                                write(1, space, 1); 
                            } 

                            write(1, output, str_len);
                        }
                        
                        free(space);
                    }
                    else // default print
                    {
                        write(1, output, ft_strlen(output));
                    }
                }
                else // default print
                {
                    write(1, output, ft_strlen(output));
                }

                // if malloc was called -> free the memory
                if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i')
                {
                    free(output);
                }
            }
        }
        else
        {
            write(1, &format[i], 1);
        }
    }

    va_end(arg);
} 