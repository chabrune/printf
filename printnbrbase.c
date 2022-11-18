/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbrbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:59:26 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/18 14:17:01 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	printnbrbase(int nbr, char *base, int *len)
{
	long int nbl;
	int i;

	i = 0;
	nbl = nbr;
	if (nbl < 0)
	{
		printchar('-', len);
		nbl = -nbl;
	}
	if (nbl >= ft_strlen(base))
	{
		printnbrbase(nbl / ft_strlen(base), base, len);
		printnbrbase(nbl % ft_strlen(base), base, len);
	}
	else
		printchar(base[nbl], len);
}