/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:06:08 by yujo              #+#    #+#             */
/*   Updated: 2020/07/29 01:27:27 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void foo (char *fmt, ...)
{
	va_list ap;
	int d;
	char c;
	char *s;

	va_start(ap, fmt);
	while (*fmt) {
		switch (*fmt++)
		{
		case 's':
			s = va_arg(ap,char  *);
			printf("string %s\n", s);
			break;
		case 'd':
			d = va_arg(ap, int);
			printf("int %d\n", d);
			break;
		case 'c':
			c = (char) va_arg(ap, int);
			printf("char %c\n", c);
			break;
		}
	}
	va_end(ap);
}

int main(void) {
	foo("d s ", 12314313412, "asdasdasd");
}
