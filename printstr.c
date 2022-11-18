/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:18:44 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/18 14:17:04 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printstr(char *str, int *len)
{
	int i;

	i = 0;
	while (str[i])
	{
		printchar(str[i], len);
		i++;
	}
	return (str);
}