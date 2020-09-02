/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:13:59 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	char			tmp[1];
	long long		div;

	num = (unsigned int)n;
	if (n < 0)
	{
		num = -(unsigned int)n;
		write(fd, "-", 1);
	}
	if (num == 0)
		write(fd, "0", 1);
	else
	{
		div = 1;
		while (num / (div * 10) != 0)
			div *= 10;
		while (num != 0 || div != 0)
		{
			tmp[0] = num / div + '0';
			write(fd, tmp, 1);
			num = num % div;
			div /= 10;
		}
	}
}
