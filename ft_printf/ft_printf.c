/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:31:10 by yujo              #+#    #+#             */
/*   Updated: 2020/08/08 17:54:55 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_start(char *format, va_list ap)
{
	t_struct tag;

	tag.count = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			tag.count += ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
		}
	}

	return 1;
}

int		ft_printf(const char **format, ...)
{
	va_list ap;
	int		count;

	va_start(ap, format);
	count = ft_printf_start((char *)format, ap);
	va_end(ap);

	return count;
}

int main(void)
{
	ft_printf("asdasdasd | %d | asdasdasd", 10);
}
