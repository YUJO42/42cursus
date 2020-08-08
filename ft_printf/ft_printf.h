/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:23:29 by yujo              #+#    #+#             */
/*   Updated: 2020/08/08 17:52:31 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

// # include <stdio.h>

#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define FORMAT "cspdiuxX%"
#define FLAG "-+0#"

typedef struct s_struct
{
	int count;
	int zero_flag;	// 0
	int minus_flag; // -
	int dot_flag;	// .
	int star_flag;	// *

	va_list ap;
} t_struct;

int ft_putchar(char c);
// void ft_handle_flag(**form, t_struct *carry)

#endif
