/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printaddr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:15:41 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/18 14:16:52 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printaddr(int nbr, char *base, int *len)
{
	printchar('0', len);
	printchar('x', len);
	printnbrbase(nbr, base, len);
}