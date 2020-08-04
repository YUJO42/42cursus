/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:22:59 by yujo              #+#    #+#             */
/*   Updated: 2020/08/04 08:06:59 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return str[i];
		i++;
	}
	return 0;
}

void	ft_putchar(char c, t_struct *bag)
{
	write(1, &c, 1);
	bag->count++;
}

void	ft_format_checker(const char **format, t_struct bag)
{
	char checker;

	checker = ft_strchr(FORMAT, **format);
	// if (checker == 0)
	// 	printf("NULL");
	// if (checker == '%')
	// 	ft_putchar('%');
	if (checker == 'c')
		ft_putchar('V', &bag);
	// else if (checker == 's')
	// 	printf("%c", checker);
	// else if (checker == 'p')
	// 	printf("%c", checker);
	// else if (checker == 'd')
	// 	ft_putchar('V', bag);
	// else if (checker == 'i')
	// 	printf("%c", checker);
	// else if (checker == 'u')
	// 	printf("%c", checker);
	// else if (checker == 'x')
	// 	printf("%c", checker);
	// else if (checker == 'X')
	// 	printf("%c", checker);
}

int ft_printf_process(const char *format, va_list ap)
{
	bag.count = 0;

	while (*format)
	{
		if (*format != '%' && *format)
			ft_putchar(*format, &bag);
		else if (*format == '%')
		{
			format++;
			ft_format_checker(&format, bag);
		}
		format++;
	}
	return bag.count;
}

int ft_printf(const char *format, ...)
{
	t_struct	bag;
	int		byte;

	va_start(bag.ap, format);
	byte = ft_printf_process((char *)format, bag.ap);
	va_end(bag.ap);
	return byte;
}

int main(void) {
	int a = ft_printf("asdasdasdasdas  | %c |asdasdasdasda", 'O');
	printf("\n");
	printf("%d\n", a);
	printf("asdasdasdasdas  | %c |asdasdasdasda\n", 'O');
}
