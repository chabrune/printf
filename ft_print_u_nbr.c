/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:05:04 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/23 13:32:10 by chabrune         ###   ########.fr       */
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
	if (nb > 9)
	{
		ft_put_u_nbr(nb / 10);
		ft_put_u_nbr(nb % 10);
	}
	else
		ft_print_char(nb + 48);
	return (nb);
}

int	ft_print_u_nbr(unsigned int nbr)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_put_u_nbr(nbr);
	return (ft_u_len(nbr));
}
