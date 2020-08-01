/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:33:54 by yujo              #+#    #+#             */
/*   Updated: 2020/08/01 20:43:38 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 처리해야될 flag "-" "0" "."(정밀도) "*", width
// 처리해야될 서식지정자 c s p d i u x X %


// 0. 서식지정자, 플래그 등이 없는 그냥 printf 구현
// 0-1. ex) printf("asdasdasd") => return 9; 리턴 값은 출력한 글자의 갯수가 되야 함.
// 0-2. 파싱, %를 만났을 때 어떻게 받아들일 것인가.

// 1. c 구현
// 1-1 . 정밀도(프리시전), 넓이, flag들 구현

// 2. s 구현
// 3. d 구현
// 4. xX구현

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_printf(const char *format, ...)
{
	int i;
	i = 0;
	while (*format)
	{
		ft_putchar_fd(*format++, 1);
		i++;
	}
	printf("\n");

	printf("%d", i);
	return 0;
}

int main(void) {
	 ft_printf("asdasdasdasdas              dasda", "a");

}
