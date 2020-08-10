/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:09:04 by yujo              #+#    #+#             */
/*   Updated: 2020/08/10 17:10:58 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_parser(char **format, t_struct *tag)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			tag->minus = ON;
		if (**format == '0')
			tag->zero = ON;
		(*format)++;
	}
	if (tag->minus && tag->zero)
		tag->zero = OFF;
}

void	width_parser(char **format, t_struct *tag)
{
	if (**format == '*')
	{
		tag->width = va_arg(tag->va, int);
		(*format)++;
		if (tag->width < 0)
		{
			tag->zero = OFF;
			tag->minus = ON;
			tag->width = -tag->width;
		}
	}
	while ('0' <= **format && **format <= '9')
	{
		tag->width = (tag->width * 10) + **format - '0';
		(*format)++;
	}
}

void	precision_parser(char **format, t_struct *tag)
{
	if (**format == '*')
	{
		tag->dot = ON;
		(*format)++;
	}
	if (**format == '*')
	{
		tag->precision = va_arg(tag->va, int);
		if (tag->precision < 0)
		{
			tag->precision = OFF;
			tag->dot = OFF;
		}
		(*format)++;
	}
	while ('0' <= **format && **format <= '9')
	{
		tag->width = (tag->precision * 10) + **format - '0';
		(*format)++;
	}
}
