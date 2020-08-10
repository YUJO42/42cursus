/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:56:11 by yujo              #+#    #+#             */
/*   Updated: 2020/08/10 22:29:24 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_struct *tag)
{
	char	*str;
	int		c;

	str = 0;
	c = 0;
	if (tag->specifier == 's')
		str = va_arg(tag->va, char *);
	else if (tag->specifier == 'c')
		c = va_arg(tag->va, int);
	else
		c = '%';
	str = (str == NULL) ? "(null)" : str;
}

