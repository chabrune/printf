/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:49:18 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/24 15:07:07 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb)
{
	if (nb < 0)
	{
		if (ft_print_char('-') <= 0)
			return (-1);
		nb = -nb;
	}
	if (nb <= 9)
	{
		if (ft_print_char(nb + 48) <= 0)
			return (-1);
	}
	else
	{
		if (ft_putnbr(nb / 10) == -1)
			return (-1);
		if (ft_putnbr(nb % 10) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_len(long long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_print_nbr(long long nbr)
{
	if (nbr == 0)
	{
		if (write(1, "0", 1) <= 0)
			return (-1);
		else
			return (1);
	}
	else
	{
		if (ft_putnbr(nbr) <= -1)
			return (-1);
	}
	return (ft_len(nbr));
}
