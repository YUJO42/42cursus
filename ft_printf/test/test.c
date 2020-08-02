/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:54:08 by yujo              #+#    #+#             */
/*   Updated: 2020/08/02 14:56:46 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	long long	a = 0x123456abcdef;
	int			b = 0xffffffff;
	float		c = 1234.1234;

	printf("%e\n", c);
	printf("%u\n", b);
	printf("%d\n", b);
	printf("|%#-20.14llx|\n", a);
}
