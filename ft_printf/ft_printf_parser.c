/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:09:04 by yujo              #+#    #+#             */
/*   Updated: 2020/08/11 14:52:20 by yujo             ###   ########.fr       */
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

void	specifier_parser(char **format, t_struct *tag)
{
	if (**format == 'c' || **format == 's' || **format == 'p' ||
		**format == 'i' || **format == 'u' || **format == 'd' ||
		**format == 'x' || **format == 'X' || **format == '%')
		tag->specifier = **format;
	else
		return ;
	(*format)++;
}


void	specifier_print(t_struct *tag)
{
	if (tag->specifier == 's' || tag->specifier == 'c' || tag->specifier == '%')
		print_word(tag);
	if (tag->specifier == 'd' || tag->specifier == 'i' || tag->specifier == 'u'
	|| tag->specifier == 'x' || tag->specifier == 'X' || tag->specifier == 'p')
		print_number(tag);
}
