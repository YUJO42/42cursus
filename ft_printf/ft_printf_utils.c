/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:02:15 by yujo              #+#    #+#             */
/*   Updated: 2020/08/12 16:57:41 by yujo             ###   ########.fr       */
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

int		ft_putstr(char *str)
{
	int			i;
	int			count;

	i = 0;
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
