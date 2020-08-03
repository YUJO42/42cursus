/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:22:59 by yujo              #+#    #+#             */
/*   Updated: 2020/08/03 20:54:02 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

# define FORMAT "cspdiuxX%"

typedef struct	s_struct
{
	int			count;
}				t_struct;


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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_format_checker(const char **format)
{
	char checker;

	checker = ft_strchr(FORMAT, **format);
	if (checker == 0)
		printf("NULL");
	if (checker == '%')
		ft_putchar('%');
	else if (checker == 'c')
		ft_putchar('c');
	else if (checker == 's')
		printf("%c", checker);
	else if (checker == 'p')
		printf("%c", checker);
	else if (checker == 'd')
		ft_putchar('d');
	else if (checker == 'i')
		printf("%c", checker);
	else if (checker == 'u')
		printf("%c", checker);
	else if (checker == 'x')
		printf("%c", checker);
	else if (checker == 'X')
		printf("%c", checker);
}

int ft_printf(const char *format, ...)
{
	int i;
	int output;
	va_list ap;

	i = 0;

	va_start(ap)
	while (*format)
	{
		if (*format != '%' && *format)
			ft_putchar(*format);
		else if (*format == '%')
		{
			format++;
			ft_format_checker(&format);
		}
		format++;
	}
	va_end()

	return 0;
}

int main(void) {
	ft_printf("asdasdasdasdas  | %d |asdasdasdasda", 1, "asdasdasd";
}
