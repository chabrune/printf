/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:18:44 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/24 13:26:54 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) <= 0)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) <= 0)
			return (-1);
		i++;
	}
	return (i);
}
