#include "libft.h"
#include "printf.h"
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_strchr(const char *s)
{
    if(!s)
        return((char*)s);
    while(*s)
    {
        if(*s == '%')
            return((char*)s)
        s++;
    }
    return(NULL);
}

void	ft_putnbr(int nb)
{
    long lnb;

    lnb = nb;
    if(lnb < 0)
    {
        ft_putchar('-');
        lnb = lnb * -1;
    }
    if(lnb > 9)
    {
        ft_putnbr(lnb / 10);
        ft_putnbr(lnb % 10);
    }
    else if
        ft_putchar(nbl + 48);
}

int ft_intlen(int nb, char c)
{
    if(c == 'x')

    if(c == 'd')
}

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

void	ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i])
        i++;
    }
}

const char *ft_search_arg(va_list arg, const char *format, t_print *sc)
{
    if(*format == 'd')
    {
        int d = va_arg(arg, int);
        ft_putnbr(d)
        sc->len += ft_intlen(d, *format);
    }
    else if (*format == 's')
    {
        char *s = va_arg(arg, char*)
        if(!s)
        {
            write(1, "(null)", 6);
            sc->len += 6;
        }
        else
        {
            ft_putstr(s);
            sc-> += ft_strlen(s);
        }
    }
    else if (*format == 'x')
    {
        unsigned int x = va_arg(arg, unsigned int);
        ft_printhexa((unsigned long)x);
        sc->len += ft_intlen((int)x, *format);
    }
    else
        return(NULL);
    format++;
    return (format);
}

const char *ft_read_text(t_print *sc, const char *format)
{
    char *next;

    next = ft_strchr(format);
    if (next)
        sc->widht = next - format;
    else
        sc->widht = ft_strlen(format);
    write(1, format, sc->widht);
    sc->len += sc->widht;
    while (*format && *format != '%')
        ++format;
    return(format);
}

int ft_printf(const char *format, ...)
{
    va_list(arg);
    va_start(arg, format);
    t_print sc;
    sc.len = 0;
    sc.widht = 0;

    while(*format)
    {
        if (*format == '%')
            format = ft_search_arg(arg, format + 1, &sc)
        else
            format = ft_read_text(&sc, format);
        if (!format)
        {
            write(1, "(null)", 6);
            va_end(arg);
            return(sc.len);
        }
    }
    va_end(arg);
    return(sc.len);
}