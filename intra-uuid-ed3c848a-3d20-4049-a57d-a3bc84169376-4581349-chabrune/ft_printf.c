/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:02:18 by chabrune          #+#    #+#             */
/*   Updated: 2022/12/01 17:44:11 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search_arg(va_list arg, const char *format)
{
	int	len;

	len = 0;
	if (*format == 'd' || *format == 'i')
		len += ft_print_nbr(va_arg(arg, int));
	else if (*format == 'c')
		len += ft_print_char(va_arg(arg, int));
	else if (*format == 's')
		len += ft_print_str(va_arg(arg, char *));
	else if (*format == 'p')
		len += ft_print_addr(va_arg(arg, unsigned long));
	else if (*format == 'x')
		len += ft_print_nbr_hexa(va_arg(arg, unsigned int), 0);
	else if (*format == 'X')
		len += ft_print_nbr_hexa(va_arg(arg, unsigned int), 1);
	else if (*format == '%')
		len += ft_print_percent();
	else if (*format == 'u')
		len = ft_print_u_nbr(va_arg(arg, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	int		len;
	int		temp;

	temp = 0;
	i = 0;
	len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = ft_search_arg(arg, &format[i + 1]);
			i++;
		}
		else
			temp = write(1, &format[i], 1);
		i++;
		len += temp;
		if (temp <= -1)
			return (-1);
	}
	va_end(arg);
	return (len);
}
