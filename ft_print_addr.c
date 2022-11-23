/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:15:41 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/23 14:21:44 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addr_len(unsigned long addr)
{
	int	len;

	len = 0;
	while (addr != 0)
	{
		len++;
		addr = addr / 16;
	}
	return (len);
}

static void	ft_put_addr(unsigned long addr)
{
	if (addr >= 16)
	{
		ft_put_addr(addr / 16);
		ft_put_addr(addr % 16);
	}
	else
	{
		if (addr <= 9)
			ft_print_char(addr + '0');
		else
			ft_print_char(addr - 10 + 'a');
	}
}

int	ft_print_addr(unsigned long addr)
{
	int		len;

	len = 0;
	if (addr == 0)
		len += (write(1, "(nil)", 5));
	else
	{
		len += write(1, "0x", 2);
		ft_put_addr(addr);
		len += ft_addr_len(addr);
	}
	return (len);
}
