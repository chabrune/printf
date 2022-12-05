/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:59:26 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/29 15:42:23 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_hexa(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static int	ft_put_nbr_hexa_up(unsigned int nbr, int X)
{
	if (nbr >= 16)
	{
		if (ft_put_nbr_hexa_up(nbr / 16, X) == -1)
			return (-1);
		if (ft_put_nbr_hexa_up(nbr % 16, X) == -1)
			return (-1);
	}
	else
	{
		if (nbr <= 9)
		{
			if (ft_print_char(nbr + '0') <= -1)
				return (-1);
		}
		else
		{
			if (ft_print_char(nbr - 10 + 'A') <= -1)
				return (-1);
		}
	}
	return (0);
}

static int	ft_put_nbr_hexa_low(unsigned int nbr, int X)
{
	if (nbr >= 16)
	{
		if (ft_put_nbr_hexa_low(nbr / 16, X) == -1)
			return (-1);
		if (ft_put_nbr_hexa_low(nbr % 16, X) == -1)
			return (-1);
	}
	else
	{
		if (nbr <= 9)
		{
			if (ft_print_char(nbr + '0') <= -1)
				return (-1);
		}
		else
		{
			if (ft_print_char(nbr - 10 + 'a') <= -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_print_nbr_hexa(unsigned int nbr, int X)
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
		if (X == 1)
		{
			if (ft_put_nbr_hexa_up(nbr, X) <= -1)
				return (-1);
		}
		else if (X == 0)
		{
			if (ft_put_nbr_hexa_low(nbr, X) <= -1)
				return (-1);
		}
	}
	return (ft_len_hexa(nbr));
}
