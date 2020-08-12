/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:02:15 by yujo              #+#    #+#             */
/*   Updated: 2020/08/12 19:59:15 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_strlen(char *str, t_struct *tag)
{
	int		i;

	if (str == NULL || (tag->specifier == 's' && tag->dot && !tag->precision))
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, t_struct *tag)
{
	int		i;

	if (!str || (tag->specifier == 's' && tag->dot && !tag->precision))
		return ;
	i = 0;
	if (tag->specifier == 's' && tag->precision)
		while (str[i] && i < tag->precision)
			tag->count += ft_putchar(str[i++]);
	else
		while (str[i])
			tag->count += ft_putchar(str[i++]);
}
