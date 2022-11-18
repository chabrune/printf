/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:02:18 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/18 14:17:55 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search_arg(va_list arg, const char *format, int *len)
{
	if (*format == 'd' || *format == 'i')
		printnbr(va_arg(arg, int), len);
	else if (*format == 's')
		printstr(va_arg(arg, char *), len);
	else if (*format == 'p')
		printaddr(va_arg(arg, unsigned long), "abcdef0123456789", len);
	else if (*format == 'u')
		printunbr(va_arg(arg, unsigned int), len);
	else if (*format == 'x')
		printnbrbase(va_arg(arg, unsigned int), "abcdef0123456789", len);
	else if (*format == 'X')
		printnbrbase(va_arg(arg, unsigned int), "ABCDEF0123456789", len);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	arg;
	int		*len;

    len = NULL;
	va_start(arg, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			ret += ft_search_arg(arg, format, len);
		else
			ret += write(1, &format[i], 1);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (*len);
		}
	}
	va_end(arg);
	return (*len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	ft_printf("Hello\n");
// 	printf("Hello\n");
// }

