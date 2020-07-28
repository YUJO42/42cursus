/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cododo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:40:50 by yujo              #+#    #+#             */
/*   Updated: 2020/07/29 01:47:23 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>
 #include <stdarg.h>

 void	printfNumbers(int args, ...)
 {
	 va_list ap;

	 va_start(ap, args);
	 for (int i = 0; i < args; i++)
	 {
		 int num = va_arg(ap, int);
		 printf("%d", num);
	 }
	 va_end(ap);

	 printf("\n");
 }

 int main()
 {
	 printfNumbers(1, 10);
	 printfNumbers(2, 10, 20);
	 printfNumbers(3, 10, 20, 30);
	 printfNumbers(4, 10, 20, 30, 40);

	 return 0;
 }
