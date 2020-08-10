/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:23:29 by yujo              #+#    #+#             */
/*   Updated: 2020/08/10 17:03:20 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define FORMAT "cspdiuxX%"
#define FLAG "-+0#"
#define ON 1
#define OFF 0

// "." "0" "-" "*"
// c s p d i u x X %

typedef struct s_struct
{
	va_list		va;
	int			count;
	int			width;  // 전체의 폭
	int			dot;	// . = 자리수 표시
	int			zero;	// 0 = 공백만큼 0채움
	int			minus;  // -
	int			precision;	// * = precision
	char		specifier; // 서싟지정자
}				t_struct;

int ft_putchar(char c);
// void ft_handle_flag(**form, t_struct *carry)

#endif
