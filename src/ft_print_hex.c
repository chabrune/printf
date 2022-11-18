#include "printf.h"
#include "libft.h"

int ft_hex_len(unsigned int num)
{
    int len;

    len = 0;
    while(num != 0)
    {
        len++;
        num /= 16;
    }
    return(len);
}

void ft_put_hex(unsigned int num, const char format)
{
    if(num >= 16)
    {
        ft_put_hex(num / 16, format);
        ft_put_hex(num % 16, format);
    }
    else
    {
        
    }

}
