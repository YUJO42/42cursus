/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:22:59 by yujo              #+#    #+#             */
/*   Updated: 2020/08/02 14:53:13 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_struct counter;
	int		i = 0;
	while (*format)
	{
		ft_putchar_fd(*format++);
		i++;
	}

	return i;
}


int main(void)
{
	int n = ft_printf("asdasd asdasd asdasd", "a");
	printf("%d", n);
}
