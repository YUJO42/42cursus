/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifer_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:20:34 by yujo              #+#    #+#             */
/*   Updated: 2020/08/10 20:29:37 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_struct *tag)
{

}

void	print_number(t_struct *tag)
{

}

void	specifier_print(t_struct *tag)
{
	if (tag->specifier == 's' || tag->specifier == 'c' || tag->specifier == '%')
		print_string(tag);
	if (tag-> specifier == 'd' || tag->specifier == 'i' || tag->specifier == 'u'
	|| tag->specifier == 'x' || tag->specifier == 'X' || tag->specifier == 'p')
		print_number(tag);
}
