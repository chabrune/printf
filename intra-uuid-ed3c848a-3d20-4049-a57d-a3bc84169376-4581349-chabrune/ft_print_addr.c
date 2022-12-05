/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:15:41 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/29 15:42:20 by chabrune         ###   ########.fr       */
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

static int	ft_put_addr(unsigned long addr)
{
	if (addr >= 16)
	{
		ft_put_addr(addr / 16);
		ft_put_addr(addr % 16);
	}
	else
	{
		if (addr <= 9)
		{
			if (ft_print_char(addr + '0') <= 0)
				return (-1);
		}
		else
		{
			if (ft_print_char(addr - 10 + 'a') <= 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_print_addr(unsigned long addr)
{
	int	len;

	len = 0;
	if (addr == 0)
	{
		if (write(1, "0x0", 3) <= 0)
			return (-1);
		len += 3;
	}
	else
	{
		if (write(1, "0x", 2) <= 0)
			return (-1);
		len += 2;
		if (ft_put_addr(addr) == -1)
			return (-1);
		len += ft_addr_len(addr);
	}
	return (len);
}
