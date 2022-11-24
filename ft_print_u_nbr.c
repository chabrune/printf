/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:05:04 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/24 14:52:39 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_u_len(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_put_u_nbr(unsigned int nb)
{
	if (nb <= 9)
	{
		if (ft_print_char(nb + 48) <= -1)
			return (-1);
	}
	else
	{
		if (ft_put_u_nbr(nb / 10) == -1)
			return (-1);
		if (ft_put_u_nbr(nb % 10) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_u_nbr(unsigned int nbr)
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
		if (ft_put_u_nbr(nbr) <= -1)
			return (-1);
	}
	return (ft_u_len(nbr));
}
