/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:31:10 by yujo              #+#    #+#             */
/*   Updated: 2020/08/09 18:18:30 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struct(t_struct *tag)
{
	tag->dot = ON;
	tag->zero = ON;
	tag->minus = ON;
	tag->star = ON;
	// tag->width = 0;
	// tag->hexa = 0;
	// tag->big_hexa = 0;
}

int		start_process(char *format, t_struct *tag)
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
			reset_struct(&tag);
		}
	}

	 printf("\n%d", tag->count);

	return 1;
}

int		ft_printf(const char *format, ...)
{
	t_struct	tag;
	int			count;

	va_start(tag.va, format);
	count = start_process((char *)format, &tag);
	va_end(tag.va);

	return count;
}

int main(void)
{
	ft_printf("asdasdasd | %d | asdasdasd", 10);
}
