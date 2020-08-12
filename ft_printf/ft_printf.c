/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:31:10 by yujo              #+#    #+#             */
/*   Updated: 2020/08/12 20:01:46 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struct(t_struct *tag)
{
	tag->dot = OFF;
	tag->zero = OFF;
	tag->minus = OFF;
	tag->width = OFF;
	tag->precision = OFF;
	tag->data_len = OFF;
	tag->printed_len = OFF;
}

void	parsing_process(char *format, t_struct *tag)
{
	tag->count = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			tag->count += ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
			reset_struct(tag);
			flag_parser(&format, tag);
			width_parser(&format, tag);
			precision_parser(&format, tag);
			specifier_parser(&format, tag);
			specifier_print(tag);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_struct	tag;

	va_start(tag.va, format);
	parsing_process((char *)format, &tag);
	va_end(tag.va);
	return (tag.count);
}
