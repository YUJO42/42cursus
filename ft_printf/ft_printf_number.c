/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:55:56 by yujo              #+#    #+#             */
/*   Updated: 2020/08/11 19:33:14 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_nbr_base(long long n, char *base, t_struct *tag)
{
	int		i;

	if (n == 0 && tag->dot && !tag->precision)
		return ;
	i = ft_strlen(base, tag);
	if (n >= i)
		ft_nbr_base((n / i), base, tag);
	tag->count += ft_putchar(base[n % i]);
}

int			ft_nbrlen_base(long long n, char *base, t_struct *tag)
{
	int		i;
	int		j;

	if (n == 0 && tag->dot && !tag->precision)
		return (0);
	j = ft_strlen(base, tag);
	i = 1;
	while (n >= j)
	{
		n /= j;
		i++;
	}
	return (i);
}

void	print_number_space(long long data, t_struct *tag)
{
	int		i;

	i = data < 0 ? 1: 0;
	if (tag->specifier == 'd' && tag->zero) {
		return ;
	}
	if (tag->zero && !tag->dot && !tag->precision)
		i += (tag->width - tag->data_len);
	if (tag->specifier == 'p')
		i += 2;
	if (tag->data_len < tag->precision)
	{
		while (i < (tag->width - tag->precision))
		{
			tag->count += ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (i < (tag->width - tag->data_len))
		{
			tag->count += ft_putchar(' ');
			i++;
		}
	}
}

void	print_number_zero(long long data, t_struct *tag)
{
	int		i;

	if (tag->zero && !tag->dot && !tag->precision)
	{
		i = data < 0 ? 1 : 0;
		while (i < tag->width - tag->data_len)
		{
			tag->count += ft_putchar('0');
			i++;
		}
	}
	else if (tag->data_len < tag->precision)
	{
		i = 0;
		while (i < tag->precision - tag->data_len)
		{
			tag->count += ft_putchar('0');
			i++;
		}
	}
}

void	print_number(t_struct *tag)
{
	char		*base;
	long long	data;

	if (tag->specifier == 'u' || tag->specifier == 'x' || tag->specifier == 'X')
		data = va_arg(tag->va, unsigned int);
	else if (tag->specifier == 'd' || tag->specifier == 'i')
		data = va_arg(tag->va, int);
	else
		data = va_arg(tag->va, unsigned long);
	if (tag->specifier == 'd' || tag->specifier == 'i' || tag->specifier == 'u')
		base = DECIMAL;
	else if (tag->specifier == 'X')
		base = HEX_UPPER;
	else
		base = HEX_LOWER;
	tag->data_len = data < 0 ? ft_nbrlen_base(-data, base, tag)
								: ft_nbrlen_base(data, base, tag);
	tag->minus == 0 ? print_number_space(data, tag) : 0;
	tag->count += (data < 0) ? ft_putchar('-') : 0;
	tag->count += (tag->specifier == 'p') ? ft_putstr("0x") : 0;
	print_number_zero(data, tag);
	data < 0 ? ft_nbr_base(-data, base, tag) : ft_nbr_base(data, base, tag);
	tag->minus == 1 ? print_number_space(data, tag) : 0;
}
