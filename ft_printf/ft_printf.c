/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:31:10 by yujo              #+#    #+#             */
/*   Updated: 2020/08/10 20:22:09 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struct(t_struct *tag)
{
	tag->dot = OFF;
	tag->zero = OFF;
	tag->minus = OFF;
	tag->precision = OFF;
	tag->width = 0;
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

	// @@@ TEST PARSER @@@

	// printf("\n| dot       %d      |", tag->dot);
	// printf("\n| zero      %d      |", tag->zero);
	// printf("\n| minus     %d      |", tag->minus);
	// printf("\n| precision %d      |", tag->dot);
	// printf("\n| width     %d      |", tag->width);
}

int		ft_printf(const char *format, ...)
{
	t_struct	tag;
	int			count;

	va_start(tag.va, format);
	parsing_process((char *)format, &tag);
	va_end(tag.va);

	return tag.count;
}

int main(void)
{
	ft_printf("asdasdasd | %0*.0d | asdasdasd", 10);
	// printf("asdasdasd%15.10dqweqwe", 1123456789);
}
