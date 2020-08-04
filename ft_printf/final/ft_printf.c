/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:42:10 by yujo              #+#    #+#             */
/*   Updated: 2020/08/04 20:14:58 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// flag    - 0 . *
// 서식지정자 c s p d i u x X %

#include "ft_printf.h"

void	ft_reset_carry(t_struct *carry)
{
	carry->zero_flag = 0;
	carry->dot_flag = 0;
	carry->minus_flag = 0;
	carry->star_flag = 0;
}

int		ft_printf_start(char *format, va_list ap)
{
	t_struct carry;

	carry.count = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			ft_putchar(*format);
			carry.count += 1;
			format++;
		}
		if (*format == '%')
		{
			format++;
			ft_reset_carry(&carry);
			// ft_handle_flag(format, ap, &carry);
		}
		format++;
	}
	return carry.count;
}

int		ft_printf(const char *format, ...)
{
	int		byte;
	va_list	ap;

	va_start(ap, format);
	byte = ft_printf_start((char *)format, ap);
	va_end(ap);
	return(byte);
}

int main(void)
{
	ft_printf("asdasdasdasdas | %d | asdasd", 10);
}
