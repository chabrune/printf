/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:49:18 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/18 14:16:58 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(long nb, int *len)
{
	if (nb > 9)
	{
		printnbr(nb / 10, len);
		printnbr(nb % 10, len);
	}
	else if (nb < 0)
	{
		printchar('-', len);
		nb *= -1;
	}
	else
		printchar(48 + nb, len);
	return (nb);
}