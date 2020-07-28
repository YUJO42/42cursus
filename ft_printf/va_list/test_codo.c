/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_codo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:35:57 by yujo              #+#    #+#             */
/*   Updated: 2020/07/29 01:45:39 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	printNumbers(int args, ...)
{
	printf("%d ", args);
	va_list ap;
	va_start(ap, args);

}

int 	main()
{
	printNumbers(2, 10, 230);
	printNumbers(2, 10, 20);
	printNumbers(3, 10, 20, 30);
	printNumbers(4, 10, 20, 30, 40);
	printNumbers(6, 10, 20, 30, 40, 60);

	return 0;
}

