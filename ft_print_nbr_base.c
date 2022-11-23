/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:59:26 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/23 13:22:42 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_base(unsigned int nb)
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

static void	ft_put_nbr_base(unsigned int nbr, int X)
{
	if (nbr >= 16)
	{
		ft_put_nbr_base(nbr / 16, X);
		ft_put_nbr_base(nbr % 16, X);
	}
	else if (X == 0)
	{
		if (nbr <= 9)
			ft_print_char(nbr + '0');
		else
			ft_print_char(nbr - 10 + 'a');
	}
	else if (X == 1)
	{
		if (nbr <= 9)
			ft_print_char(nbr + '0');
		else
			ft_print_char(nbr - 10 + 'A');
	}
}

int	ft_print_nbr_base(unsigned int nbr, int X)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_put_nbr_base(nbr, X);
	return (ft_len_base(nbr));
}
