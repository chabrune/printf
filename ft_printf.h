/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:47:51 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/24 15:18:47 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_percent(void);
int	ft_print_str(char *str);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(long long nb);
int	ft_print_u_nbr(unsigned int nbr);
int	ft_print_nbr_hexa(unsigned int nbr, int X);
int	ft_print_addr(unsigned long addr);
int	ft_printf(const char *format, ...);

#endif